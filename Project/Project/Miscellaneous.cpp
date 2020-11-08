//Preprocessor directives, Using, etc     |>-
#include <iostream>
#include "Miscellaneous.h"
#include "windows.h"
#include "conio.h"

using namespace std;

//Function Definition                     |>-

void putinInt(int& num)
{
	cin >> num;
	while (!cin)
	{
		err(5);
		cin.clear();
		cin.ignore();
		cin >> num;
	}
}

void err(int errorCode, char punctuation, int speed, bool wait, bool clearScreen)
{
	if (clearScreen)
		system("CLS");


	cout << "\nError" << punctuation;

	int sleepTime = 125 / speed;
	for (int i = 0; i < 3; i++)
	{
		Sleep(sleepTime);
		cout << '.';
	}
	cout << "\t";

	switch (errorCode)
	{
	case 1:
		cout << "There is no available space for a new set.";
		break;
	case 2:
		cout << "There are no available sets";
		break;
	case 3:
		cout << "There are not enough sets";
		break;
	case 4:
		cout << "Invalid input. Enter a valid input";
		break;
	case 5:
		cout << "Input was not an integer. Enter an integer";
		break;
	case 6:
		cout << "Set size cannot be smaller than 0. Enter a bigger number";
		break;
	case 7:
		cout << "Number is out of range";
		break;
	default:
		break;
	}

	cout << punctuation;

	for (int i = 0; i < 3; i++)
	{
		Sleep(sleepTime);
		cout << '.';
	}


	if (wait)
		char empty = _getch();
}

