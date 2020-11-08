//Preprocessor directives, Using, etc     |>-
#include <iostream>
#include "Player.h"

//Function Definition                     |>-

wchar_t returnCurrentFace(enum Direction dir)
{
	switch (dir)
	{
	case STATIONARY:
		return L'♦';
		break;
	case UP:
		return L'▲';
		break;
	case DOWN:
		return L'▼';
		break;
	case LEFT:
		return L'◄';
		break;
	case RIGHT:
		return L'►';
		break;
	default:
		return L'‼';
		break;
	}
}

Direction returnCurrentDirection(_2DVector pos, _2DVector pastPos)
{
	int xDif = pos.x - pastPos.x;
	int yDif = pos.y - pastPos.y;
	
	switch (xDif)
	{
	case -1:
		return LEFT;
	case 1:
		return RIGHT;
	default:
		switch (yDif)
		{
		case -1:
			return DOWN;
		case 1:
			return UP;
		default:
			return STATIONARY;
		}
	}

}

_2DVector changePointerPos(_2DVector pos, Direction dir)
{
	switch (dir)
	{
	case STATIONARY:
		return pos;
	case UP:
		return { pos.x, pos.y + 1 };
	case DOWN:
		return { pos.x, pos.y - 1 };
	case LEFT:
		return { pos.x - 1, pos.y };
	case RIGHT:
		return { pos.x + 1, pos.y };
	default:
		return pos;
	}
}
