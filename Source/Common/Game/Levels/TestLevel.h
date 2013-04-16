//
//  TestLevel.h
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef TEST_LEVEL_H
#define TEST_LEVEL_H

#include "Level.h"


class TestLevel : public Level
{
public:
	TestLevel();
	virtual ~TestLevel();

  //Must be inherited from Level, returns the TileType at a specific index 
  TileType getTileTypeForIndex(int index);
};

#endif