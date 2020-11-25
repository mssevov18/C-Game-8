#pragma once

#include "Miscellaneous.h"

enum class Direction
{
	STATIONARY = 0,
	UP = 1,
	DOWN = 2,
	LEFT = 3,
	RIGHT = 4	
};

enum class PointerState
{
	PLACE = 0,
	REMOVE = 1,
	INTERACT = 2
};

struct Player
{
	_2DVector pos = { 0,0 };
	_2DVector pastPos = { 0,0 };
	_2DVector pointerPos = { 0,0 };
	enum Direction dir = Direction::STATIONARY;
	enum class PointerState pState = PointerState::PLACE;
	wchar_t currentFace = L'♦';
	wchar_t pointerFace = L'■';
	//╳╬□■¤
};

wchar_t returnCurrentPlayerFace(enum Direction dir);

Direction returnCurrentDirection(_2DVector pos, _2DVector pastPos);

_2DVector changePointerPos(_2DVector pos, Direction dir);

wchar_t returnCurrentPointerFace(enum PointerState);