#ifndef _TILE_C_
#define _TILE_C_
#include "../etc/end.c"
#include "../etc/open.c"
#include "../etc/credit.c"
#include "../etc/map0.c"
#include "../etc/map1.c"
#include "../etc/map2.c"
#include "../etc/map3.c"
#include "../etc/map4.c"
#include "../etc/map5.c"
#include "../etc/map6.c"
#include "../etc/map7.c"
#include "../etc/Sprite.h"
//Alfabeto
#include "../etc/bkg.c"

#define MAX_TILE 11
Tile End = {endWidth, endHeight, end};
Tile Open = {openWidth, openHeight, open};
Tile Credit = {creditWidth, creditHeight, credit};
Tile Map_0 = {map00Width, map00Height, map00};
Tile Map_1 = {map01Width, map01Height, map01};
Tile Map_2 = {map03Width, map03Height, map03};
Tile Map_3 = {map04Width, map04Height, map04};
Tile Map_4 = {map05Width, map05Height, map05};
Tile Map_5 = {map06Width, map06Height, map06};
Tile Map_6 = {map02Width, map02Height, map02};
Tile Map_7 = {map07Width, map07Height, map07};
Tile *MasterTile[MAX_TILE] = {&Credit, &Open, &Map_0, &Map_1, &Map_2, &Map_3, &Map_4, &Map_5, &Map_6, &Map_7, &End};

#endif