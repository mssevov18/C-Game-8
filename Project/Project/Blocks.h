#pragma once

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
	_2DVector pos = { 0,0 };
	wchar_t face = ' ';
	BlockId id = BlockId::Air;
};

wchar_t returnBlockFace(BlockId id);