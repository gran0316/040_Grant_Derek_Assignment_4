//
//  Level4.cpp
//  GAM-1532 OSX Game
//
//  Created by Derek Grant on 2013-04-02.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "Level4.h"

#include "../../Constants/Constants.h"


Level4::Level4() : Level(LEVEL_4_NUMBER_OF_HORIZONTAL_TILES,
                         LEVEL_4_NUMBER_OF_VERTICAL_TILES,
                         LEVEL_4_TILE_SIZE,
                         LEVEL_4_STARTING_PLAYER_TILE_INDEX)
{
    //Load the level
    loadLevel();
}

Level4::~Level4()
{
    //All the memory is deleted in the level class
}

TileType Level4::getTileTypeForIndex(int aIndex)
{
    //This method returns the level's TileTypes from this constant array
    return (TileType)LEVEL_4_TILES[aIndex];
}