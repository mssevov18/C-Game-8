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

//Map parts

const wchar_t wallTopLeft = L'┏', wallBottomLeft = L'┗', wallTopRight = L'┓', wallBottomRight = L'┛', wallHorizontal = L'━', wallVertical = L'┃', plIndicatorLeft = L'┣', plIndicatorRight = L'┫', plIndicatorTop = L'┳', plIndicatorBottom = L'┻';

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

_2DVector _Alternative_findActiveChunkPosition(_2DVector pos, _2DVector pastPos);