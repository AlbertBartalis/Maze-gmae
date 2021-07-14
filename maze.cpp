
// 2073.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Varianta mea, cu matrice
//sa includ afisarea labirintului in meniu
#include <iostream>
#include "Maze.h"
#include <time.h>
using namespace std;
void menu()
{
	cout << "------------------------------------------------------------ \n";
	cout << "1. Type in a direction \n";
	cout << "2. Type in an absolute direction (coordinates (x,y)) \n";
	cout << "3. I give up, give me the solution \n";
	cout << "4. Where am I? \n";
	cout << "5. Exit game \n";
	cout << "------------------------------------------------------------ \n";
}
void controls()
{
	cout << "*******************\n";
	cout << "8 = up \n";
	cout << "2 = down \n";
	cout << "6 = right \n";
	cout << "4 = left \n";
	cout << "*******************\n";
}
void print_sol(int size, int* sol)
{
	int count = 1;
	cout << "Generated coordinates: \n";
	for (int i = 0; i < size; i++)
	{
		if (count == 1)
		{
			cout << "(" << sol[i] << ",";
			++count;
		}
		else if (count == 2)
		{
			count = 1;
			cout << sol[i] << ") ";
			if (i < size - 1)
			{
				cout << ", ";
			}
		}
	}
	cout << endl;
}
void play()
{
	int x, y;
	cout << "Insert the dimensions of the maze: \n";
	cout << "Lenght: ";
	cin >> x;
	cout << "Width: ";
	cin >> y;
	maze l(x, y);
	l.SetWalls();
	l.SetCheese();
	l.Print();
	bool solved = false;
	int cmd;
	while (!solved)
	{
		menu();
		cin >> cmd;
		if (cmd == 1)
		{
			controls();
			int direction;
			cin >> direction;
			if (l.Move(direction))
			{
				cout << "Nice move! \n";
			}
			else
			{
				cout << "Illegal move! \n";
			}
			if (l.isSolved_after_move())
			{
				solved = true;
				cout << "The mouse found the cheese! \n";
			}
		}
		if (cmd == 2)
		{
			int x, y;
			cout << "x=";
			cin >> x;
			cout << "y=";
			cin >> y;
			l.SetMouse(x, y);
			if (l.LegalPos(x, y))
			{
				cout << "Nice move! \n";
			}
			else
			{
				cout << "Illegal move! \n";
			}
			if (l.isSolved_after_move())
			{
				solved = true;
				cout << "The mouse found the cheese! \n";
				exit(1);
			}
		}
		if (cmd == 3)
		{
			int* solutii;
			int solv_size;
			solutii = new int[1000];
			if (l.Solve(solv_size, solutii))
			{
				solved = true;
				cout << "The mouse found the cheese! \n";
				print_sol(solv_size, solutii);
				exit(1);
			}

		}
		if (cmd == 4)
		{
			cout << "The mouse is located on coordinates: ";
			int x, y;
			l.GetMouse(x,y);
			cout << x << " " << y;
			cout << endl;
		}
		if (cmd == 5)
		{
			l.~maze();
			exit(1);
		}
	}
	return;
}
bool maze::isSolved_after_move()
{
	if (this->ex == this->sx && this->ey == this->sy)
	{

		return true;
	}
	return false;
}
int main()
{
	play();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
