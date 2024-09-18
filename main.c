
#include <gbdk/platform.h>
// #include <gb/gb.h>
// #include <gb/cgb.h>

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "draw.c"
#include "init.c"
#include "update.c"
/*
void performantdelay(Uint8 numloops){
    Uint8 i;
    for(i = 0; i < numloops; i++){
        wait_vbl_done();
    }
}
*/
#define _FPS_ 5
void init(Game *this);
void draw(Game *this);
int update(Game *this);

void main(void)
{
    Game game;

    int canDraw = 1;
    init(&game);

    while (game.state != EXIT)
    {
        if (canDraw != 0)
        {
            draw(&game);
            canDraw = 0;
        }
        canDraw = update(&game);
        // performantdelay(6);
        //delay(1000 / _FPS_);
        vsync();
    }
}
