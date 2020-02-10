
#include <iostream>
#include "Source.cpp"
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
