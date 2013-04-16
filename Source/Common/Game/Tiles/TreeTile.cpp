//
//  TreeTile.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "TreeTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


TreeTile::TreeTile() : Tile(false, TILE_TREE_TEXTURE)
{
    
}

TreeTile::~TreeTile()
{
    
}

void TreeTile::paint()
{
    OpenGLRenderer::getInstance()->drawTexture(m_TileTexture, getX(), getY());
    
    //Call the tile's paint(), it handle's the selected tile's painting
    Tile::paint();
}

const char* TreeTile::getType()
{
    return TILE_TREE_TYPE;
}