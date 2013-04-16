//
//  WaterTile.cpp
//  GAM-1532 OSX Game
//
//  Created by Derek Grant on 2013-04-02.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "WaterTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


WaterTile::WaterTile() : Tile(true, TILE_WATER_TEXTURE)
{
    
}

WaterTile::~WaterTile()
{
    
}

void WaterTile::paint()
{
    OpenGLRenderer::getInstance()->drawTexture(m_TileTexture, getX(), getY());
    
    //Call the tile's paint(), it handle's the selected tile's painting
    Tile::paint();
}

const char* WaterTile::getType()
{
    return TILE_WATER_TYPE;
}
