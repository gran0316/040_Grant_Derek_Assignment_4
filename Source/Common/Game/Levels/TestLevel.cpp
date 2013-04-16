//
//  TestLevel.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "TestLevel.h"
#include "../../Constants/Constants.h"


TestLevel::TestLevel() : Level(TEST_LEVEL_NUMBER_OF_HORIZONTAL_TILES,
                               TEST_LEVEL_NUMBER_OF_VERTICAL_TILES,
                               TEST_LEVEL_TILE_SIZE,
                               TEST_LEVEL_STARTING_PLAYER_TILE_INDEX)
{
  //Load the level
  loadLevel();
}

TestLevel::~TestLevel()
{
  //All the memory is deleted in the level class
}

TileType TestLevel::getTileTypeForIndex(int aIndex)
{
  //This method returns the level's TileTypes from this constant array
  return (TileType)TEST_LEVEL_TILES[aIndex];
}
