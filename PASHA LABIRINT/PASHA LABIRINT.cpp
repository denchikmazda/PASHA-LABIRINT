#include "pch.h"
#include <iostream>
using namespace std;
const int MazeHeight = 11;
const int MazeWidth = 11;

char Maze[MazeHeight][MazeWidth + 1] =
{
	"# #########",
	"#  #      #",
	"# ## #### #",
	"#    #    #",
	"# ## ## ###",
	"# ##  #   #",
	"# ### ### #",
	"# # # # # #",
	"#   # # # #",
	"# ###   # #",
	"######### #"
};

const char Wall = '#';
const char Free = ' ';
const char SomeDude = '*';

class COORD
{
public:
	int X;
	int Y;
	COORD(int x = 0, int y = 0) { X = x, Y = y; }
	COORD(const COORD &coord) { X = coord.X; Y = coord.Y; }
};

COORD StartingPoint(1, 0);
COORD EndingPoint(9, 10);

void PrintDaMaze()
{
	for (int Y = 0; Y < MazeHeight; Y++)
	{
		printf("%s\n", Maze[Y]);
	}
	printf("\n");
}
/*
bool Solve(int X, int Y)
{
	// Make the move (if it wrong, we will backtrack later.
	Maze[Y][X] = SomeDude;

	// If you want progressive update, uncomment these lines...
	//PrintDaMaze();
	//Sleep(50);

	// Check if we have reached our goal.
	if (X == EndingPoint.X && Y == EndingPoint.Y)
	{
		return true;
	}

	// Recursively search for our goal.
	if (X > 0 && Maze[Y][X - 1] == Free && Solve(X - 1, Y))
	{
		return true;
	}
	if (X < MazeWidth && Maze[Y][X + 1] == Free && Solve(X + 1, Y))
	{
		return true;
	}
	if (Y > 0 && Maze[Y - 1][X] == Free && Solve(X, Y - 1))
	{
		return true;
	}
	if (Y < MazeHeight && Maze[Y + 1][X] == Free && Solve(X, Y + 1))
	{
		return true;
	}

	// Otherwise we need to backtrack and find another solution.
	Maze[Y][X] = Free;

	// If you want progressive update, uncomment these lines...
	//PrintDaMaze();
	//Sleep(50);
	return false;
}
*/
int main()
{
	char step;
	bool b = true,exit =false;
	Maze[StartingPoint.X][StartingPoint.Y] = SomeDude;
	while (b)
	{
		cout << "Choose the side which you want to go:" << endl;
		cout << "'w' - up, 'a' - left,'s' - down, 'd'-right" << endl;
		PrintDaMaze();
		cin >> step;
		switch (step)
		{
		case 'a':
			if (StartingPoint.X > 0 && Maze[StartingPoint.X - 1][StartingPoint.Y]==Free)
			{
				StartingPoint.X -= 1;
				Maze[StartingPoint.X][StartingPoint.Y] = SomeDude;
			}
			else if (StartingPoint.X - 1 == EndingPoint.X&&StartingPoint.Y == EndingPoint.Y)
			{
				cout << "Exit is founded! Congratulations!!" << endl;
				exit = true;
			}
			else cout << "You can't go to the left, go to the other side" << endl;
			break;
		case 'w':
			if (StartingPoint.Y > 0 &&	Maze[StartingPoint.X][StartingPoint.Y-1] == Free)
			{
				StartingPoint.Y -= 1;
				Maze[StartingPoint.X][StartingPoint.Y] = SomeDude;
			}
			else if (StartingPoint.X == EndingPoint.X&&StartingPoint.Y-1 == EndingPoint.Y)
			{
				cout << "Exit is founded! Congratulations!!" << endl;
				exit = true;
			}
			else cout << "You can't go to the up, go to the other side" << endl;
			break;
		case's':
			if (StartingPoint.Y < MazeHeight && Maze[StartingPoint.X][StartingPoint.Y+1] == Free)
			{
				StartingPoint.Y += 1;
				Maze[StartingPoint.X][StartingPoint.Y] = SomeDude;
			}
			else if (StartingPoint.X == EndingPoint.X&&StartingPoint.Y+1 == EndingPoint.Y)
			{
				cout << "Exit is founded! Congratulations!!" << endl;
				exit = true;
			}
			else cout << "You can't go to the down, go to the other side" << endl;
			break;
		case 'd':
			if (StartingPoint.X < MazeWidth && Maze[StartingPoint.X + 1][StartingPoint.Y] == Free)
			{
				StartingPoint.X += 1;
				Maze[StartingPoint.X][StartingPoint.Y] = SomeDude;
			}
			else if (StartingPoint.X + 1 == EndingPoint.X&&StartingPoint.Y == EndingPoint.Y)
			{
				cout << "Exit is founded! Congratulations!!" << endl;
				exit = true;
			}
			else cout << "You can't go to the right, go to the other side" << endl;
			break;
		default: if (Maze[StartingPoint.X - 1][StartingPoint.Y] != Free &&
			Maze[StartingPoint.X + 1][StartingPoint.Y] != Free &&
			Maze[StartingPoint.X][StartingPoint.Y - 1] != Free &&
			Maze[StartingPoint.X][StartingPoint.Y + 1] != Free)
				{
					cout << "you are in deadlock" << endl;
					 b= false;
				}
				 else cout << "Choose free side" << endl;

		}//end switch

	}//end while
	if (exit)
	{
		cout << "Your Maze :" << endl;
		PrintDaMaze();
	}
	else if (!b) cout <<"You loser! Try again"<<endl;
	return 0;
}