#pragma once

#include "Map.h"
#include "Miscellaneous.h"

//Block Section                     |>

enum class BlockId
{
	Air = 0,
	Bedrock = 1,
	Stone = 2,
	Dirt = 3,
	Wood = 4,
	Water = 5
};

struct Block
{
	_2DVector pos;
	wchar_t face = ' ';
	BlockId id;
};

wchar_t returnBlockFace(BlockId id);