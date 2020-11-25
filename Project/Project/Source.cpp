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
	bool inputArrows = false;
	bool modeChanged = false;

	Chunk chunk[10];
	Player pl;
	_2DVector ActiveChPos = findActiveChunkPosition(pl.pos, pl.pastPos);
	wchar_t sym = NULL;
	enum PointerState pastPState = PointerState::PLACE;

	while (inGame)
	{
		//wcout << "\n\n\n\n\n\n\n\n\n\n";
		system("CLS");

		//Map render
		renderMap(pl, ActiveChPos);
		//Hud render
		display2DVector(pl.pos);	

		playerMovement:
		//Player movement
		pl.pastPos = pl.pos;
		pastPState = pl.pState;
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
			inputArrows = true;
			goto playerMovement;
			break;
		case '1':
			pl.pState = PointerState::PLACE;
			break;
		case '2':
			pl.pState = PointerState::REMOVE;
			break;
		case '3':
			pl.pState = PointerState::INTERACT;
			break;
		default:
			break;
		}

		if (pastPState != pl.pState)
			modeChanged = true;

		ActiveChPos = findActiveChunkPosition(pl.pos, pl.pastPos);

		if (inputArrows)
		{
			switch (sym) //Make this change the direction that the pl is facing
			{
			case 'H': //Up
				pl.dir = Direction::UP;
				break;
			case 'P': //Down
				pl.dir = Direction::DOWN;
				break;
			case 'K': //Left
				pl.dir = Direction::LEFT;
				break;
			case 'M': //Right
				pl.dir = Direction::RIGHT;
				break;
			default:
				inputArrows = false;
				break;
			}
		}
		else if(!modeChanged)
			pl.dir = returnCurrentDirection(pl.pos, pl.pastPos);

		pl.pointerPos = changePointerPos(pl.pos, pl.dir);
		pl.pointerFace = returnCurrentPointerFace(pl.pState);
		
		if(!modeChanged)
			pl.currentFace = returnCurrentPlayerFace(pl.dir);
	
		modeChanged = false;
	}
}
