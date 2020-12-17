#include "MCell.h"
#pragma once
#ifndef MAZE_H
#define MAZE_H

class Maze
{
public:
	Maze(int n, int m);
	const MCell& cell(int i, int j) const;
	bool hasConnection(int i1, int j1, int i2, int j2);
	bool makeConnection(int i1, int j1, int i2, int j2);
	bool removeConnection(int i1, int j1, int i2, int j2);
	void printMaze();
private:
	MCell* m_field;
	int m_height;
	int m_width;
};
#endif // !MAZE_H
