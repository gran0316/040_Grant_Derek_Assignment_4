//
//  GroundTile.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "GroundTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


GroundTile::GroundTile() : Tile(true, TILE_GROUND_TEXTURE)
{

}

GroundTile::~GroundTile()
{

}

void GroundTile::paint()
{
    OpenGLRenderer::getInstance()->drawTexture(m_TileTexture, getX(), getY());

  //Call the tile's paint(), it handle's the selected tile's painting
  Tile::paint();
}

const char* GroundTile::getType()
{
  return TILE_GROUND_TYPE;
}
