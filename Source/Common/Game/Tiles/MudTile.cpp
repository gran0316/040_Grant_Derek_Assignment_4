//
//  MudTile.cpp
//  GAM-1532 OSX Game
//
//  Created by Derek Grant on 2013-04-02.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "MudTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


MudTile::MudTile() : Tile(true, TILE_MUD_TEXTURE)
{
    
}

MudTile::~MudTile()
{
    
}

void MudTile::paint()
{
    OpenGLRenderer::getInstance()->drawTexture(m_TileTexture, getX(), getY());
    
    //Call the tile's paint(), it handle's the selected tile's painting
    Tile::paint();
}

const char* MudTile::getType()
{
    return TILE_MUD_TYPE;
}
