#include "MTreeNode.h"
#include "Maze.h"
#include <iostream>
#include <cassert>

int main()
{
	const int n = 5;
	const int m = 5;
	MTreeNode* root = MTreeNode::beginTree(0, 0);
	MTreeNode* rootCopy1 = root;
	MTreeNode* rootCopy2 = root;

	//построение древа
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			assert(rootCopy1->addChild(j, i));
			rootCopy1 = rootCopy1->hasChild(j, i);
		}
		rootCopy1 = rootCopy2;
		if (i != n - 1)
		{
			assert(rootCopy1->addChild(i, i + 1));
			rootCopy1 = rootCopy1->hasChild(i, i + 1);
			assert(rootCopy1->addChild(i + 1, i + 1));
			rootCopy2 = rootCopy1->hasChild(i + 1, i + 1);
		}
		for (int j = i + 2; j < m; j++)
		{
			assert(rootCopy1->addChild(i, j));
			rootCopy1 = rootCopy1->hasChild(i, j);
		}
		rootCopy1 = rootCopy2;
	}

	//построение связей
	Maze* maze = new Maze(n, m);
	rootCopy1 = root;
	for (int i = 0; i < n; i++)
	{
		int j = rootCopy1->j();
		rootCopy2 = rootCopy1;
		int k = i + 1;
		MTreeNode* child = rootCopy2->hasChild(k, j);
		while (child != nullptr)
		{
			assert(maze->makeConnection(k - 1, j, k, j));
			rootCopy2 = child;
			child = rootCopy2->hasChild(++k, j);
		}
		k = i + 1;
		rootCopy2 = rootCopy1;
		child = rootCopy2->hasChild(i, k);
		if (i < n - 1)
		{
			rootCopy1 = child->hasChild(i + 1, i + 1);
			assert(maze->makeConnection(i, k, k, k));
		}
		while (child != nullptr)
		{
			assert(maze->makeConnection(j, k - 1, j, k));
			rootCopy2 = child;
			child = rootCopy2->hasChild(i, ++k);
		}
	}
	maze->printMaze();

	//вычисление дистанции
	int** distances = new int* [n];
	for (int i = 0; i < m; i++)
		distances[i] = new int[m];
	distances[0][0] = 0;
	rootCopy1 = root;
	rootCopy2 = rootCopy1;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			rootCopy1 = rootCopy1->hasChild(j, i);
			distances[j][i] = rootCopy1->distance();
		}
		rootCopy1 = rootCopy2;
		if (i != n - 1)
		{
			rootCopy1 = rootCopy1->hasChild(i, i + 1);
			distances[i][i + 1] = rootCopy1->distance();
			rootCopy2 = rootCopy1->hasChild(i + 1, i + 1);
			distances[i + 1][i + 1] = rootCopy2->distance();
		}
		for (int j = i + 2; j < m; j++)
		{
			rootCopy1 = rootCopy1->hasChild(i, j);
			distances[i][j] = rootCopy1->distance();
		}
		rootCopy1 = rootCopy2;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			std::cout << distances[i][j] << " ";
		std::cout << std::endl;
	}
}
