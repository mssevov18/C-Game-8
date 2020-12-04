#pragma once

#include "Miscellaneous.h"
#include "Blocks.h"

//Chunk Section                     |>

//Constant value of the chunk size
const short int CHUNK_SIZE = 16;
const short int CHUNK_AREA = 256;

//Chunk structure
struct Chunk
{
	_2DVector pos = { 0,0 };
	Block block[256];
	bool generated = false;
};

int chunkTopBorder(int y);

int chunkBottomBorder(int y);

int chunkRightBorder(int x);

int chunkLeftBorder(int x);

int findChunkX(int x, bool useLB);

int findChunkY(int y, bool useBB);

_2DVector findActiveChunkPosition(_2DVector pos, _2DVector pastPos);

Chunk generateChunk(_2DVector chunkPos);

