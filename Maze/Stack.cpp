#include "Stack.h"

Stack::Stack() // Constructor
{
	top = NULL;
}

Stack::~Stack() // Destructor
{
	MakeEmpty();
}

void Stack::AllocationTest(void * ptr)
{
	if (!ptr)
	{
		cout << "Allocation error!!\n";
		exit(1);
	}
}

void Stack::MakeEmpty()  // Makes the Stack empty 
{
	Node* temp;
	while (top != NULL)
	{
		temp = top;
		top = top->next;
		delete temp;
	}
}

int Stack::IsEmpty() // IsEmpty: return NULL if the Stack is empty 
{
	return (top == NULL);
}

void Stack::Push(Square item) //inserts a new sqaure at the top of the stack
{
	top = new Node(item, top);
	AllocationTest(top);
}

Square Stack::Pop() //removes the square on top of the stack and reducing its size by one
{
	if (IsEmpty())
	{
		cout << "Error: STACK UNDERFLOW\n";
		exit(1);
	}
	Node* temp = top;
	Square item = top->data;
	top = top->next;
	delete temp;
	return item;
}

Square Stack::Top()
{
	Square x = Pop();
	Push(x);
	return x;
}
