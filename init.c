#ifndef _INIT_C_
#define _INIT_C_
#include "entity.c"
#include <gbdk/font.h>

void resetBox(Stack *this)
{
    int slot = 8;
    Node *pointer = this->first;//, *erase;
    while (!isEmpty(pointer))
    {
        //erase = pointer;
        //pointer = pointer->next;
        //free(erase->value);
        //free(erase);
        pointer->value->x = -1;
        pointer->value->y = -1;
        //hide_sprite(slot++);
        //slot++;
        pointer = pointer->next;
    }
    // this->first = NULL;
}

void build_paletteBKG(Tile *map, char *paletteBackground, Uint8 *paletteSprite)
{
    Uint8 palette, element;
    for (int index = 0; index < 360; index++)
    {
        element = map->map[index];
        palette = paletteSprite[element < 32 ? element : 0];
        paletteBackground[index] = palette;
    }
}

void parseElementsOfTile(Game *this, Tile *other)
{
    int col, row, element;
    int index = 0, pivot = 0;
    int startH = 18 - other->height;
    int startW = 20 - other->width;
    Node *pointer = this->box->first;
    for (row = 0; row < other->height; row++)
    {
        index = row * other->width;
        pivot = (startH + row) * 20 + startW;
        for (col = 0; col < other->width; col++)
        {
            element = other->map[index + col];
            if (element == BOX || element == PLAYER)
            {
                if (element == BOX)
                {
                    if (!isEmpty(pointer))
                    {
                        pointer->value->x = col + startW;
                        pointer->value->y = row + startH;
                        pointer = pointer->next;
                    }
                    else
                    {
                        Point2D *point = newElement(Point2D);
                        point->x = col + startW;
                        point->y = row + startH;
                        stackPush(this->box, point);
                    }
                }
                else
                {
                    this->player->position->x = col + startW;
                    this->player->position->y = row + startH;
                    this->player->vector = -1;
                    this->player->box = NULL;
                }
                element = EMPTY;
            }
            this->map->map[pivot + col] = element;
        }
    }
}

void changeLevel(Game *this, int level)
{
    this->level = level;
    if (this->player == NULL)
    {
        this->player = newElement(Player);
        this->player->position = newElement(Point2D);
        this->player->box = NULL;
    }
    if (this->box == NULL)
    {
        this->box = newElement(Stack);
        this->box->first = NULL;
    }
    else
    {
        resetBox(this->box);
    }
    if (this->map == NULL)
    {
        this->map = newElement(Tile);
        this->map->width = 20;
        this->map->height = 18;
        this->map->map = newArray(Uint8, 360);
    }
    memset(this->map->map, 1, 360);
    Tile *current = MasterTile[this->level];
    parseElementsOfTile(this, current);
}

void init(Game *this)
{
    // Inicializado Variables
    this->level = 0;
    this->state = OPEN;
    this->player = NULL;
    this->box = NULL;
    this->map = NULL;
    SPRITES_8x8;
    //  Inicializado Graficos
    set_sprite_data(0, 19, sprite);
    set_sprite_tile(0, PLAYER);
    set_sprite_palette(0, 5, &spritePalette[0]);
    SHOW_SPRITES;
    // Carga Background tiles and then map
    set_bkg_data(0, 95, bkg);
    set_bkg_data(0, 8, sprite);
    set_bkg_palette(0, 5, &spritePalette[0]);

    changeLevel(this, this->level);
    SHOW_BKG;

    // set_win_data(0,0x66,font_min);
    // SHOW_WIN;

    DISPLAY_ON;
}
#endif