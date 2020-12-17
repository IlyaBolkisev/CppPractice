#include "Maze.h"
#include <iostream>

Maze::Maze(int n, int m)
{
	this->m_field = new MCell[n * m];
	this->m_height = n;
	this->m_width = m;
}

const MCell& Maze::cell(int i, int j) const
{
	return this->m_field[i * this->m_width + j];
}

bool Maze::hasConnection(int i1, int j1, int i2, int j2)
{
	if (((abs(i1 - i2) + abs(j1 - j2)) != 1) || i1 < 0 || j1 < 0 || i2 < 0 || j2 < 0)
		return false;
	if (i1 == i2)
	{
		if (j1 > j2)
			return this->cell(i2, j2).m_right;
		else
			return this->cell(i1, j1).m_right;
	}
	else
	{
		if (i1 > i2)
			return this->cell(i2, j2).m_down;
		else
			return this->cell(i1, j1).m_down;
	}
}

bool Maze::makeConnection(int i1, int j1, int i2, int j2)
{
	MCell* mCell;
	if (abs(i1 - i2) + abs(j1 - j2) != 1)
		return false;
	if (i1 == i2)
	{
		if (j1 > j2)
			mCell = &this->m_field[i2 * this->m_width + j2];
		else
			mCell = &this->m_field[i1 * this->m_width + j1];
		mCell->m_right = true;
	}
	else
	{
		if (i1 > i2)
			mCell = &this->m_field[i2 * this->m_width + j2];
		else
			mCell = &this->m_field[i1 * this->m_width + j1];
		mCell->m_down = true;
	}
	return true;
}

bool Maze::removeConnection(int i1, int j1, int i2, int j2)
{
	MCell mCell;
	if (abs(i1 - i2) + abs(j1 - j2) != 1)
		return false;
	if (i1 != i2)
	{
		if (i1 > i2)
			mCell = this->cell(i2, j2);
		else 
			mCell = this->cell(i1, j1);
		mCell.m_down = false;
	}
	else
	{
		if (j1 > j2)
			mCell = this->cell(i2, j2);
		else 
			mCell = this->cell(i1, j1);
		mCell.m_right = false;
	}
	return true;
}

void Maze::printMaze()
{
	for (int i = 0; i < this->m_height; i++)
	{
		for (int j = 0; j < this->m_width; j++)
		{
			bool left = this->hasConnection(i, j, i, j - 1);
			bool right = this->hasConnection(i, j, i, j + 1);
			bool down = this->hasConnection(i, j, i + 1, j);
			bool up = this->hasConnection(i, j, i - 1, j);
			if (i == 0 && j == 0) std::cout << (char)248;
			else 
			{
				if (up && right && down && left) std::cout << (char)197;
				else if (up && right && down) std::cout << (char)195;
				else if (up && right && left) std::cout << (char)193;
				else if (up && down && left) std::cout << (char)180;
				else if (right && down && left) std::cout << (char)194;
				else if (up && right) std::cout << (char)192;
				else if (up && down) std::cout << (char)179;
				else if (up && left) std::cout << (char)217;
				else if (right && down) std::cout << (char)218;
				else if (right && left) std::cout << (char)196;
				else if (down && left) std::cout << (char)191;
				else std::cout << (char)248;
			}
		}
		std::cout << std::endl;
	}
}
