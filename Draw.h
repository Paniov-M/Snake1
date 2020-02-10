#pragma once
#pragma once
#include <iostream>
#include "Source.cpp"
void Draw()                                                                                               //painting  the area
{

	system("cls");                                       //this thing will be clean our monitor after every call functions Draw();

	for (int i = 0;i < width + 1;i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < height;i++)
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

	for (int i = 0;i < width + 1;i++)
		cout << "#";
	cout << endl;
	cout << "SCORE - " << score << endl;
}
