//
//  Pathnode.cpp
//  GAM-1532 OSX Game
//
//  Created by Derek Grant on 13-03-19.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "Pathnode.h"
#include "../Tiles/Tile.h"



#include <stdlib.h>

PathNode::PathNode(Tile* aTile)
{
    //Initialize our member variables.
    m_Tile = aTile;
    m_ScoreG = 0;
    m_ScoreH = 0;
    m_ParentNode = NULL;
}

PathNode::~PathNode()
{
    //Set our pointers to NULL.
    m_Tile = NULL;
    m_ParentNode = NULL;
}

Tile* PathNode::getTile()
{
    return m_Tile;
}

int PathNode::getScoreG()
{
    return m_ScoreG;
}

int PathNode::getScoreH()
{
    return m_ScoreH;
}

int PathNode::getScoreFinal()
{
    return getScoreG() + getScoreH();
}

void PathNode::setScoreG(int aScoreG)
{
    m_ScoreG = aScoreG;
}

void PathNode::setScoreH(int aScoreH)
{
    m_ScoreH = aScoreH;
}

PathNode * PathNode::getParentNode()
{
    return m_ParentNode;
}

void PathNode::setParentNode(PathNode* aParentNode)
{
    m_ParentNode = aParentNode;
}

void PathNode::paintScoring(OpenGLColor aColor)
{
    if(m_Tile != NULL)
    {
        if(getScoreG() != 0 && getScoreH() !=0)
        {
            m_Tile->paintScoreF(getScoreFinal());
            m_Tile->paintScoreG(getScoreG());
            m_Tile->paintScoreH(getScoreH());
            m_Tile->paintListColor(aColor);
        }
    }
}

bool PathNode::compareNode(PathNode *aPathNodeA, PathNode *aPathNodeB)
{
    return aPathNodeA->getScoreFinal() < aPathNodeB->getScoreFinal();
}