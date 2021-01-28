#include "Maze.h"
#include "Queue.h"
#include "Square.h"
#include "Stack.h"

Maze::Maze(int row, int col) //Maze constructor
{
	setCol(col);
	setRow(row);
	m_maze = new char*[row + 1];
	AllocationTest(m_maze);
	for (int i = 0; i < row; i++)
	{
		m_maze[i] = new char[col + 1];
		AllocationTest(m_maze[i]);
	}
}

Maze::~Maze()   //Maze destructor
{
	for (int i = 0; i < m_row; i++)
		delete[] m_maze[i];
	delete[] m_maze;
}

void Maze::AllocationTest(void * ptr) 
{
	if (!ptr)
	{
		cout << "Allocation error!!\n";
		exit(1);
	}
}

void Maze::setRow(int row)
{
	m_row = row;
}

void Maze::setCol(int col)
{
	m_col = col;
}

int Maze::getRow() const
{
	return m_row;
}

int Maze::getCol() const
{
	return m_col;
}

bool Maze::SolveMaze()  //function solving the given maze and returns true if maze is solved
{
	Square current ,end;
	end.SetRow(m_row - 2);
	end.SetCol(m_col - 1);
	current.SetRow(1);
	current.SetCol(0);
	Queue q(m_col*m_row);
	q.EnQueue(current);
	while (!q.IsEmpty())    //while there is moves available
	{
		current = q.DeQueue();
		m_maze[current.getRow()][current.getCol()] = '$';
		if (current == end)
		{
			return true;    //maze is solved
		}
		else
		{
			if (m_maze[current.getRow()][current.getCol() + 1] == ' ') // right
				q.EnQueue(current.getRow(), current.getCol() + 1);
			if (m_maze[current.getRow() + 1][current.getCol()] == ' ') // down
				q.EnQueue(current.getRow() + 1,current.getCol());
			if (m_maze[current.getRow()][current.getCol() - 1] == ' ') // left
				q.EnQueue(current.getRow(),current.getCol() - 1);
			if (m_maze[current.getRow() - 1][current.getCol()] == ' ') // up
				q.EnQueue(current.getRow() - 1,current.getCol());
		}
	}
	//no more moves available, maze can't be solved
	return false; 
}

bool Maze::CheckIfRowValid(char * row_to_check, int col)
{
	if (strlen(row_to_check) == col + 1) // check if the length is valid
		return false;
	for (int i = 0; i < col; i++) // check the values of the string
		if (row_to_check[i] != ' ' && row_to_check[i] != '*')
			return false;
	return true;
}

bool Maze::CheckIfMazeValid()
{
	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			if (i == 0 || i == m_row -1)
				if (m_maze[i][j] != '*') // first row && last row
					return false;
			if (j == 0 || j == m_col - 1) // walls
				if ((i != 1 && i != m_row - 2) && m_maze[i][j] != '*') // not include entrance and exit
					return false; 
			if (i == 1 && j == 0 && m_maze[i][j] != ' ') // entrance
				return false;
			if (i == m_row - 2 && j == m_col - 1 && m_maze[i][j] != ' ') // exit
				return false;
		}
	}
	return true;
}

void Maze::setLine(char * row, int index)
{
	if (CheckIfRowValid(row, m_col))
	{
		m_maze[index] = new char[m_col+1];
		AllocationTest(m_maze[index]); //memory allocation check
		strcpy(m_maze[index], row); //copy new valid row to maze
	}
	else
	{
		cout << "invalid input\n";
		exit(1);
	}
}

void Maze::CreateInitialMaze()  //function creates maze format by definiton from given row and col
{
	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
			if (i % 2 == 0 || j % 2 == 0)
				m_maze[i][j] = '*';
			else
				m_maze[i][j] = ' ';
		m_maze[i][m_col] = '\0';
	}
	m_maze[1][0] = ' ';
	m_maze[m_row - 2][m_col - 1] = ' ';
}

bool Maze::HasNeighbors(Square sqr) //checks if given square has valid neighbors
{
	int row = sqr.getRow(), col = sqr.getCol();
	if ( col + 2 < m_col - 1 && m_maze[row][col + 2] == ' ') // right neighbor
		return true;
	if (row + 2 < m_row - 1 && m_maze[row + 2][col] == ' ') // down neighbor
		return true;
	if (col - 2 > 0 && m_maze[row][col - 2] == ' ') // left neighbor
		return true;
	if (row -2 > 0 && m_maze[row - 2][col] == ' ') // up neighbor
		return true;
	return false;
}

void Maze::CreateRandMaze() //create a valid maze randomally by definition
{
	Stack s;
	Square current, temp;
	int row, col;
	bool flag = true;
	srand((unsigned)time(NULL));
	current.SetCol(1);
	current.SetRow(1);
	s.Push(current);
	while (!s.IsEmpty())
	{
		current = s.Pop(); // remove temporarily from stack
		row = current.getRow();
		col = current.getCol();
		m_maze[row][col] = '+';
		if (HasNeighbors(current) == true)
		{
			while (flag == true)
				switch (rand() % 4)
				{
				case 0: // right
				{
					if (col + 2 < m_col - 1 && m_maze[row][col + 2] == ' ') // right neighbor
					{
						m_maze[row][col + 1] = ' '; // remove wall
						temp.SetCol(col + 2);
						temp.SetRow(row);
						s.Push(current); // return to stack
						s.Push(temp); // push new path move
						flag = false;
					}
					break;
				}
				case 1: // down
				{
					if (row + 2 < m_row - 1 && m_maze[row + 2][col] == ' ') // down neighbor
					{
						m_maze[row + 1][col] = ' '; // remove wall
						temp.SetCol(col);
						temp.SetRow(row + 2);
						s.Push(current); // return to stack
						s.Push(temp); // push new path move
						flag = false;
					}
					break;
				}
				case 2: // left
				{
					if (col - 2 > 0 && m_maze[row][col - 2] == ' ') // left neighbor
					{
						m_maze[row][col - 1] = ' '; // remove wall
						temp.SetCol(col - 2);
						temp.SetRow(row);
						s.Push(current); // return to stack
						s.Push(temp); // push new path move
						flag = false;
					}
					break;
				}
				case 3: // up
				{
					if (row - 2 > 0 && m_maze[row - 2][col] == ' ') // up neighbor
					{
						m_maze[row - 1][col] = ' '; // remove wall
						temp.SetCol(col);
						temp.SetRow(row - 2);
						s.Push(current); // return to stack
						s.Push(temp); // push new path move
						flag = false;
					}
					break;
				}
				default:
					break;
				}
			flag = true;
		}
	}
	CleanRandMaze();
}

void Maze::CleanRandMaze()
{
	for (int i = 0; i < m_row; i++)
		for (int j = 0; j < m_col; j++)
			if (m_maze[i][j] == '+')
				m_maze[i][j] = ' ';
}

void Maze::PrintMaze()  //print maze
{
	for (int i = 0; i < m_row; i++)
	{
		cout << m_maze[i] << " ";
		cout << "\n";
	}
	cout << "\n";
}