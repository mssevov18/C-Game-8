#pragma once

#include "Miscellaneous.h"
#include "Player.h"
#include "Chunk.h"
#include "Blocks.h"

//Map Section                       |>

//Function that renders the map
void renderMap(Player pl, Chunk ch, _2DVector ActiveChPos);


//Map parts

const wchar_t wallTopLeft = L'┏', wallBottomLeft = L'┗', wallTopRight = L'┓', wallBottomRight = L'┛', wallHorizontal = L'━', wallVertical = L'┃', plIndicatorLeft = L'┣', plIndicatorRight = L'┫', plIndicatorTop = L'┳', plIndicatorBottom = L'┻';