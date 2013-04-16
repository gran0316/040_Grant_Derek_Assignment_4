//
//  WallTile.h
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef WALL_TILE_H
#define WALL_TILE_H

#include "Tile.h"


class WallTile : public Tile
{
public:
	WallTile();
	virtual ~WallTile();

  //Paint the custom tile
	void paint();
  
  //Return the type of the tile
  const char* getType();
};

#endif
