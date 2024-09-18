#ifndef _NODE_H_
#define _NODE_H_

#define newElement(_type) (_type *)malloc(sizeof(_type))

// TElement es un puntero a un tipo de dato que se define fuera de este fichero
typedef struct _link Node;
struct _link
{
	TElement value;
	Node *next;
};
// Node Method
int isEmpty(Node *this);
TElement look(Node *this);
int any(Node *this, TElement point);
Node *createNode(TElement value);
void destroyNode(Node *this);
#include "Node.c"
#endif