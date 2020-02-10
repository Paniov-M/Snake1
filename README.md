#ALL SNAKE
#include <iostream>
#include <conio.h>          //it is for the Input to see what player press;
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <stdio.h>     
using namespace std;

bool gameOver;                                                                                             //it is varie for the end of game;

const int width = 20;                                                                                      //width - shuruna;

const int height = 20;

 int x, y;                                                                                  //coordinates our snakes;

 int fruitX, fruitY;                                                                 //coordinates our fruit;

 int tailX[100], tailY[100];

 int nTail;

 int score;                                                                         //it is our list of point;

 enum eDirection { STOP = 0,LEFT,RIGHT,UP,DOWN };                                     //for the move of snake;

 eDirection dir;

void Setup()                                                                                                //for the options                            
{
	gameOver = false;

	dir = STOP;                                                //the firs position in the STOP;

	x = width / 2;                                              //So snake located in the centre;  

	y = height / 2;

	fruitX = rand() % width;                                      //fruitX and fruitY it is coordinates of FRUIT 
	                                                             
	                                                             //We do this to fruit  random appear in the area;
	 fruitY = rand() % height;

	score = 0;                                                 //First time score =0;
}

void Draw()                                                                                               //painting  the area
{

	system("cls");                                       //this thing will be clean our monitor after every call functions Draw();

	for ( int i = 0;i < width + 1 ;i++)
		cout << "#";
	cout << endl;

	for ( int i = 0; i < height;i++)
	{
		for (int j = 0; j < width;j++)
		{
			if (j == 0 || j == width - 1)                          //first and last cell will be "#" and cell beetwen them will be empty;

			cout << "#";

			if (i == y && j == x)                                    //it is a head of our snake; 

				cout << "0";


			else if (i == fruitY && j == fruitX)              //it is our fruit;
				cout << "F";

			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						print = true;
						cout << "o";
						
					}
				}

				if (!print)
					cout << " ";
			}

		}

		cout << endl;

	}

	for (int i = 0;i < width + 1 ;i++)
		cout << "#";
	cout << endl;
	cout << "SCORE - " << score<<endl;
}

void Input()                                                                                         //when playes press the button 
{
	if (_kbhit())                     //to see what player press and search this button;
	{
		switch (_getch())            //our move; 
		{
		case 'a':
			dir = LEFT;
			break;

		case 'd':
			dir = RIGHT;
			break;

		case 's':
			dir = DOWN;
			break;

		case 'w':
			dir = UP;
			break;

		case 'x':
			gameOver = true;         //for ending  the game;
			break;
		}
    }
}

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


int main()
{
	Setup();

	while (!gameOver)
	{
		Draw();
		Input();
		Logik();

	}

	return(0);
}
