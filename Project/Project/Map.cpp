//Preprocessor directives, Using, etc     |>-
#include <iostream>
#include "Map.h"
#include "Miscellaneous.h"
#include "Player.h"
#include "Blocks.h"

using namespace std;

//Function Definition                     |>-
//Map Section               |>

void renderMap(Player pl, _2DVector ActiveChPos) //There are issues when the pl gets close to the chunk border!!!
{
	const int leftBorder = chunkLeftBorder(ActiveChPos.x);
	const int rightBorder = chunkRightBorder(ActiveChPos.x);
	const int bottomBorder = chunkBottomBorder(ActiveChPos.y);
	const int topBorder = chunkTopBorder(ActiveChPos.y);

	/*
	┳┻┣┫┃┏┗┓┛┃━
	
	┏━━┳━━━━━━━━━┓
	┃            ┃
	┣  ►¤        ┫
	┃            ┃
	┃            ┃
	┗━━┻━━━━━━━━━┛
	
	*/


	//!!! PROBLEM
	// WHEN GOING TO THE NEXT CHUNK THE PLAYER STARTS FROM 1 POSITION AWAY FROM THE BORDER
	//imstupid

	_2DVector loopPos{ leftBorder,topBorder };
	wstring triplet = L"";
	for (loopPos.y = topBorder; loopPos.y >= bottomBorder; loopPos.y--)
	{ 
		for (loopPos.x = leftBorder; loopPos.x <= rightBorder; loopPos.x++)
		{
			triplet = L"";

			//Left section
			if (loopPos.x == leftBorder)
			{
				if (loopPos.y == topBorder)
					triplet += wallTopLeft;
				else if (loopPos.y == bottomBorder)
					triplet += wallBottomLeft;
				else if (loopPos.y == pl.pos.y)
					triplet += plIndicatorLeft;
				else
					triplet += wallVertical;
			}
			else if (loopPos.y == topBorder or loopPos.y == bottomBorder)
				triplet += wallHorizontal;
			else
				triplet += L' ';

			//Middle section
			if (loopPos.x != leftBorder and loopPos.x != rightBorder)
			{
				if (isEqualto2DVector(loopPos, pl.pos) and pl.pos.x != leftBorder and pl.pos.x != rightBorder and pl.pos.y != topBorder and pl.pos.y != bottomBorder)
					triplet += pl.currentFace;
				else if (isEqualto2DVector(loopPos, pl.pointerPos) and pl.pointerPos.x != leftBorder and pl.pointerPos.x != rightBorder and pl.pointerPos.y != topBorder and pl.pointerPos.y != bottomBorder)
					triplet += pl.pointerFace;
				else if (loopPos.x == pl.pos.x)
				{
					if (loopPos.y == topBorder)
						triplet += plIndicatorTop;
					else if (loopPos.y == bottomBorder)
						triplet += plIndicatorBottom;
					else					
						triplet += L' ';
				}
				else if (loopPos.y == topBorder or loopPos.y == bottomBorder)
					triplet += wallHorizontal;
				else
					triplet += L' ';
			}

			//Right section
			if (loopPos.x == rightBorder)
			{
				if (loopPos.y == topBorder)
					triplet += wallTopRight;
				else if (loopPos.y == bottomBorder)
					triplet += wallBottomRight;
				else if (loopPos.y == pl.pos.y)
					triplet += plIndicatorRight;
				else
					triplet += wallVertical;
			}
			else if (loopPos.y == topBorder or loopPos.y == bottomBorder)
				triplet += wallHorizontal;
			else
				triplet += L' ';

			wcout << triplet;

			//Old code - delete?
			//Not up to date
			/*
			if (pl.pos.x == xi and pl.pos.y == yi)
				wcout << pl.currentFace;
			else if (pl.pointerPos.x == xi and pl.pointerPos.y == yi)
				wcout << pl.pointerFace;
			else if (xi == leftBorder)
			{
				if (yi == topBorder)
					wcout << L'┏';
				else if (yi == bottomBorder)
					wcout << L'┗';
				else if (yi != futurePos.y)
					wcout << L'┃';
				else
					wcout << plIndicatorLeft;
			}
			else if (xi == rightBorder)
			{
				if (yi == topBorder)
					wcout << L'┓';
				else if (yi == bottomBorder)
					wcout << L'┛';
				else if (yi != futurePos.y)
					wcout << L'┃';
				else
					wcout << plIndicatorRight;
			}
			else if (yi == topBorder or yi == bottomBorder)
			{
				if (xi != futurePos.x)
					wcout << L'━';
				else if (yi == topBorder)
					wcout << plIndicatorTop;
				else if (yi == bottomBorder)
					wcout << plIndicatorBottom;
				else
					wcout << L'━';
			}
			else
				wcout << L' ';

				if ((yi == topBorder or yi == bottomBorder) and xi != rightBorder and futurePos.x == xi)
				{
					if (pl.pos.y == topBorder or pl.pos.y == bottomBorder)
						wcout << L' ';
				}
				else if ((yi == topBorder or yi == bottomBorder) and xi != rightBorder and futurePos.x != xi)
					wcout << L'━';
				else
					wcout << L' ';
			*/
			//Not up to date
			/*wstring out = L"";
			if (xi == leftBorder)
			{
				if(yi == topBorder)
					out += L'┏';
				else if (yi == bottomBorder)
					out += L'┗';
				else
					out += L'┃';
			}
			else if (yi == topBorder or yi == bottomBorder)
				out += L'━';
			else
				out += L' ';

			if (pl.pos.x == xi and pl.pos.y == yi)
				out += pl.currentFace;
			else if (yi == topBorder or yi == bottomBorder)
				out += L'━';
			else
				out += L' ';

			if (xi == rightBorder)
			{
				if (yi == topBorder)
					out += L'┓';
				else if (yi == bottomBorder)
					out += L'┛';
				else
					out += L'┃';
			}
			else if (yi == topBorder or yi == bottomBorder)
				out += L'━';
			else
				out += L' ';

			wcout << out;*/
		}
		wcout << "\n";
	}
}


//Chunk Section             |>

int chunkTopBorder(int y)		{return y * int(CHUNK_SIZE) + 1 + (CHUNK_SIZE / 2);}
int chunkBottomBorder(int y)	{return y * int(CHUNK_SIZE) - 1 - (CHUNK_SIZE / 2);}
int chunkRightBorder(int x)		{return x * int(CHUNK_SIZE) + 1 + (CHUNK_SIZE / 2);}
int chunkLeftBorder(int x)		{return x * int(CHUNK_SIZE) - 1 - (CHUNK_SIZE / 2);}

int findChunkX(int x, bool useLB)
{
	int chX;
	int Rb, Lb;
	
	if(useLB)
		chX = (x - 1 + (CHUNK_SIZE / 2)) / CHUNK_SIZE;
	else
		chX = (x + 1 - (CHUNK_SIZE / 2)) / CHUNK_SIZE;

	Lb = chX * CHUNK_SIZE - (CHUNK_SIZE / 2);
	Rb = chX * CHUNK_SIZE + (CHUNK_SIZE / 2);
	if (Lb <= x and x <= Rb)
		return chX;
	else
		return NULL;
}

int findChunkY(int y, bool useBB)
{
	int chY;
	int Tb, Bb;
	
	if(useBB)
		chY = (y - 1 + (CHUNK_SIZE / 2)) / CHUNK_SIZE;
	else
		chY = (y + 1 - (CHUNK_SIZE / 2)) / CHUNK_SIZE;

	Bb = chY * CHUNK_SIZE - (CHUNK_SIZE / 2);
	Tb = chY * CHUNK_SIZE + (CHUNK_SIZE / 2);
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
	mem2 = findChunkY(pos.y , true);

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

 _2DVector _Alternative_findActiveChunkPosition(_2DVector pos, _2DVector pastPos)
 {
	 _2DVector out = { 0,0 };


	 return out;
 }