#include "Queue.h"

Queue::Queue(int size) // Constructor
{
	m_head = 1;
	m_tail = 0;
	m_square = new Square[size];
	AllocationTest(m_square);
	m_size = size;
}

Queue::~Queue() // Destructor
{
    delete[] m_square;
}

void Queue::AllocationTest(void * ptr)
{
	if (!ptr)
	{
		cout << "Allocation error!!\n";
		exit(1);
	}
}

void Queue::MakeEmpty() // Makes the Queue empty
{
	m_head = 1;
	m_tail = 0;
}

char Queue::IsEmpty()  // IsEmpty: return 1 if Queue is empty, 0 otherwise
{
	return (AddOne(m_tail) == m_head);
}

Square Queue::Front()
{
	if (IsEmpty())
	{
		cout << "Error: QUEUE EMPTY\n";
		exit(1);
	}
	return (m_square[m_head]);
}

void Queue::EnQueue(Square item)
{
	if (AddOne(AddOne(m_tail)) == m_head)
	{
		cout << "Error: QUEUE FULL\n";
		exit(1);
	}
	m_tail = AddOne(m_tail);
	m_square[m_head] = item;
}

void Queue::EnQueue(int row, int col)
{
	if (AddOne(AddOne(m_tail)) == m_head)
	{
		cout << "Error: QUEUE FULL\n";
		exit(1);
	}
	m_tail = AddOne(m_tail);
	m_square[m_tail].SetRow(row);
	m_square[m_tail].SetCol(col);
}

Square Queue::DeQueue() //returns the next square in queue
{
	if (IsEmpty())
	{
		cout << " Error: QUEUE EMPTY\n";
		exit(1);
	}
	Square temp = m_square[m_head];
	m_head = AddOne(m_head);
	return temp;
}

int Queue::AddOne(int x)
{
	return ((1 + x) % this->m_size);
}
