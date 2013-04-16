//
//  Level2.h
//  GAM-1532 OSX Game
//
//  Created by Derek Grant on 13-03-19.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef LEVEL_2_H
#define LEVEL_2_H

#include "Level.h"

class Level2 : public Level
{
public:
	Level2();
	virtual ~Level2();
    
    //Must be inherited from Level, returns the TileType at a specific index
    TileType getTileTypeForIndex(int index);
};

#endif 
