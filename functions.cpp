#include <iostream>
#include "Maze.h"

#include <fstream>
#include <time.h>

using namespace std;


maze::maze(int x, int y)
{
	Maze = new int* [x];
	for (int i = 0; i < x; i++)
	{
		Maze[i] = new int[y] {0};
	}

	this->ex = 0;
	this->ey = 0;
	this->dimx = x;
	this->dimy = y;
	this->SetWalls();
	this->SetCheese();
}
maze::~maze()
{
	for (int i = 0; i < this->dimy; i++)
	{
		delete[] Maze[i];
	}
	delete[] this->Maze;
}
maze::maze(const char* s, int x, int y) /// labirintus letrehozasa allomanybol
{

	ifstream in(s);
	in >> x;
	in >> y;

	Maze = new int* [x];
	for (int i = 0; i < x; i++)
	{
		Maze[i] = new int[y] {0};
	}
	this->dimx = x;
	this->dimy = y;
	this->SetWalls();
	this->SetCheese();
	this->ex = 0;
	this->ey = 0;

}

void maze::SetCheese()
{
	
	int x, y;
	bool placed = false;
	
	while (!placed)
	{
		x = rand() % dimx;
		y = rand() % dimy;
		if (LegalPos(x, y))
		{
			this->sx = x;
			this->sy = y;
			placed = true;
		}
	}
}

void maze::SetWalls()
{
	srand(time(NULL));
	for (int i = 1; i < this->dimx; i++)
	{
		for (int j = 1; j < this->dimy; j++)
		{
			this->Maze[i][j] = rand() % 2;
		}
	}
}
void maze::GetMouse(int& x, int& y)   
{
	x = this->ex;
	y = this->ey;
	
}
void maze::SetMouse(int x, int y)
{
	this->ex = x;
	this->ey = y;
}
bool maze::LegalPos(int x, int y)
{
	if (x * y > this->dimx * this->dimy)
	{
		return false;
	}
	
	if (this->Maze[x][y] == 1)  
	{
		return false;
	}
	if (this->Maze[x][y] == 0)  
	{
		return true;
	}

}
int maze::MoveAbs(int x, int y)		/// Abszolut koordinatakkal megadott elmozdulas, ha szabalyos, visszateriti, hogy elmozdult-e
{
	if (LegalPos(this->ex + x, this->ey + y))
	{
		SetMouse(this->ex + x, this->ey + y);
		return 1;
	}
	return 0;
}
int maze::Move(int direction)	
{
	if (direction == 8) //up
	{
		if (LegalPos(this->ex, this->ey + 1))
		{
			SetMouse(this->ex, this->ey + 1);
		}
		return 1;
	}
	if (direction == 2) //down
	{
		if (LegalPos(this->ex, this->ey - 1))
		{
			SetMouse(this->ex, this->ey - 1);
		}
		return 1;
	}
	if (direction == 6) //right
	{
		if (LegalPos(this->ex + 1, this->ey))
		{
			SetMouse(this->ex + 1, this->ey);
		}
		return 1;
	}
	if (direction == 4) //left
	{
		if (LegalPos(this->ex - 1, this->ey))
		{
			SetMouse(this->ex - 1, this->ey);
		}
		return 1;
	}
	return 0;
}


int maze::Solve(int& solution_size, int* solution)
{
	
	int x, y; 
	int max_try = 1000;
	solution_size = 0;
	srand(time(NULL));
	bool solved = false;
	while (!solved || solution_size < max_try)
	{
		x = rand() % dimx;
		y = rand() % dimy;
		solution[solution_size++] = x;
		solution[solution_size++] = y;
		if (LegalPos(x, y)) 
		{

			if (x == sx && y == sy)
			{
				solved = true;
				return true;
			}
		}
	}
	return 0;
}


void maze::Print()
{

	for (int i = 0; i < this->dimx; i++)
	{	
		for (int j = 0; j < this->dimy; j++)
		{
			cout << this->Maze[i][j] << " ";
		}
		cout << endl;
	}
}



