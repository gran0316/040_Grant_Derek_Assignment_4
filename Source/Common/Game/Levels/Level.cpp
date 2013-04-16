//
//  Level.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "Level.h"
#include "../Player.h"
#include "../Tiles/Tile.h"
#include "../Tiles/WallTile.h"
#include "../Tiles/GroundTile.h"
#include "../Tiles/MudTile.h"
#include "../Tiles/WaterTile.h"
#include "../Tiles/TreeTile.h"
#include "../Path Finding/PathFinder.h"
#include "../../Constants/Constants.h"
#include <stdlib.h>


Level::Level(unsigned int aHorizontalTiles, unsigned int aVerticalTiles, unsigned int aTileSize, int aPlayerStartingTileIndex)
{
  //Set the number of horizontal and vertical tiles as well as the tile size
	m_HorizontalTiles = aHorizontalTiles;
	m_VerticalTiles = aVerticalTiles;
	m_TileSize = aTileSize;
  m_PlayerStartingTileIndex = aPlayerStartingTileIndex;
  
  //Create the player object
	m_Player = new Player(this);
  
  //Allocate the tiles array, the inheriting class will populate this array with Tile objects
	m_Tiles = new Tile*[aHorizontalTiles * aVerticalTiles];
  
  //Initialize the selected tile index
	m_SelectedTileIndex = -1;
  
  //Initialize the paint flags
  m_PaintTileScoring = false;
  m_PaintTileIndexes = false;
}

Level::~Level()
{
  //Delete the player object
	if(m_Player != NULL)
	{
		delete m_Player;
		m_Player = NULL;
	}

  //Delete the tiles array, the inheriting class
  //must delete the object in this array itself
	if(m_Tiles != NULL)
	{
    //Cycle through and delete all the tile objects in the array
    for(int i = 0; i < getNumberOfTiles(); i++)
    {
      if(m_Tiles[i] != NULL)
      {
        delete m_Tiles[i];
        m_Tiles[i] = NULL;
      }
    }
  
		delete[] m_Tiles;
		m_Tiles = NULL;
	}
}

void Level::update(double aDelta)
{
	//Update all the game tiles
	for(int i = 0; i < getNumberOfTiles(); i++)
	{
		if(m_Tiles[i] != NULL)
		{
			m_Tiles[i]->update(aDelta);
		}
	}

	//Update the Player
	if(m_Player != NULL)
	{
		m_Player->update(aDelta);
	}
}

void Level::paint()
{
	//Cycle through and paint all the tiles
	for(int i = 0; i < getNumberOfTiles(); i++)
	{
    //Safety check the tile
		if(m_Tiles[i] != NULL)
		{
      //Paint the tile
      m_Tiles[i]->paint();
      
      //If the paint tile indexes flag is set to true,
      //draw the index number on the tiles
      if(m_PaintTileIndexes == true)
      {
        m_Tiles[i]->paintIndex(i);
      }
		}
	}

	//Paint the Player
	if(m_Player != NULL)
	{
    //If paint tile scoring flag is set to true,
    //draw the path scoring
    if(m_PaintTileScoring == true)
    {
        m_Player->getPathFinder()->paint();
    }
  
    //Paint the player
		m_Player->paint();
	}
}

void Level::reset()
{
	//Cycle through and reset all the tiles
	for(int i = 0; i < getNumberOfTiles(); i++)
	{
		if(m_Tiles[i] != NULL)
		{
			m_Tiles[i]->reset();
		}
	}

	//Reset the Player
	if(m_Player != NULL)
	{
		m_Player->reset();
        m_Player->setCurrentTile(m_Tiles[m_PlayerStartingTileIndex]);
	}
}

void Level::mouseLeftClickUpEvent(float aPositionX, float aPositionY)
{
	//Convert the mouse click position, into a tile index
	int index = getTileIndexForPosition(aPositionX, aPositionY);

	//Safety check that the tile isn't NULL
	if(m_Tiles[index] != NULL)
	{
    //Set the selected tile index
    setSelectedTileIndex(index);

    //If the tile is walkable, set the player's destination tile
    if(m_Tiles[index]->isWalkableTile() == true)
    {
      m_Player->setDestinationTile(m_Tiles[m_SelectedTileIndex]);
    }
	}
}

unsigned int Level::getNumberOfTiles()
{
  return getNumberOfHorizontalTiles() * getNumberOfVerticalTiles();
}

unsigned int Level::getNumberOfHorizontalTiles()
{
	return m_HorizontalTiles;
}

unsigned int Level::getNumberOfVerticalTiles()
{
	return m_VerticalTiles;
}

bool Level::validateTileCoordinates(int aCoordinatesX, int aCoordinatesY)
{
  if(aCoordinatesX < 0 || aCoordinatesY < 0 || aCoordinatesX >= getNumberOfHorizontalTiles() || aCoordinatesY >= getNumberOfVerticalTiles())
	{
    return false;
  } 
  return true;
}

int Level::getTileCoordinateForPosition(int aPosition)
{
	return (aPosition / m_TileSize);
}

int Level::getTileIndexForPosition(int aPositionX, int aPositionY)
{
	int coordinatesX = getTileCoordinateForPosition(aPositionX);
	int coordinatesY = getTileCoordinateForPosition(aPositionY);
	return getTileIndexForCoordinates(coordinatesX, coordinatesY);
}

int Level::getTileIndexForCoordinates(int aCoordinatesX, int aCoordinatesY)
{
	//Validate the coordinates, then calculate the array index
	if(validateTileCoordinates(aCoordinatesX, aCoordinatesY) == true)
	{
		return aCoordinatesX + (aCoordinatesY * getNumberOfHorizontalTiles());
	}
  
	return -1;
}

int Level::getTileIndexForTile(Tile* aTile)
{
	return getTileIndexForPosition(aTile->getX(), aTile->getY());
}

Tile* Level::getTileForPosition(int aPositionX, int aPositionY)
{
	return getTileForIndex(getTileIndexForPosition(aPositionX, aPositionY));
}

Tile* Level::getTileForCoordinates(int aCoordinatesX, int aCoordinatesY)
{
	return getTileForIndex(getTileIndexForCoordinates(aCoordinatesX, aCoordinatesY));
}

Tile* Level::getTileForIndex(int aIndex)
{
  //Safety check the index bounds
	if(aIndex >= 0 && aIndex < getNumberOfTiles())
	{
		return m_Tiles[aIndex];
	}

  //If we got here, it means the index passed in was out of bounds
	return NULL;
}

void Level::togglePaintTileScoring()
{
  m_PaintTileScoring = !m_PaintTileScoring;
}

void Level::togglePaintTileIndexes()
{
  m_PaintTileIndexes = !m_PaintTileIndexes;
}

void Level::setSelectedTileIndex(int aSelectedIndex)
{
	//Deselect the previously selected tile
	if(m_SelectedTileIndex >= 0 && m_SelectedTileIndex < getNumberOfTiles())
	{
		m_Tiles[m_SelectedTileIndex]->setIsSelected(false);
	}

	//Set the new tile index
	m_SelectedTileIndex = aSelectedIndex;

	//Selected the newly selected tile
	if(m_SelectedTileIndex >= 0 && m_SelectedTileIndex < getNumberOfTiles())
	{
		m_Tiles[m_SelectedTileIndex]->setIsSelected(true);
	}
}

void Level::loadLevel()
{
	//Tile variables
	int tileIndex = 0;
	float tileX = 0.0f;
	float tileY = 0.0f;

	//Cycle through all the tiles and create them
	for(int v = 0; v < getNumberOfVerticalTiles(); v++)
	{
		for(int h = 0; h < getNumberOfHorizontalTiles(); h++)
		{
			//Get the TileType for the current index
      TileType tileType = getTileTypeForIndex(tileIndex);
      
      //Now allocate the proper tile object based on the TileType
      switch (tileType)
      {
        case TileTypeGround:
          m_Tiles[tileIndex] = new GroundTile();
          break;
          
        case TileTypeWall:
          m_Tiles[tileIndex] = new WallTile();
          break;
              
          case TileTypeMud:
              m_Tiles[tileIndex] = new MudTile();
              break;
              
          case TileTypeWater:
              m_Tiles[tileIndex] = new WaterTile();
              break;
              
          case TileTypeTree:
              m_Tiles[tileIndex] = new TreeTile();
              break;

        case TileTypeUnknown:
        default:
          m_Tiles[tileIndex] = NULL;
          break;
      }

			//Set the tile position and size
      if(m_Tiles[tileIndex] != NULL)
      {
        m_Tiles[tileIndex]->setPosition(tileX, tileY);
        m_Tiles[tileIndex]->setSize(m_TileSize, m_TileSize);
      }
      
			//Increment the tile index
			tileIndex++;

			//And increment the tile x position
			tileX += m_TileSize;
		}

		//Increment the tile y position and reset the tile x position, since we started a new row
		tileY += m_TileSize;
		tileX = 0.0f;
	}
  
  //The level is loaded, reset everything
  reset();
}
