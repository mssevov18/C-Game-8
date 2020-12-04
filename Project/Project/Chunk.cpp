//Preprocessor directives, Using, etc     |>-
#include <iostream>
#include "Map.h"
#include "Miscellaneous.h"
#include "Blocks.h"
#include "Chunk.h"

using namespace std;

//Function Definition                     |>-
//Chunk Section             |>

int chunkTopBorder(int y) { return y * CHUNK_SIZE + (CHUNK_SIZE / 2); }
int chunkBottomBorder(int y) { return y * CHUNK_SIZE - (CHUNK_SIZE / 2); }
int chunkRightBorder(int x) { return x * CHUNK_SIZE + (CHUNK_SIZE / 2); }
int chunkLeftBorder(int x) { return x * CHUNK_SIZE - (CHUNK_SIZE / 2); }

int findChunkX(int x, bool useLB)
{
	int chX;
	int Rb, Lb;

	if (useLB)
		chX = (x - 1 + (CHUNK_SIZE / 2)) / CHUNK_SIZE;
	else
		chX = (x + 1 - (CHUNK_SIZE / 2)) / CHUNK_SIZE;

	Lb = chunkLeftBorder(chX);
	Rb = chunkRightBorder(chX);
	if (Lb <= x and x <= Rb)
		return chX;
	else
		return NULL;
}

int findChunkY(int y, bool useBB)
{
	int chY;
	int Tb, Bb;

	if (useBB)
		chY = (y - 1 + (CHUNK_SIZE / 2)) / CHUNK_SIZE;
	else
		chY = (y + 1 - (CHUNK_SIZE / 2)) / CHUNK_SIZE;

	Bb = chunkBottomBorder(chY);
	Tb = chunkTopBorder(chY);
	if (Bb <= y and y <= Tb)
		return chY;
	else
		return NULL;
}

_2DVector findActiveChunkPosition(_2DVector pos, _2DVector pastPos)
{
	_2DVector out = { 0,0 };

	int mem = findChunkX(pos.x, true);
	int mem2 = findChunkX(pos.x, false);

	if (mem == 0 and mem2 == 0)
		goto postPastPosCheck;
	if (mem != NULL and mem2 != NULL or mem == NULL and mem2 == NULL)
	{
		mem = findChunkX(pastPos.x, true);
		if (mem == NULL)
			out.x = findChunkX(pastPos.x, false);
		else
			out.x = mem;
	}
postPastPosCheck:
	if (mem != NULL)
		out.x = mem;
	else
		out.x = mem2;

	mem = findChunkY(pos.y, false);
	mem2 = findChunkY(pos.y, true);

	if (mem != NULL and mem2 != NULL or mem == NULL and mem2 == NULL)
	{
		mem = findChunkY(pastPos.y, false);
		if (mem == NULL)
			out.y = findChunkY(pastPos.y, true);
		else
			out.y = mem;
	}
	if (mem != NULL)
		out.y = mem;
	else
		out.y = mem2;

	return out;
}

Chunk generateChunk(_2DVector chunkPos)
{
	Chunk chunk;
	chunk.pos = chunkPos;
	int starting1DPos = flatten2DIterator(chunk.pos, CHUNK_SIZE);

	for (size_t i = 0; i < CHUNK_AREA; i++)
	{
		chunk.block[i].id = BlockId::Air; //Add an algorithm for world gen
		chunk.block[i].face = returnBlockFace(chunk.block[i].id);
		chunk.block[i].pos = expand1DIterator(starting1DPos + i, CHUNK_SIZE, CHUNK_SIZE);
	}

	chunk.generated = true;

	return chunk;
}
