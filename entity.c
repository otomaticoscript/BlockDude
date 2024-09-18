#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Entity/EnumGameState.h"
#include "Entity/Point2D.h"
typedef unsigned char Uint8;
typedef unsigned int Uint16;

#include "Entity/Collection.h"
#include "Entity/Player.h"
#include "Entity/Tile.h"

struct blockDude
{
    EnumGameState state;
    Player *player;
    Tile *map;
    Stack *box;
    int level;
};

typedef struct blockDude Game;
#endif