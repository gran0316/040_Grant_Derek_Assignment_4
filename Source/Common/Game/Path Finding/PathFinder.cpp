//
//  PathFinder.cpp
//  GAM-1532 OSX Game
//
//  Created by Derek Grant on 13-03-19.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "PathFinder.h"
#include "Pathnode.h"
#include "../Tiles/Tile.h"
#include "../Levels/Level.h" 
#include "../../Constants/Constants.h"
#include <stdlib.h>
#include <algorithm>
#include <math.h>

PathFinder::PathFinder(Level* aLevel)
{
    //Set the level pointer
    m_Level = aLevel;
    
    //Initialze the state
    m_State = StateIdle;
    
    //Initiatlze the destination tile index.
    m_DestinationTileIndex = -1;
}

PathFinder::~PathFinder()
{
    //Set the level pointer to NULL. 
    m_Level = NULL;
    
    //Clear all the path nodes.
    clearPathNodes();
}

void PathFinder::findPath(Tile* aStartingTile, Tile* aDestinationTile)
{
    //Reset all the tile path flags.
    for (int i = 0; i < m_Level->getNumberOfTiles(); i++)
    {
        Tile* tile = m_Level->getTileForIndex(i);
        if(tile != NULL && tile->isWalkableTile() == true)
        {
            tile->setIsPath(false);
        }
    }
    
    //Next clear all the path nodes.
    clearPathNodes();
    
    //Next get the current and estination tiles indexes.
    int currentTileIndex = m_Level->getTileIndexForTile(aStartingTile);
    m_DestinationTileIndex = m_Level->getTileIndexForTile(aDestinationTile);
    
    //Make sure they are not the same tile
    if(currentTileIndex == m_DestinationTileIndex)
    {
        return;
    }
    
    //Make sure the destination tile is a walkable tile
    if(aDestinationTile->isWalkableTile() == false)
    {
        return;
    }
    
    //Create a path node for the starting tile and add it to the Open List
    PathNode* pathNode = new PathNode(aStartingTile);
    addNodeToOpenList(pathNode);
    
    //Lastly set the state to 'searching path'
    m_State = StateSearchingPath;
}

void PathFinder::update(double aDelta)
{
    //Make sure we are in the seaching path state.
    while(isSearchingPath() == true)
    {
        //Next make sure there is at least 1 path node in the open list.
        //If there isn't it's possible that the destination can not be reached.
        if(m_OpenList.size() == 0)
        {
            m_State = StateError;
            return;
        }
        
        //Get the first path node from the Open List, because Open List is sorted,
        //we know this is the Path Node with the lowest F score.
        PathNode* currentNode = m_OpenList.front();
        
        //Next add it to the closed list.
        m_ClosedList.push_back(currentNode);
        
        //Lastly remove it from the Open List
        m_OpenList.erase(m_OpenList.begin());
        
        //Next get the current node's tile's index from the level.
        int currentNodeTileIndex = m_Level->getTileIndexForTile(currentNode->getTile());
        if(currentNodeTileIndex == m_DestinationTileIndex)
        {
            //If the current node's tile index is the same as the destination tile, the we
            //have reached out destination tile and now know the shortest path.
            
            do
            {
                //If the parent node doesn't equal NULL, and the current node to the final path list.
              if(currentNode->getParentNode() != NULL)
              {
                  m_FinalPath.insert(m_FinalPath.begin(), currentNode);
              }
                //Set the node's tile isPath flag to true
                currentNode->getTile()->setIsPath(true);
                
                //Set the current node to the parent node.
                currentNode = currentNode->getParentNode();
            }
            while(currentNode != NULL);
            
            //Set the state to the PathFound
            m_State = StatePathFound;
            
            return;
        }
        
        //Now, if we got here, it means we haven't reached the destination, we need to
        // get the current node's adjacent tiles and calculate their path scores.
        std::vector<Tile*> adjacentTiles;
        addAdjacentTile(adjacentTiles, currentNode->getTile(), -1, 0); //Left
        addAdjacentTile(adjacentTiles, currentNode->getTile(), 1, 0); //Right
        addAdjacentTile(adjacentTiles, currentNode->getTile(), 0, -1); //Up
        addAdjacentTile(adjacentTiles, currentNode->getTile(), 0, 1); //Down
        
        //Cycle through the adjacent tiles
        for(int i = 0; i < adjacentTiles.size(); i++)
        {
            Tile* adjacentTile = adjacentTiles.at(i);
            
            //Next we need to check if the adjacent tile is already in the close list,
            //if it is, then we can ignore this tile.
            if(isTileInClosedList(adjacentTile) == true)
            {
                continue;
            }
            
            //Then we need to check if the adjacent tile is already in the Open List
            if(isTileInOpenList(adjacentTile) == true)
            {
                //If we got here, then the tile is in the Open list alreadu and we have to determine
                //if the existing tile's score is lower or the adjacent tile.
                PathNode* existingNode = getPathNodeFromOpenList(adjacentTile);
                
                //Check to see if the adjacent node has a higher G Score
                //(since the h scores will be identical)
                //than the existing node's G score.
                
                if(existingNode->getScoreG() > currentNode->getScoreG() +1)
                {
                    //Update the existing node's parent.
                    existingNode->setParentNode(currentNode);
                    
                    //Set the lower G score
                    existingNode->setScoreG(currentNode->getScoreG() +1);
                    
                    //Sort the OpenList
                    sortOpenList();
                }
            }
            else
            {
               //If we got here then the tile doesn't exist in the Open or Closed list.
                //Let's make a new PathNode object and calculate it's tile score.
                PathNode* adjacentNode = new PathNode(adjacentTile);
                
                //Set the pathNode's parent.
                adjacentNode->setParentNode(currentNode);
                
                //Calculate the G score, it's a Parent node's G score plus 1.
                adjacentNode->setScoreG(currentNode->getScoreG() +1);
                
                //Calculate the H score, remember we use the manhattan distance method.
                adjacentNode->setScoreH(getManhattanDistanceCost(adjacentTile, m_Level->getTileForIndex(m_DestinationTileIndex)));
                
                //Lastly add is to the Open list, calling this method will sort the open list.
                addNodeToOpenList(adjacentNode);
                                    
            }
        }
    }
}

void PathFinder::paint()
{
    //Paint the tile scoring for all the path nodes in the closed list.
    for(int i = 0; i < m_ClosedList.size(); i++)
    {
        m_ClosedList.at(i)->paintScoring(OpenGLColorBlue());
    }
    
    //Paint the tile scoring for all the path nodes in the closed list.
    for(int i = 0; i < m_OpenList.size(); i++)
    {
        m_OpenList.at(i)->paintScoring(OpenGLColorRed());
    }
    
    //Paint the tile scoring for all the path nodes in the closed list.
    for(int i = 0; i < m_FinalPath.size(); i++)
    {
        m_FinalPath.at(i)->paintScoring(OpenGLColorYellow());
    }
}

bool PathFinder::wasPathFound()
{
    return m_State == StatePathFound;
}

bool PathFinder::isSearchingPath()
{
    return m_State == StateSearchingPath;
}

bool PathFinder::isUnableToFindPath()
{
    return m_State == StateError;
}

int PathFinder::getFinalPathSize()
{
    return m_FinalPath.size();
}

PathNode* PathFinder::getFinalPathNodeAtIndex(int aIndex)
{
    if(aIndex >= 0 && aIndex < getFinalPathSize())
    {
        return m_FinalPath.at(aIndex);
    }
    
    return NULL;
}

void PathFinder::clearPathNodes()
{
    while(m_OpenList.size() > 0)
    {
        //Get the last path node in the Open List
        PathNode* pathNode = m_OpenList.back();
        
        //Delete it from memory.
        delete pathNode;
        
        //Remove the pointer from the back of the Open List.
        m_OpenList.pop_back();
    }
    
    while(m_ClosedList.size() > 0)
    {
        //Get the last path node in the Open List
        PathNode* pathNode = m_ClosedList.back();
        
        //Delete it from memory.
        delete pathNode;
        
        //Remove the pointer from the back of the Open List.
        m_ClosedList.pop_back();
    }
    
    //Clear all the elements from the final path, we don't need to delete the memory here, because there were copies of the points not the objects.
    m_FinalPath.clear();
    
    //Set the destination index to -1.
    m_DestinationTileIndex = -1;
}

void PathFinder::addNodeToOpenList(PathNode* aPathNode)
{
    //Add the path node to the list, then sort it.
    m_OpenList.push_back(aPathNode);
    sortOpenList();
}

void PathFinder::sortOpenList()
{
    std::sort(m_OpenList.begin(), m_OpenList.end(), PathNode::compareNode);
}

void PathFinder::addAdjacentTile(std::vector<Tile *> &aAdjacentTiles, Tile *aRelativeTile, int aDeltaX, int aDeltaY)
{
    //Determine the adjacent tiles coordinates
    int coordinateX = m_Level->getTileCoordinateForPosition(aRelativeTile->getX()) + aDeltaX;
    int coordinateY = m_Level->getTileCoordinateForPosition(aRelativeTile->getY()) + aDeltaY;
    
    //Next get the pointer for the adhjacent tile.
    Tile* adjacentTile = m_Level->getTileForCoordinates(coordinateX, coordinateY);
    
    if(adjacentTile != NULL)
    {
        bool isWalkable = adjacentTile->isWalkableTile();
        bool isValid = m_Level->validateTileCoordinates(coordinateX, coordinateY);
        
        if(isWalkable == true && isValid == true)
        {
            aAdjacentTiles.push_back(adjacentTile);
        }
    }
}

bool PathFinder::isTileInClosedList(Tile* aTile)
{
    //Get the tile's tile index.
    int tileIndex = m_Level->getTileIndexForTile(aTile);
    
    //Cycle through the closed list and compare the tile indexes.
    for(int i = 0; i < m_ClosedList.size(); i++)
    {
        PathNode* pathNode = m_ClosedList.at(i);
        if(m_Level->getTileIndexForTile(pathNode->getTile()) == tileIndex)
        {
            return true;
        }
    }
    
    //If we got here then the tile is not in the closed list.
    return false;
}

bool PathFinder::isTileInOpenList(Tile* aTile)
{
    return getPathNodeFromOpenList(aTile) != NULL;
}

PathNode* PathFinder::getPathNodeFromOpenList(Tile* aTile)
{
    //Get the tile's tile index.
    int tileIndex = m_Level->getTileIndexForTile(aTile);
    
    //Cycle through the open list and compare the tile indexes.
    for(int i = 0; i < m_OpenList.size(); i++)
    {
        PathNode* pathNode = m_OpenList.at(i);
        if(m_Level->getTileIndexForTile(pathNode->getTile()) == tileIndex)
        {
            return pathNode;
        }
    }
    
    //If we got here then the tile is not in the open list.
    return false;
}

int PathFinder::getManhattanDistanceCost(Tile* aCurrentTile, Tile* aDestinationTile)
{
    int currentCoordinateX = m_Level->getTileCoordinateForPosition(aCurrentTile->getX());
    int currentCoordinateY = m_Level->getTileCoordinateForPosition(aCurrentTile->getY());
    int destinationCoordinateX = m_Level->getTileCoordinateForPosition(aDestinationTile ->getX());
    int destinationCoordinateY = m_Level->getTileCoordinateForPosition(aDestinationTile ->getY());
    
    int distance = abs(destinationCoordinateX - currentCoordinateX) + abs(destinationCoordinateY - currentCoordinateY);
    
    return distance;
}