//
//  Level5.cpp
//  GAM-1532 OSX Game
//
//  Created by Derek Grant on 2013-04-02.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "Level5.h"

#include "../../Constants/Constants.h"


Level5::Level5() : Level(LEVEL_5_NUMBER_OF_HORIZONTAL_TILES,
                         LEVEL_5_NUMBER_OF_VERTICAL_TILES,
                         LEVEL_5_TILE_SIZE,
                         LEVEL_5_STARTING_PLAYER_TILE_INDEX)
{
    //Load the level
    loadLevel();
}

Level5::~Level5()
{
    //All the memory is deleted in the level class
}

TileType Level5::getTileTypeForIndex(int aIndex)
{
    //This method returns the level's TileTypes from this constant array
    return (TileType)LEVEL_5_TILES[aIndex];
}