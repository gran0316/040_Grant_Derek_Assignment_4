//
//  WallTile.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "WallTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


WallTile::WallTile() : Tile(false, TILE_WALL_TEXTURE)
{

}

WallTile::~WallTile()
{

}

void WallTile::paint()
{
    OpenGLRenderer::getInstance()->drawTexture(m_TileTexture, getX(), getY());

  //Call the tile's paint(), it handle's the selected tile's painting
  Tile::paint();
}

const char* WallTile::getType()
{
  return TILE_WALL_TYPE;
}