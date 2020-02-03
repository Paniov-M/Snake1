
#include <iostream>
#include "Source.cpp"

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
