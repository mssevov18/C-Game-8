//Preprocessor directives, Using, etc     |>-
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <conio.h>
#include <vector>

#include "Map.h"
#include "Miscellaneous.h"
#include "Chunk.h"
#include "Blocks.h"
#include "Player.h"

using namespace std;

//Function Declaration                    |>-

void mainLoop();

void titleScreen();

//Global values                           |>-

//Main                                    |>-

int main()
{
	int a = _setmode(_fileno(stdout), _O_U16TEXT);
	a = _setmode(_fileno(stdin), _O_U16TEXT);

	titleScreen();

	mainLoop();

}

//Function Definition                     |>-

void mainLoop()
{
	bool inGame = true;
	bool inputArrows = false;
	bool modeChanged = false;

	Player pl;
	vector<Chunk> chunks;
	_2DVector ActiveChPos = { 0,0 };
	int ActiveChZ = 0;
	chunks.push_back(generateChunk(ActiveChPos));
	wchar_t sym = NULL;
	enum PointerState pastPState = PointerState::PLACE;

	while (inGame)
	{
		//wcout << "\n\n\n\n\n\n\n\n\n\n"; //Alternative option
		system("CLS");

		if (!isEqualto2DVector(ActiveChPos, ActiveChPos = findActiveChunkPosition(pl.pos, pl.pastPos)))
		{
			size_t i = 0;
			for (i = 0; i < chunks.size(); i++)
			{
				if (isEqualto2DVector(chunks[i].pos, ActiveChPos))
					break;

				if (!chunks[i].generated)
				{
					chunks.push_back(generateChunk(ActiveChPos));
					break;	
				}

			}
			ActiveChZ = i;
		}
		
		//Map render
		renderMap(pl, chunks[ActiveChZ], ActiveChPos);
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

void titleScreen()
{
	system("CLS");
	// ╔ ╗ ╚ ╝ ╠ ╣ ═ ║ ╦ ╩ ╬
	wcout << L"╔══════════════════════════╗\n";
	wcout << L"║   C++ Game Iteration 8   ║\n";
	wcout << L"╠══════════════════════════╣\n";
	wcout << L"║      By Martin4ata       ║\n";
	wcout << L"╚══════════════════════════╝\n\n";

	wcout << L"Press any button to continue...\n";
	char c = _getch();


}