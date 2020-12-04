//Preprocessor directives, Using, etc     |>-
#include <iostream>
#include "Map.h"
#include "Miscellaneous.h"
#include "Player.h"
#include "Chunk.h"
#include "Blocks.h"

using namespace std;

//Function Definition                     |>-
//Map Section               |>

bool blink = false;
void renderMap(Player pl, Chunk ch, _2DVector ActiveChPos) //There are issues when the pl gets close to the chunk border!!!
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
	for (loopPos.y = topBorder + 1; loopPos.y >= bottomBorder - 1; loopPos.y--)
	{ 
		for (loopPos.x = leftBorder - 1; loopPos.x <= rightBorder + 1; loopPos.x++)
		{
			triplet = L"";

			//Left section
			if (loopPos.x == leftBorder - 1)
			{
				if (loopPos.y == topBorder + 1)
					triplet += wallTopLeft;
				else if (loopPos.y == bottomBorder - 1)
					triplet += wallBottomLeft;
				else if (loopPos.y == pl.pos.y)
					triplet += plIndicatorLeft;
				else
					triplet += wallVertical;
			}
			else if (loopPos.y == topBorder + 1 or loopPos.y == bottomBorder - 1)
				triplet += wallHorizontal;
			else
				triplet += L' ';

			//Middle section
			if (loopPos.x != leftBorder - 1 and loopPos.x != rightBorder + 1)
			{
				if (isEqualto2DVector(loopPos, pl.pos) and pl.pos.x != leftBorder - 1 and pl.pos.x != rightBorder + 1 and pl.pos.y != topBorder + 1 and pl.pos.y != bottomBorder - 1)
					triplet += pl.currentFace;
				else if (isEqualto2DVector(loopPos, pl.pointerPos) and pl.pointerPos.x != leftBorder - 1 and pl.pointerPos.x != rightBorder + 1 and pl.pointerPos.y != topBorder + 1 and pl.pointerPos.y != bottomBorder - 1)
				{
					switch (pl.dir)
					{
					case Direction::LEFT:
						triplet += ch.block[flatten2DIterator(loopPos, CHUNK_SIZE)].face;
						triplet += pl.pointerFace;
						break;
					case Direction::RIGHT:
						triplet += pl.pointerFace;
						triplet += ch.block[flatten2DIterator(loopPos, CHUNK_SIZE)].face;
						break;
					default:
						triplet += pl.pointerFace;
						triplet += ch.block[flatten2DIterator(loopPos, CHUNK_SIZE)].face;
						break;
					}
					goto printTriplet;
				}
				else if (loopPos.x == pl.pos.x)
				{
					if (loopPos.y == topBorder + 1)
						triplet += plIndicatorTop;
					else if (loopPos.y == bottomBorder - 1)
						triplet += plIndicatorBottom;
					else					
						triplet += ch.block[flatten2DIterator(loopPos,CHUNK_SIZE)].face;
				}
				else if (loopPos.y == topBorder + 1 or loopPos.y == bottomBorder - 1)
					triplet += wallHorizontal;
				else
					triplet += ch.block[flatten2DIterator(loopPos, CHUNK_SIZE)].face;
			}

			//Right section

			if (loopPos.x == rightBorder + 1)
			{
				if (loopPos.y == topBorder + 1)
					triplet += wallTopRight;
				else if (loopPos.y == bottomBorder - 1)
					triplet += wallBottomRight;
				else if (loopPos.y == pl.pos.y)
					triplet += plIndicatorRight;
				else
					triplet += wallVertical;
			}
			else if (loopPos.y == topBorder + 1 or loopPos.y == bottomBorder - 1)
				triplet += wallHorizontal;
			else
				triplet += L' ';

			printTriplet:
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
	blink = !blink;
}