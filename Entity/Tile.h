#ifndef _TILE_H_
#define _TILE_H_

/*
|ID	|Descripcion|
|---|-----------|
|0  |vazio      |
|1  |bloque     |
|2|6|puerta     |
|3  |caja       |
|4|5|jugador    |
|7  |plataform  |
*/

#define EMPTY     0 
#define BLOCK     1 
#define DOOR      2 
#define BOX       3 
#define PLAYER    4  
#define NPC       5  
#define PREV      6  
#define PLATAFORM 7  
#define LEFT      8  
#define RIGHT     9  

typedef struct _mapLevel
{
    int width;
    int height;
    Uint8 *map;
}  Tile;
#include "Tile.c"
#endif