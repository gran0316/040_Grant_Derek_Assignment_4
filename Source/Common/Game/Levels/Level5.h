//
//  Level5.h
//  GAM-1532 OSX Game
//
//  Created by Derek Grant on 2013-04-02.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef LEVEL_5_H
#define LEVEL_5_H

#include "Level.h"

class Level5 : public Level
{
public:
	Level5();
	virtual ~Level5();
    
    //Must be inherited from Level, returns the TileType at a specific index
    TileType getTileTypeForIndex(int index);
};

#endif