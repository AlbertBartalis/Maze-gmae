#pragma once
#ifndef LABIRINTUS_H_INCLUDED
#define LABIRINTUS_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS


class maze {
	int** Maze;   
	int dimx, dimy; //size of maze
	int ex, ey;  //coordinates of mouse
	int sx, sy;   //coordinates of cheese
public:
	maze(int, int);
	~maze();
	void GetMouse(int&, int&);   
	void SetMouse(int, int); // set coordinates for mouse
	void SetWalls();	//sets up walls in the maze
	void SetCheese();	//places the cheese in the maze
	bool isSolved_after_move();
	int Move(int direction);			
	int MoveAbs(int, int);		
	bool LegalPos(int, int);		
	void Print();	
	int Solve(int&, int*);	
	
};



#endif
