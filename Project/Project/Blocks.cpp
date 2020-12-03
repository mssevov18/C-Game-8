//Preprocessor directives, Using, etc     |>-
#include <iostream>
#include "Miscellaneous.h"
#include "Map.h"
#include "Player.h"
#include "Blocks.h"

using namespace std;

//Function Definition                     |>-

wchar_t returnBlockFace(BlockId id)
{
	switch (id)
	{
	case BlockId::Air:
		break;
	case BlockId::Bedrock:
		break;
	case BlockId::Stone:
		break;
	case BlockId::Dirt:
		break;
	case BlockId::Wood:
		break;
	case BlockId::Water:
		break;
	default:
		return L'‼';
		break;
	}
}