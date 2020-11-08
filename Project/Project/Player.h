#pragma once

#include "Miscellaneous.h"

enum Direction
{
	STATIONARY = 0,
	UP = 1,
	DOWN = 2,
	LEFT = 3,
	RIGHT = 4	
};

struct Player
{
	_2DVector pos = { 0,0 };
	_2DVector pastPos = { 0,0 };
	_2DVector pointerPos = { 0,0 };
	enum Direction dir = STATIONARY;
	wchar_t currentFace = L'♦';
	wchar_t pointerFace = L'□';
};

wchar_t returnCurrentFace(enum Direction dir);

Direction returnCurrentDirection(_2DVector pos, _2DVector pastPos);

_2DVector changePointerPos(_2DVector pos, Direction dir);