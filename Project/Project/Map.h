#pragma once

#include "Miscellaneous.h"
#include "Player.h"
#include "Blocks.h"

//Map Section                       |>

//Function that renders the map
void renderMap(Player pl, _2DVector ActiveChPos);






//Chunk Section                     |>

//Constant value of the chunk size
const char CHUNK_SIZE = 16;

//Chunk structure
struct Chunk
{
	_2DVector pos;
};

int chunkTopBorder(int y);

int chunkBottomBorder(int y);

int chunkRightBorder(int x);

int chunkLeftBorder(int x);

int findChunkX(int x, bool useLB);

int findChunkY(int y, bool useBB);

_2DVector findActiveChunkPosition(_2DVector pos, _2DVector pastPos);

void generateChunkBlocks();