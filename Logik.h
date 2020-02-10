#pragma once
#include <iostream>
#include "Source.cpp"
void Logik()
{
	int prevX = tailX[0];
	int prevY = tailY[0];

	int prev2X, prev2Y;

	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1;i < nTail;i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (dir)                                               //logik our move;
	{
	case LEFT:
		x--;                                               //its coordinates of our snake;                                       
		break;                                              //(<--- or --->) x-our width , so if we go left X will be less(--);

	case RIGHT:
		x++;
		break;

	case DOWN:
		y++;                                               //( | ) y-  our height , so if we go down Y will be less(--);   
		break;

	case UP:
		y--;
		break;
	}

	if (x > width || x < 0 || y>height || y < 0)                 //if we move to edge so we  lose our game ;
		gameOver = true;

	/*	if (x > width-1)                                             //if we go on the wall so we move in other side;
			x = 0;
		else if (x < 0)
			x = width - 2;
		if (y > height)
			y = 0;
		else if (y < 0)
			y = height ;*/

	for (int i = 0;i < nTail;i++)
	{
		if (tailX[i] == x && tailY[i] == y)
		{
			gameOver = true;
		}
	}
	if (x == fruitX && y == fruitY)                       //if cordinates of our SNAKE  be similar like cordinates of FRUIT we will add some point to our score;
	{
		score += 10;

		fruitX = rand() % width;                          //also we add new random fruit;         
		fruitY = rand() % height;

		nTail++;
	}
}

