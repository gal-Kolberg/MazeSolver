#ifndef __MAZE_H
#define __MAZE_H

#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

#include "Square.h"

#pragma warning(disable: 4996)

class Maze
{
public:
	Maze(int row,int col);
	~Maze();

	void AllocationTest(void * ptr);
	void setRow(int row);
	void setCol(int col);

	int getRow() const;
	int getCol() const;

	bool SolveMaze();
	bool CheckIfRowValid(char* row_to_check, int col);
	bool CheckIfMazeValid();
	void setLine(char* row, int index);
	void CreateInitialMaze();
	bool HasNeighbors(Square sqr);
	void CreateRandMaze();
	void CleanRandMaze();
	void PrintMaze();
private:

	int m_row, m_col;
	char** m_maze;
};

#endif // !__MAZE_H

