//
//  LevelConstants.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "LevelConstants.h"

//Test Level Constants
const int TEST_LEVEL_TILES[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                                 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1,
                                 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1,
                                 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1,
                                 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1,
                                 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1,
                                 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1,
                                 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1,
                                 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1,
                                 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };


const int TEST_LEVEL_NUMBER_OF_HORIZONTAL_TILES = 16;
const int TEST_LEVEL_NUMBER_OF_VERTICAL_TILES = 12;
const int TEST_LEVEL_TILE_SIZE = 64;
const int TEST_LEVEL_STARTING_PLAYER_TILE_INDEX = 17;

//Level 2 constants
const int LEVEL_2_TILES[]  = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1,
                               1, 0, 1, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 0, 1,
                               1, 0, 1, 0, 0, 0, 1, 3, 3, 1, 0, 0, 0, 1, 0, 1,
                               1, 0, 1, 0, 1, 0, 1, 3, 3, 1, 0, 1, 0, 1, 0, 1,
                               1, 0, 1, 0, 1, 0, 0, 3, 3, 0, 0, 1, 0, 1, 0, 1,
                               1, 0, 1, 0, 1, 0, 0, 3, 3, 0, 0, 1, 0, 1, 0, 1,
                               1, 0, 1, 0, 1, 0, 1, 3, 3, 1, 0, 1, 0, 1, 0, 1,
                               1, 0, 1, 0, 0, 0, 1, 3, 3, 1, 0, 0, 0, 1, 0, 1,
                               1, 0, 1, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 0, 1,
                               1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

const int LEVEL_2_NUMBER_OF_HORIZONTAL_TILES = 16;
const int LEVEL_2_NUMBER_OF_VERTICAL_TILES = 12;
const int LEVEL_2_TILE_SIZE = 64;
const int LEVEL_2_STARTING_PLAYER_TILE_INDEX = 17;

//Level3 Constants
extern const int LEVEL_3_TILES[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                     1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1,
                                     1, 0, 2, 2, 2, 2, 2, 3, 3, 2, 2, 2, 2, 2, 0, 1,
                                     1, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 1,
                                     1, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 1,
                                     1, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 1,
                                     1, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 1,
                                     1, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 1,
                                     1, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 1,
                                     1, 0, 2, 2, 2, 2, 2, 3, 3, 2, 2, 2, 2, 2, 0, 1,
                                     1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1,
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
extern const int LEVEL_3_NUMBER_OF_HORIZONTAL_TILES = 16;
extern const int LEVEL_3_NUMBER_OF_VERTICAL_TILES = 12;
extern const int LEVEL_3_TILE_SIZE = 64;
extern const int LEVEL_3_STARTING_PLAYER_TILE_INDEX = 17;

//Level4 Constants
extern const int LEVEL_4_TILES[] = { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                                     4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4,
                                     4, 2, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 2, 4,
                                     4, 2, 3, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 3, 2, 4,
                                     4, 2, 3, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 3, 2, 4,
                                     4, 2, 3, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 3, 2, 4,
                                     4, 2, 3, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 3, 2, 4,
                                     4, 2, 3, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 3, 2, 4,
                                     4, 2, 3, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 3, 2, 4,
                                     4, 2, 3, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 3, 2, 4,
                                     4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4,
                                     4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 };

extern const int LEVEL_4_NUMBER_OF_HORIZONTAL_TILES = 16;
extern const int LEVEL_4_NUMBER_OF_VERTICAL_TILES = 12;
extern const int LEVEL_4_TILE_SIZE = 64;
extern const int LEVEL_4_STARTING_PLAYER_TILE_INDEX = 17;

//Level5 Constants
extern const int LEVEL_5_TILES[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1,
                                     1, 0, 2, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 0, 1,
                                     1, 0, 1, 4, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 0, 1,
                                     1, 0, 1, 0, 0, 0, 1, 3, 3, 1, 0, 0, 0, 1, 0, 1,
                                     1, 0, 1, 0, 1, 0, 1, 3, 3, 1, 0, 1, 0, 1, 0, 1,
                                     1, 0, 1, 0, 1, 0, 0, 4, 3, 4, 0, 4, 0, 1, 0, 1,
                                     1, 0, 1, 0, 1, 0, 0, 3, 3, 0, 0, 1, 0, 1, 0, 1,
                                     1, 0, 1, 4, 1, 4, 1, 3, 3, 1, 0, 1, 0, 1, 0, 1,
                                     1, 0, 1, 0, 0, 0, 1, 3, 3, 1, 0, 0, 0, 1, 0, 1,
                                     1, 0, 1, 1, 1, 1, 1, 4, 3, 1, 1, 1, 1, 1, 0, 1,
                                     1, 0, 2, 2, 2, 4, 2, 2, 2, 2, 4, 2, 2, 4, 0, 1,
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1 };

extern const int LEVEL_5_NUMBER_OF_HORIZONTAL_TILES = 16;
extern const int LEVEL_5_NUMBER_OF_VERTICAL_TILES = 12;
extern const int LEVEL_5_TILE_SIZE = 64;
extern const int LEVEL_5_STARTING_PLAYER_TILE_INDEX = 17;
