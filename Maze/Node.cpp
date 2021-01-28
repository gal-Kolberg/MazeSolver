#include "Node.h"

Node::Node() // Constructor
{
	next = NULL;
}

Node::Node(Square item, Node * ptr) // Constructor
{
	data = item;
	next = ptr;
}

Node::~Node() // Destructor
{
}

void Node::InsertAfter(Node * newnode)
{
	newnode->next = next;
	next = newnode;
}

Node * Node::DeleteAfter()
{
	Node* temp = next;
	if (next == NULL)
		return NULL;
	next = temp->next;
	return temp;
}
