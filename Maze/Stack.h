#ifndef __STACK_H
#define __STACK_H

#include "Node.h"

class Stack
{
public:
	Stack();
	~Stack();

	void AllocationTest(void * ptr);
	void MakeEmpty();
	int IsEmpty();
	void Push(Square item);
	Square Pop();
	Square Top();
private:
	Node* top; //Points to top of stack
};

#endif // !__STACK_H
