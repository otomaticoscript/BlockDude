#include "entity.c"
#include "init.c"

int getElement(Tile *tile, Stack *box, Point2D *point);
static int gravity(Player *player, Tile *board, Stack *boxes);
static int takeToHand(Player *player, Stack *boxes, Point2D *position);
static int changePosition(Player *player, Tile *board, Stack *boxes, Point2D *position);
int movePlayer(Player *this, Tile *board, Stack *boxes, Uint8 key);
int updateElements(Game *this);

int update(Game *this)
{
    switch (this->state)
    {
    case OPEN:
        this->level = 1;
        changeLevel(this, this->level);
        this->state = GAME;
        return 1;
    case OVER:
        if (joypad())
        {
            this->state = EXIT;
            return 1;
        }
        return 0;
    default:
    case GAME:
        if (this->state == GAME)
        {
            int canDraw = 1;
            canDraw = updateElements(this);
            Uint8 key = joypad();
            if (key)
            {
                canDraw = movePlayer(this->player, this->map, this->box, key) || canDraw;
                waitpadup();
            }
            return gravity(this->player, this->map, this->box) || canDraw;
        }
    }
    return 0;
}

int updateElements(Game *this)
{
    int element = getElement(this->map, this->box, this->player->position);
    if (element == DOOR || element == PREV)
    {
        this->level += element == DOOR ? 1 : -1;
        if (this->level == MAX_TILE)
        {
            this->state = OVER;
        }
        else
        {
            changeLevel(this, this->level);
        }
        return 1;
    }
    return 0;
}
int getElementOfMap(Tile *map, Uint8 x, Uint8 y)
{
    int index = map->width * y + x;
    return map->map[index];
}

int getElementOfStack(Stack *box, Uint8 x, Uint8 y)
{
    Node *pointer = box->first;
    while (pointer != NULL)
    {
        if (pointer->value->x == x && pointer->value->y == y)
        {
            return BOX;
        }
        pointer = pointer->next;
    }
    return EMPTY;
}

int getElement(Tile *tile, Stack *box, Point2D *point)
{
    Uint8 el = getElementOfMap(tile, point->x, point->y);
    if (el == EMPTY)
    {
        el = getElementOfStack(box, point->x, point->y);
    }
    return el;
}

int movePlayer(Player *this, Tile *board, Stack *boxes, Uint8 key)
{
    int canDraw = 0;

    Point2D position; // newElement(Point2D);
    position.x = this->position->x;
    position.y = this->position->y;
    if (key & J_LEFT)
    {
        position.x--;
        this->vector = -1;
    }
    if (key & J_RIGHT)
    {
        position.x++;
        this->vector = 1;
    }
    if (key & J_DOWN)
    {
        position.y++;
    }

    if ((key & J_UP) || (key & J_A) || (key & J_B))
    {
        position.x += this->vector;
        int element = getElement(board, boxes, &position);
        if (element == BOX && isEmpty(this->box) && ((key & J_A) || (key & J_UP)))
        {
            canDraw = takeToHand(this, boxes, &position);
        }
        else
        {
            if (element == EMPTY && !isEmpty(this->box) && ((key & J_B) || (key & J_UP)))
            {
                this->box->value->x = position.x;
                this->box->value->y = position.y;
                this->box = NULL;
                canDraw = 1;
            }
        }
    }
    else
    {
        canDraw = changePosition(this, board, boxes, &position);
    }
    // free(position);
    return canDraw;
}

static int changePosition(Player *player, Tile *board, Stack *boxes, Point2D *position)
{

    int can = 0, element = getElement(board, boxes, position);
    if (element == BLOCK || element == BOX)
    {
        position->y--;
        element = getElement(board, boxes, position);
    }
    if (element == DOOR || element == EMPTY || element == PREV)
    {
        player->position->x = position->x;
        player->position->y = position->y;
        can = 1;
    }
    if (!isEmpty(player->box))
    {
        player->box->value->x = player->position->x;
        player->box->value->y = player->position->y - 1;
        can = 1;
    }
    return can;
}

static int takeToHand(Player *player, Stack *boxes, Point2D *position)
{
    if (isEmpty(player->box))
    {
        Node *pointer = stackFind(boxes, position);
        if (!isEmpty(pointer))
        {
            player->box = pointer;
            player->box->value->x = player->position->x;
            player->box->value->y = player->position->y - 1;
            return 1;
        }
    }
    return 0;
}

static int gravity(Player *player, Tile *board, Stack *boxes)
{
    Point2D *position = newElement(Point2D);
    position->y = player->position->y + 1;
    position->x = player->position->x;
    int can = changePosition(player, board, boxes, position);
    free(position);
    return can;
}