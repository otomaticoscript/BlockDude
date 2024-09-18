#ifndef _TDA_H
#define _TDA_H

#include "Point2D.h"
#include <stdlib.h>
typedef Point2D *TElement;
#include "Node.h"
#include "Stack.h"
//#define newElement(_type) (_type *)malloc(sizeof(_type))
#define newArray(_type, _size) (_type *)calloc((_size), sizeof(_type))

#endif
