#ifndef __NODE_H
#define __NODE_H

#include <iostream>
#include <string.h>
#include "Square.h"
using namespace std;

#pragma warning(disable: 4996)

class Node
{
public:	
	Square data;
	Node* next; // points to the next node in the list

	Node();
	Node(Square item, Node* ptr = NULL);
	~Node();
	void InsertAfter(Node* newnode); // Insert newnode after current node
	Node* DeleteAfter(); // Delete node after current node
};

#endif // !__NODE_H
