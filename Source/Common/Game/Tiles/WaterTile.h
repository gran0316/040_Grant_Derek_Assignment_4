//
//  WaterTile.h
//  GAM-1532 OSX Game
//
//  Created by Derek Grant on 2013-04-02.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef WATER_TILE_H
#define WATER_TILE_H

#include "Tile.h"

class WaterTile : public Tile
{
public:
	WaterTile();
	virtual ~WaterTile();
    
    //Paint the custom tile
	void paint();
    
    //Return the type of the tile
    const char* getType();
};

#endif