#pragma once

//Structures and custom types             |>-

//Data type for coordinates
struct _2DVector
{
	int x; //Left-Right
	int y; //Down-Up
};

//Function Declaration                    |>-

/*Function that prints an error message
How to use:
	=> errorCode -> code for the current error
	=> punctuation -> char for error punctuation
	=> speed -> changes the speed of the punctuation
	=> wait -> if true, then the function will go through a _getch()
	=> clearScreen -> if true, then the function will clear the screen at the begining
Error Code:
	1. No available space for a new set
	2. No available sets
	3. Not enough sets
	4. Invalid input
	5. Input was not an integer. Enter an integer.
	6. Set size cannot be smaller than 0
	7. Number is out of range
*/
void err(int errorCode, char punctuation = '.', int speed = 1, bool wait = false, bool clearScreen = true);

//Function to input and check an integer
void putinInt(int& num);

void display2DVector(_2DVector vec, bool newLine = true);

bool isEqualto2DVector(_2DVector a, _2DVector b);
