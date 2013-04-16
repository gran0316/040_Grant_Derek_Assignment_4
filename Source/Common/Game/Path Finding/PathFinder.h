//
//  PathFinder.h
//  GAM-1532 OSX Game
//
//  Created by Derek Grant on 13-03-19.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef PATH_FINDER_H
#define PATH_FINDER_H

#include <vector>

class Level;
class PathNode;
class Tile;

class PathFinder
{
public:
    PathFinder(Level* level);
    ~PathFinder();
    
    //Call this method to find the path between the two tiles.
    void findPath(Tile* startingTile, Tile* destinationTile);
    
    //Update and paint methods, the painting is really only for debugging.
    void update(double delta);
    void paint();
    
    //State getter methods
    bool wasPathFound();
    bool isSearchingPath();
    bool isUnableToFindPath();
    
    //Final Path methods
    int getFinalPathSize();
    PathNode* getFinalPathNodeAtIndex(int index);
    
private:
    //Private methods, for internal use only
    void clearPathNodes();
    void addNodeToOpenList(PathNode * pathNode);
    void sortOpenList();
    void addAdjacentTile(std::vector<Tile*>& adjacentTiles, Tile* relativeTile, int deltaX, int deltaY);
    bool isTileInClosedList(Tile* tile);
    bool isTileInOpenList(Tile* tile);
    PathNode* getPathNodeFromOpenList(Tile* tile);
    
    int getManhattanDistanceCost(Tile* currentTile, Tile* destinationTile);
    
    //Pointer to the level.
    Level* m_Level;
    
    //Our Open and Closed list as well as the final path.
    std::vector<PathNode*> m_OpenList;
    std::vector<PathNode*> m_ClosedList;
    std::vector<PathNode*> m_FinalPath;
    
    //Enum to keep track of the current state of the path finder
    enum PathFinderState
    {
      StateIdle = 0,
        StateSearchingPath,
        StatePathFound,
        StateError
    };
    
    //Path Finder state variable
    PathFinderState m_State;
    
    //Destination title index
    int m_DestinationTileIndex;
};

#endif 
