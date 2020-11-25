//Preprocessor directives, Using, etc     |>-
#include <iostream>
#include "Player.h"

//Function Definition                     |>-

wchar_t returnCurrentPlayerFace(enum class Direction dir)
{
	switch (dir)
	{
	case Direction::STATIONARY:
		return L'♦';
		break;
	case Direction::UP:
		return L'▲';
		break;
	case Direction::DOWN:
		return L'▼';
		break;
	case Direction::LEFT:
		return L'◄';
		break;
	case Direction::RIGHT:
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
		return Direction::LEFT;
	case 1:
		return Direction::RIGHT;
	default:
		switch (yDif)
		{
		case -1:
			return Direction::DOWN;
		case 1:
			return Direction::UP;
		default:
			return Direction::STATIONARY;
		}
	}

}

_2DVector changePointerPos(_2DVector pos, Direction dir)
{
	switch (dir)
	{
	case Direction::STATIONARY:
		return pos;
	case Direction::UP:
		return { pos.x, pos.y + 1 };
	case Direction::DOWN:
		return { pos.x, pos.y - 1 };
	case Direction::LEFT:
		return { pos.x - 1, pos.y };
	case Direction::RIGHT:
		return { pos.x + 1, pos.y };
	default:
		return pos;
	}
}

wchar_t returnCurrentPointerFace(enum class PointerState pState)
{
	switch (pState)
	{
	case PointerState::PLACE:
		return L'■';
		break;
	case PointerState::REMOVE:
		return L'□';
		break;
	case PointerState::INTERACT:
		return L'¤';
		break;
	default:
		return L'‼';
		break;
	}
}