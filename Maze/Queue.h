#ifndef __QUEUE_H
#define __QUEUE_H

#include <iostream>
#include <string.h>
using namespace std;

#include "Square.h"

#pragma warning(disable: 4996)

const int MAX_SIZE = 80 * 25;

class Queue
{
public:
	Queue(int size = MAX_SIZE);
	~Queue();

	void AllocationTest(void * ptr);
	void MakeEmpty();
	char IsEmpty();
	Square Front();
	void EnQueue(Square item);
	void EnQueue(int row,int col);
	Square DeQueue();

private:
	int m_head, m_tail, m_size;
	Square* m_square;
	int AddOne(int x); 
};

#endif // !__QUEUE_H
