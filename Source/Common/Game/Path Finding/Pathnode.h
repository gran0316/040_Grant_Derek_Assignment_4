//
//  Pathnode.h
//  GAM-1532 OSX Game
//
//  Created by Derek Grant on 13-03-19.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef PATH_NODE_H
#define PATH_NODE_H

#include "../../OpenGL/OpenGL.h"

class Tile;

class PathNode
{
public:
    PathNode(Tile* tile);
    ~PathNode();
    
    Tile* getTile();
    
    int getScoreG();
    int getScoreH();
    int getScoreFinal();
    
    void setScoreG(int scoreG);
    void setScoreH(int scoreH);
    
    PathNode * getParentNode();
    void setParentNode(PathNode* parentNode);
    
    void paintScoring(OpenGLColor color);
    
    static bool compareNode(PathNode* pathNodeA, PathNode* pathNodeB);
    
private:
    Tile * m_Tile;
    int m_ScoreG;
    int m_ScoreH;
    PathNode* m_ParentNode;
};


#endif 
