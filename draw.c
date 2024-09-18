#ifndef _DRAW_C_
#define _DRAW_C_
#include "entity.c"
#include "init.c"

#define SLOT_BOX 2
#define TILE_BOX 3
#define TILE_PLAYER 4

void drawText(char text[], Uint8 x, Uint8 y)
{
    int len = 0;
    while (text[len] != '\0')
        len++;
    set_bkg_tiles(x, y, len, 1, text);
    // set_win_tiles(x, y, len , 1, text);
}

void drawBackground(Tile *map, Stack *box, int bkg)
{
    if (bkg)
    {
        Uint8 mapPaletteBKG[360];
        build_paletteBKG(map, mapPaletteBKG, spriteCGB);
        set_bkg_tiles(0, 0, map->width, map->height, map->map);
        set_bkg_attributes(0, 0, map->width, map->height, mapPaletteBKG);
    }

    Node *pivot = box->first;
    int slot = SLOT_BOX;
    while (pivot != NULL)
    {
        set_sprite_tile(slot, TILE_BOX);
        set_sprite_prop(slot, spriteCGB[BOX]);
        move_sprite(slot, (pivot->value->x + 1) * 8, (pivot->value->y + 2) * 8);
        pivot = pivot->next;
        slot++;
    }
}

void drawPlayer(Player *player)
{
    int sprite = TILE_PLAYER + (player->vector < 0 ? 0 : player->vector);
    set_sprite_prop(0, spriteCGB[PLAYER]);
    set_sprite_tile(0, sprite);
    int x = player->position->x * 8 + 8;
    int y = player->position->y * 8 + 16;
    move_sprite(0, x, y);
}

void draw(Game *this)
{
    static int lastLevel = -1;
    if (this->level == lastLevel)
    {
        if (this->level == 1)
        {
            drawText("JUEGO", 1, 14);
            drawText("CREDITO", 12, 14);
        }
        else if (this->level == 0)
        {
            drawText("CREDITO", 6, 1);
            drawText("HECHO POR OTO", 4, 3);
            drawText("[A] PARA COGER", 1, 10);
            drawText("[B] PARA SOLTAR", 1, 11);
        }
    }
    drawBackground(this->map, this->box, this->level != lastLevel);
    lastLevel = this->level;
    drawPlayer(this->player);
}
#endif