//
//  Level.h
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef LEVEL_H
#define LEVEL_H

#include "../../Constants/Constants.h"


class Tile;
class Player;

class Level
{
public:
	Level(unsigned int horizontalTiles, unsigned int verticalTiles, unsigned int tileSize, int playerStartingTileIndex);
	virtual ~Level();

	//Update, paint and reset methods
	virtual void update(double delta);
	virtual void paint();
  virtual void reset();
  
  //Mouse event methods
	virtual void mouseLeftClickUpEvent(float positionX, float positionY);
	
	//This method must be implemented in inheriting classes, see the TestLevel class on how to use it
  virtual TileType getTileTypeForIndex(int index) = 0;

	//Tile count methods
  unsigned int getNumberOfTiles();
	unsigned int getNumberOfHorizontalTiles();
	unsigned int getNumberOfVerticalTiles();

	//Validate that the tile coordinates passed in are valid
	bool validateTileCoordinates(int coordinatesX, int coordinatesY);

	//Converts a position in screen space into a position in coordinate space
	int getTileCoordinateForPosition(int position);

	//Index methods
	int getTileIndexForPosition(int positionX, int positionY);
	int getTileIndexForCoordinates(int coordinatesX, int coordinatesY);
	int getTileIndexForTile(Tile* tile);

	//Tile methods
	Tile* getTileForPosition(int positionX, int positionY);
	Tile* getTileForCoordinates(int coordinatesX, int coordinatesY);
	Tile* getTileForIndex(int index);
  
  //Coveniance methods to toggle debug paint methods
  void togglePaintTileScoring();
  void togglePaintTileIndexes();

protected:
	//Disables the old tiles selection (if ground tile) and 
	//enables the newly selected tiles selection (if ground tile)
	void setSelectedTileIndex(int selectedIndex);
  
  //Load level method, this MUST be called
  //from the inheriting class' constructor
  void loadLevel();

	//Protected Member variables
	Player* m_Player;
	Tile** m_Tiles;
	unsigned int m_HorizontalTiles;
	unsigned int m_VerticalTiles;
	unsigned int m_TileSize;
  unsigned int m_PlayerStartingTileIndex;
	int m_SelectedTileIndex;
  bool m_PaintTileScoring;
  bool m_PaintTileIndexes;
};

#endif
