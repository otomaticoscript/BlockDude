#ifndef _STACK_H
#define _STACK_H
#include "Node.h"
typedef struct _stack
{
	Node *first;
} Stack;

// Stack Method
void stack(Stack *this);
int stackIsEmpty(Stack *this);
TElement stackLookaHead(Stack *this);
void stackPush(Stack *this, TElement value);
TElement stackPop(Stack *this);
Node *stackFind(Stack *this, Point2D *position);
void destroyStack(Stack *this);
#include "Stack.c"
#endif