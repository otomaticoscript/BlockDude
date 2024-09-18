#ifndef _STACK_C_
#define _STACK_C_
#include "Stack.h"
// Stack Method
void stack(Stack *this)
{
	this->first = NULL;
}
int stackIsEmpty(Stack *this)
{
	return isEmpty(this->first);
}

TElement stackLookaHead(Stack *this)
{
	return look(this->first);
}

void stackPush(Stack *this, TElement value)
{
	Node *newbie = createNode(value);
	newbie->next = this->first;
	this->first = newbie;
}

TElement stackPop(Stack *this)
{
	TElement value = NULL;
	if (!isEmpty(this->first))
	{
		value = stackLookaHead(this);
		Node *erase = this->first;
		this->first = this->first->next;
		free(erase);
	}
	return value;
}
Node *stackFind(Stack *this, Point2D *position)
{
	Node *pointer = this->first;
	while (!isEmpty(pointer))
	{
		if (pointer->value->x == position->x && pointer->value->y == position->y)
		{
			return pointer;
		}
		pointer = pointer->next;
	}
	return NULL;
}
void freeNode(Node *self)
{
	if (!isEmpty(self))
	{
		free(self->value);
		freeNode(self->next);
		free(self);
	}
}
void destroyStack(Stack *this)
{

	freeNode(this->first);
	this->first = NULL;
}
#endif