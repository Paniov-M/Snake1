#include <iostream>
#include "Source.cpp"
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

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };                                     //for the move of snake;

eDirection dir;



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
