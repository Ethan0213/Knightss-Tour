
#include "KnightTour.h"
#include <iostream>
#include <iomanip>

using namespace std;

const int
KnightTour::horizontal[8] = { 1, 1, 2, 2, -1, -1, -2, -2 };

const int
KnightTour::vertical[8] = { 2, -2, 1, -1, 2, -2, 1, -1 };

//Define constructer
KnightTour::KnightTour (int x, int y)
{
  if (x >= 0 && x < 8 && y >= 0 && y < 8)
    {
      currentx = x;
      currenty = y;
    }
  else
    {
      currentx = 0;
      currenty = 0;
    }

  initialize ();
}

void
KnightTour::initialize ()
{
  //initialize all cells to 0 in board matrix
  for (int i = 0; i < 8; i++)
    {
      for (int j = 0; j < 8; j++)
	{
	  board[i][j] = 0;
	}
    }
  for (int i = 0; i < 8; i++)
    {
      for (int j = 0; j < 8; j++)
	{
	  access[i][j] = 0;

	  for (int move = 0; move < 8; move++)
	    {
	      int testx = i + vertical[move];
	      int testy = j + horizontal[move];

	      //if [testx][testy] is within the boundry of board
	      if (testx >= 0 && testx < 8 && testy >= 0 && testy < 8)
		{
		  access[i][j]++;
		}
	    }

	}
    }
}

bool
KnightTour::inBoard (int x, int y)
{				//checks for out of bounds
  return x >= 0 && x < 8 && y >= 0 && y < 8;
}

void
KnightTour::getTour ()
{
  int step = 1;
  board[currentx][currenty] = step;
  while (step < 64)
    {
      int nextx = 0;
      int nexty = 0;
      int minAccess = 9;
      for (int k = 0; k < 8; k++)
	{
	  int testx = currentx + vertical[k];
	  int testy = currenty + horizontal[k];
	  if (inBoard (testx, testy) && board[testx][testy] == 0)
	    {
	      access[testx][testy]--;
	      if (access[testx][testy] < minAccess)
		{
		  nextx = testx;
		  nexty = testy;
		  minAccess = access[testx][testy];
		}
	    }
	}
      currentx = nextx;
      currenty = nexty;
      board[currentx][currenty] = ++step;
    }
}

void
KnightTour::printBoard ()
{
  for (int i = 0; i < 8; i++)
    {
      for (int j = 0; j < 8; j++)
	{
	  cout << setw (4) << board[i][j];
	  //cout << endl;
	}
      cout << endl;
    }
}
