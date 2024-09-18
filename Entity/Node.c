#ifndef _NODE_C_
#define _NODE_C_
#include "Node.h"
// Node Method
int isEmpty(Node *this)
{
	return this == NULL;
}

TElement look(Node *this)
{
	return this->value;
}


int any(Node *this, TElement point)
{
	int exist = 0;
	TElement head;
	Node *pointer = this;
	while (pointer != NULL && !exist)
	{
		head = pointer->value;
		exist = (head->x == point->x && head->y == point->y);
		pointer = pointer->next;
	}
	return exist;
}


Node *createNode(TElement value)
{
	Node *newbie = newElement(Node);
	newbie->value = value;
	newbie->next = NULL;
	return newbie;
}
void destroyNode(Node *this)
{
	if (!isEmpty(this))
	{
		//free(this->value);
		free(this);
	}
}
#endif