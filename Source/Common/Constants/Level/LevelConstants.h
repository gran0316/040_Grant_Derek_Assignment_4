//
//  LevelConstants.h
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef LEVEL_CONSTANTS_H
#define LEVEL_CONSTANTS_H

//Global enum for the Level's tile types,
//add additional tile types in this enum
enum TileType
{
  TileTypeGround = 0,
  TileTypeWall,
  TileTypeMud,
  TileTypeWater,
  TileTypeTree,
  TileTypeUnknown,
  TileTypeCount
};

//Test Level Constants
extern const int TEST_LEVEL_TILES[];
extern const int TEST_LEVEL_NUMBER_OF_HORIZONTAL_TILES;
extern const int TEST_LEVEL_NUMBER_OF_VERTICAL_TILES;
extern const int TEST_LEVEL_TILE_SIZE;
extern const int TEST_LEVEL_STARTING_PLAYER_TILE_INDEX;

//Level2 Constants
extern const int LEVEL_2_TILES[];
extern const int LEVEL_2_NUMBER_OF_HORIZONTAL_TILES;
extern const int LEVEL_2_NUMBER_OF_VERTICAL_TILES;
extern const int LEVEL_2_TILE_SIZE;
extern const int LEVEL_2_STARTING_PLAYER_TILE_INDEX;

//Level3 Constants
extern const int LEVEL_3_TILES[];
extern const int LEVEL_3_NUMBER_OF_HORIZONTAL_TILES;
extern const int LEVEL_3_NUMBER_OF_VERTICAL_TILES;
extern const int LEVEL_3_TILE_SIZE;
extern const int LEVEL_3_STARTING_PLAYER_TILE_INDEX;

//Level4 Constants
extern const int LEVEL_4_TILES[];
extern const int LEVEL_4_NUMBER_OF_HORIZONTAL_TILES;
extern const int LEVEL_4_NUMBER_OF_VERTICAL_TILES;
extern const int LEVEL_4_TILE_SIZE;
extern const int LEVEL_4_STARTING_PLAYER_TILE_INDEX;

//Level5 Constants
extern const int LEVEL_5_TILES[];
extern const int LEVEL_5_NUMBER_OF_HORIZONTAL_TILES;
extern const int LEVEL_5_NUMBER_OF_VERTICAL_TILES;
extern const int LEVEL_5_TILE_SIZE;
extern const int LEVEL_5_STARTING_PLAYER_TILE_INDEX;

#endif
