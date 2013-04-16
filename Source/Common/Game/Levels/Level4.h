//
//  Level4.h
//  GAM-1532 OSX Game
//
//  Created by Derek Grant on 2013-04-02.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef LEVEL_4_H
#define LEVEL_4_H

#include "Level.h"

class Level4 : public Level
{
public:
	Level4();
	virtual ~Level4();
    
    //Must be inherited from Level, returns the TileType at a specific index
    TileType getTileTypeForIndex(int index);
};

#endif