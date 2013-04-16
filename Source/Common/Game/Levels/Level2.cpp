//
//  Level2.cpp
//  GAM-1532 OSX Game
//
//  Created by Derek Grant on 13-03-19.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "Level2.h"

#include "../../Constants/Constants.h"


Level2::Level2() : Level(LEVEL_2_NUMBER_OF_HORIZONTAL_TILES,
                               LEVEL_2_NUMBER_OF_VERTICAL_TILES,
                               LEVEL_2_TILE_SIZE,
                               LEVEL_2_STARTING_PLAYER_TILE_INDEX)
{
    //Load the level
    loadLevel();
}

Level2::~Level2()
{
    //All the memory is deleted in the level class
}

TileType Level2::getTileTypeForIndex(int aIndex)
{
    //This method returns the level's TileTypes from this constant array
    return (TileType)LEVEL_2_TILES[aIndex];
}