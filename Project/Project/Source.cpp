//Preprocessor directives, Using, etc     |>-
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <conio.h>

#include "Map.h"
#include "Miscellaneous.h"
#include "Player.h"

using namespace std;

//Function Declaration                    |>-

void mainLoop();

//Global values                           |>-

//Main                                    |>-
int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);

	mainLoop();

}

//Function Definition                     |>-

void mainLoop()
{
	bool inGame = true;

	Chunk chunk[10];
	Player pl;
	_2DVector ActiveChPos = findActiveChunkPosition(pl.pos, pl.pastPos);
	wchar_t pastSym = NULL;
	wchar_t sym = NULL;

	while (inGame)
	{
		//wcout << "\n\n\n\n\n\n\n\n\n\n";
		system("CLS");

		//Map render
		renderMap(pl, ActiveChPos);
		//Hud render
		wcout << "\n" << pl.pos.x << "   " << pl.pos.y << "   " << sym;
		//Player movement
		pl.pastPos = pl.pos;
		wchar_t sym = _getch();
		switch (sym)
		{
		case 27:
			return;
		case 'w':
			pl.pos.y++;
			break;
		case 's':
			pl.pos.y--;
			break;
		case 'a':
			pl.pos.x--;
			break;
		case 'd':
			pl.pos.x++;
			break;
			case L'à':
			pastSym = sym;
		default:
			break;
		}

		ActiveChPos = findActiveChunkPosition(pl.pos, pl.pastPos);
		if (pastSym != NULL)
		{
			pastSym = NULL;
			switch (sym) //Make this change the direction that the pl is facing
			{
			case 'H': //Up
				pl.dir = UP;
				break;
			case 'P': //Down
				pl.dir = DOWN;
				break;
			case 'K': //Left
				pl.dir = LEFT;
				break;
			case 'M': //Right
				pl.dir = RIGHT;
				break;
			default:
				pastSym = sym;
				break;
			}
		}
		else
			pl.dir = returnCurrentDirection(pl.pos, pl.pastPos);
		pl.currentFace = returnCurrentFace(pl.dir);
		pl.pointerPos = changePointerPos(pl.pos, pl.dir);
	
	}
}
