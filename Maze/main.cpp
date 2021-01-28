#include "Maze.h"

int main()
{
	int rows, cols, choice;
	cout << "Maze: 1) From input 2) Random\n";
	cin >> choice;
	cin >> rows >> cols;
	Maze maze(rows, cols);
	if (choice == 1) //recieve maze from user input
	{   
		char* tempLine = new char[cols + 1];
		maze.AllocationTest(tempLine);  //memory allocation check
		cin.ignore();
		for (int i = 0; i < rows; i++)
		{
			cin.getline(tempLine, cols + 1);
			maze.setLine(tempLine, i);
		}
		if (maze.CheckIfMazeValid() == false)
		{
			cout << "invalid input\n";
			exit(1);
		}
		delete[] tempLine;
	}
	else    //program build maze by definition
	{
		maze.CreateInitialMaze();
		maze.CreateRandMaze();
	}
	if (maze.SolveMaze() == true)
		maze.PrintMaze();   //print solved maze
	else
		cout << "no solution\n";
	return 0;
}