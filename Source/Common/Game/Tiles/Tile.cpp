//
//  Tile.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "Tile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"
#include <stdlib.h>
#include <sstream>
#include <string>


Tile::Tile(bool aIsWalkableTile, const char* aTexture)
{
  //Initialize the walkable tile, selected and path flags
  m_IsWalkableTile = aIsWalkableTile;
  m_IsSelected = false;
  m_IsPath = false;
  m_TileTexture = new OpenGLTexture(aTexture);
 
  //Create the selected tile object
  m_SelectedTile = new OpenGLTexture(RES_SELECTED_TILE);
  
  //Create the tile index number OpenGLTextures
  m_TileIndexNumbers = new OpenGLTexture*[RES_TILE_INDEX_NUMBERS_COUNT];
  for(int i = 0; i < RES_TILE_INDEX_NUMBERS_COUNT; i++)
  {
    m_TileIndexNumbers[i] = new OpenGLTexture(RES_TILE_INDEX_NUMBERS[i]);
  }

  //Create the tile scoring number OpenGLTextures
  m_TileScoreNumbers = new OpenGLTexture*[RES_TILE_SCORE_NUMBERS_COUNT];
  for(int i = 0; i < RES_TILE_SCORE_NUMBERS_COUNT; i++)
  {
    m_TileScoreNumbers[i] = new OpenGLTexture(RES_TILE_SCORE_NUMBERS[i]);
  }
}

Tile::~Tile()
{
  //Delete the selected tile texture from memory
  if(m_SelectedTile != NULL)
  {
    delete m_SelectedTile;
    m_SelectedTile = NULL;
  }
    
  if(m_TileTexture != NULL)
  {
      delete m_TileTexture;
      m_TileTexture = NULL;
  }
 
  //Delete the tile index number OpenGLTextures
  if(m_TileIndexNumbers != NULL)
  {
    for(int i = 0; i < RES_TILE_INDEX_NUMBERS_COUNT; i++)
    {
      //Delete each OpenGLTexure in the array
      if(m_TileIndexNumbers[i] != NULL)
      {
        delete m_TileIndexNumbers[i];
        m_TileIndexNumbers[i] = NULL;
      }
    }
    
    //Lastly delete the array
    delete [] m_TileIndexNumbers;
    m_TileIndexNumbers = NULL;
  }
  
  //Delete the tile score number OpenGLTextures
  if(m_TileScoreNumbers != NULL)
  {
    for(int i = 0; i < RES_TILE_SCORE_NUMBERS_COUNT; i++)
    {
      //Delete each OpenGLTexure in the array
      if(m_TileScoreNumbers[i] != NULL)
      {
        delete m_TileScoreNumbers[i];
        m_TileScoreNumbers[i] = NULL;
      }
    }
    
    //Lastly delete the array
    delete [] m_TileScoreNumbers;
    m_TileScoreNumbers = NULL;
  }
}

void Tile::update(double aDelta)
{

}

void Tile::paint()
{
  //Paint the selected texture if this tile is actually selected
  if(isSelected() == true)
  {
    OpenGLRenderer::getInstance()->drawTexture(m_SelectedTile, getX(), getY());
  }
}

void Tile::reset()
{
  m_IsSelected = false;
  m_IsPath = false;
}

void Tile::paintScoreG(int aScoreG)
{
  paintScoreNumber(aScoreG, getX() + getWidth() * 0.046875f, getY() + getHeight() * 0.765625f);
}

void Tile::paintScoreH(int aScoreH)
{
  paintScoreNumber(aScoreH, getX() + getWidth() * 0.65f, getY() + getHeight() * 0.765625f);
}

void Tile::paintScoreF(int aScoreF)
{
  paintScoreNumber(aScoreF, getX() + getWidth() * 0.046875f, getY() + getHeight() * 0.03125f);
}

void Tile::paintListColor(OpenGLColor aColor)
{
    OpenGLRenderer::getInstance()->setLineWidth(2.0f);
    OpenGLRenderer::getInstance()->setForegroundColor(aColor);
    OpenGLRenderer::getInstance()->drawRectangle(getX(), getY(), getWidth(), getHeight(), false);
    OpenGLRenderer::getInstance()->setLineWidth(1.0f);
}

void Tile::paintIndex(int aIndex)
{
  //Convert the index to a stringstream
  std::stringstream numberStream;
  numberStream << aIndex;

  //Next convert the stringstream into a string
  std::string numberString(numberStream.str());
  
  //Cycle through each number in the string and calculate the total width of the string
  float stringWidth = 0.0f;
  float stringHeight = 0.0f;
  for(int i = 0; i < numberString.length(); i++)
  {
    //Convert the letter in the string back to an int
    int index = atoi(numberString.substr(i,1).c_str());

    //Increment the X value
    stringWidth += m_TileIndexNumbers[index]->getSourceWidth();
    stringHeight = stringHeight < m_TileIndexNumbers[index]->getSourceHeight() ? m_TileIndexNumbers[index]->getSourceHeight() : stringHeight;
  }
  
  //Calculate the x and y position based on the string width and height
  float x = getX() + (getWidth() - stringWidth) / 2.0f;
  float y = getY() + (getHeight() - stringHeight) / 2.0f;
  for(int i = 0; i < numberString.length(); i++)
  {
    //Convert the letter in the string back to an int
    int index = atoi(numberString.substr(i,1).c_str());

    //Draw the texture that is equivalent to the number
    OpenGLRenderer::getInstance()->drawTexture(m_TileIndexNumbers[index], x, y);
      
    //Increment the X value
    x += m_TileIndexNumbers[index]->getSourceWidth();
  }
}

void Tile::paintScoreNumber(int aNumber, float aX, float aY)
{
  //Check to see if its a walkable tile
  if(isWalkableTile() == true)
  {  
    //Convert the number to a stringstream
    std::stringstream numberStream;
    numberStream << aNumber;

    //Next convert the stringstream into a string
    std::string numberString(numberStream.str());
    
    //Cycle through each number in the string and draw it
    for(int i = 0; i < numberString.length(); i++)
    {
      //Convert the letter in the string back to an int
      int index = atoi(numberString.substr(i,1).c_str());

      //Draw the texture that is equivalent to the number
      OpenGLRenderer::getInstance()->drawTexture(m_TileScoreNumbers[index], aX, aY);
      
      //Increment the X value
      aX += m_TileScoreNumbers[index]->getSourceWidth();
    }
  }
}

bool Tile::isWalkableTile()
{
  return m_IsWalkableTile;
}

void Tile::setIsSelected(bool aIsSelected)
{
	m_IsSelected = aIsSelected;
}

bool Tile::isSelected()
{
	return m_IsSelected;
}

void Tile::setIsPath(bool aIsPath)
{
  if(m_IsWalkableTile == true)
  {
    m_IsPath = aIsPath;
  }
}

bool Tile::isPath()
{
	return m_IsPath;
}