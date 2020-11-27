//Preprocessor directives, Using, etc     |>-
#include <iostream>
#include "Miscellaneous.h"
#include "Map.h"
#include "Player.h"

using namespace std;

//Function Definition                     |>-
//Map Section               |>

void renderMap(Player pl, _2DVector ActiveChPos) //There are issues when the pl gets close to the chunk border!!!
{
	const int leftBorder = ActiveChPos.x * CHUNK_SIZE - (CHUNK_SIZE / 2);
	const int rightBorder = ActiveChPos.x * CHUNK_SIZE + (CHUNK_SIZE / 2);
	const int bottomBorder = ActiveChPos.y * CHUNK_SIZE - (CHUNK_SIZE / 2);
	const int topBorder = ActiveChPos.y * CHUNK_SIZE + (CHUNK_SIZE / 2);

	for (int yi = topBorder; yi >= bottomBorder; yi--)
	{
		for (int xi = leftBorder; xi <= rightBorder; xi++)
		{
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
				else
					wcout << L'┃';
			}
			else if (xi == rightBorder)
			{
				if (yi == topBorder)
					wcout << L'┓';
				else if (yi == bottomBorder)
					wcout << L'┛';
				else
					wcout << L'┃';
			}
			else if (yi == topBorder or yi == bottomBorder)
				wcout << L'━';
			else
				wcout << L' ';


				if ((yi == topBorder or yi == bottomBorder) and xi != rightBorder)
					wcout << L'━';
				else
					wcout << L' ';


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

int chunkTopBorder(int y)	{return y * int(CHUNK_SIZE) + (CHUNK_SIZE / 2);}
int chunkBottomBorder(int y)	{return y * int(CHUNK_SIZE) - (CHUNK_SIZE / 2);}
int chunkRightBorder(int x)	{return x * int(CHUNK_SIZE) + (CHUNK_SIZE / 2);}
int chunkLeftBorder(int x)	{return x * int(CHUNK_SIZE) - (CHUNK_SIZE / 2);}

int findChunkX(int x, bool useLB)
{
	int chX;
	int Rb, Lb;
	
	if(useLB)
		chX = (x + (CHUNK_SIZE / 2)) / CHUNK_SIZE;
	else
		chX = (x - (CHUNK_SIZE / 2)) / CHUNK_SIZE;

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
		chY = (y + (CHUNK_SIZE / 2)) / CHUNK_SIZE;
	else
		chY = (y - (CHUNK_SIZE / 2)) / CHUNK_SIZE;

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

	mem = findChunkY(pos.y, true);
	mem2 = findChunkY(pos.y , false);

	if (mem != NULL and mem2 != NULL or mem == NULL and mem2 == NULL)
	{
		mem = findChunkY(pastPos.y, true);
		if (mem == NULL)
			out.y = findChunkY(pastPos.y, false);
		else
			out.y = mem;
	}
	if (mem != NULL)
		out.y = mem;
	else
		out.y = mem2;

	return out;
}


//Block Section             |>