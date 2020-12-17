#include "Maze.h"
#include <iostream>
#include <cassert>

int main()
{
	int n = 5;
	int m = 5;
	Maze* maze = new Maze(n, m);
	for (int i = 0; i < n - 1; i++)
	{
		assert(maze->makeConnection(i, i, i, i + 1));
		assert(maze->makeConnection(i, i + 1, i + 1, i + 1));
	}
	maze->printMaze();
}
