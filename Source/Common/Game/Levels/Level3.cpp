//
//  Level3.cpp
//  GAM-1532 OSX Game
//
//  Created by Derek Grant on 2013-04-02.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "Level3.h"

#include "../../Constants/Constants.h"


Level3::Level3() : Level(LEVEL_3_NUMBER_OF_HORIZONTAL_TILES,
                         LEVEL_3_NUMBER_OF_VERTICAL_TILES,
                         LEVEL_3_TILE_SIZE,
                         LEVEL_3_STARTING_PLAYER_TILE_INDEX)
{
    //Load the level
    loadLevel();
}

Level3::~Level3()
{
    //All the memory is deleted in the level class
}

TileType Level3::getTileTypeForIndex(int aIndex)
{
    //This method returns the level's TileTypes from this constant array
    return (TileType)LEVEL_3_TILES[aIndex];
}