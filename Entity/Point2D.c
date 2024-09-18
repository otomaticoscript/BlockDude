#ifndef _POINT2D_C_
#define _POINT2D_C_
#include "Point2D.h"

void dumpPoint(Point2D * A){
    printf("{x:0x%.2x,y:0x%.2x}\n", A->x, A->y);
} 
#endif