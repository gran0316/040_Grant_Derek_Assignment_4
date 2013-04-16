//
//  Player.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "Player.h"
#include "Tiles/Tile.h"
#include "Levels/Level.h"
#include "Path Finding/PathFinder.h"
#include "Path Finding/Pathnode.h"
#include "../OpenGL/OpenGL.h"
#include "../Constants/Constants.h"
#include <stdlib.h>
#include <algorithm>
#include <math.h>

Player::Player(Level* aLevel)
{
  //Create the PathFinder object
    m_PathFinder = new PathFinder(aLevel);
    m_FindPath = false;
    
  //Initialize the current and destination tiles to NULL
  m_CurrentTile = NULL;
  m_DestinationTile = NULL;

  //Initialize the animation member variables
  m_CanAnimate = false;
  m_AbortAnimation = false;
  m_AnimationPathNodeIndex = -1;

  //Initialize the player's size
	setSize(PLAYER_SIZE, PLAYER_SIZE);
}

Player::~Player()
{
  //Delete the PathFinder object from memory.
    if(m_PathFinder != NULL)
    {
        delete m_PathFinder;
        m_PathFinder = NULL;
    }
    
  //Set the current and desination tiles to NULL
	m_CurrentTile = NULL;
	m_DestinationTile = NULL;
}

void Player::update(double aDelta)
{
    //Can we start finding the path?
    if(m_FindPath == true)
    {
        m_FindPath = false;
        findPath();
    }
    
    //Update the path finder, if it's needed
    if(m_PathFinder->isSearchingPath() == true)
    {
        m_PathFinder->update(aDelta);
        
        //Was a path found?
        if(m_PathFinder->wasPathFound() == true)
        {
            startAnimating();
        }
    }
    
    if(isAnimating() == true && m_AnimationPathNodeIndex > -1)
    {
        PathNode* pathNode = m_PathFinder->getFinalPathNodeAtIndex(m_AnimationPathNodeIndex);
        Tile* tile = pathNode != NULL ? pathNode->getTile() : NULL;
        
        //Safety check that tile isn't NULL
        if(tile != NULL)
        {
            //Calculate the center of the tile, this is the tile that we are animating towards.
            int tileX = tile->getX() + (tile->getWidth() - getWidth()) /2.0f;
            int tileY = tile->getY() + (tile->getHeight() - getHeight()) / 2.0f;
            
            //Next calculate how much the player should animate this update() call,
            //use the animate() method to help calculate.
            int playerX = animate(getX(), tileX, aDelta);
            int playerY = animate(getY(), tileY, aDelta);
            setPosition(playerX, playerY);
            
            //Is the player and the tile's position?
            if(playerX == tileX && playerY == tileY)
            {
                m_AnimationPathNodeIndex++;
                
                //Set the current tile's path flag to false
                m_CurrentTile->setIsPath(false);
                
                //Set the new current tile.
                setCurrentTile(tile);
                
                //Are we done animating?
                if(m_AnimationPathNodeIndex >= m_PathFinder->getFinalPathSize())
                {
                    stopAnimating();
                    m_CurrentTile->setIsPath(false);
                }
                
                //Is the abort animation flag set?
                if(m_AbortAnimation == true)
                {
                    m_AbortAnimation = false;
                    m_FindPath = true; 
                }
            }
        }
    }
}

void Player::paint()
{
	OpenGLRenderer::getInstance()->setForegroundColor(PLAYER_INSIDE_COLOR);
	OpenGLRenderer::getInstance()->drawCircle(getX() + (getWidth() / 2), getY() + (getHeight() / 2), getWidth() / 2, 90);
	OpenGLRenderer::getInstance()->setForegroundColor(PLAYER_OUTLINE_COLOR);
	OpenGLRenderer::getInstance()->drawCircle(getX() + (getWidth() / 2), getY() + (getHeight() / 2), getWidth() / 2, 90, false);
}

void Player::reset()
{
  m_DestinationTile = NULL;
    stopAnimating();
}

const char* Player::getType()
{
  return PLAYER_TYPE;
}

void Player::setCurrentTile(Tile* tile)
{
	//Set the current tile pointer
	m_CurrentTile = tile;

	//Center the player's position on the tile
	setPosition(tile->getX() + ((tile->getWidth() - getWidth()) / 2), tile->getY() + ((tile->getHeight() - getHeight()) / 2));
}

void Player::setDestinationTile(Tile* tile)
{
	//Set the destination tile pointer
	m_DestinationTile = tile;
    
    //Is the Player currently animating?
    if(isAnimating() == true)
    {
        m_AbortAnimation = true;
    }
    else
    {
        m_FindPath = true;
    }
}

PathFinder* Player::getPathFinder()
{
    return m_PathFinder;
}

void Player::findPath()
{
    //Stop the current path animation (if there is one)
    stopAnimating();
    
    //Find the current path
    m_PathFinder->findPath(m_CurrentTile, m_DestinationTile);
}

float Player::animate(float aCurrent, float aTarget, double aDelta)
{
  float increment = aDelta * PLAYER_SPEED * (aTarget < aCurrent ? -1 : 1);
    
  if(m_CurrentTile->getType() == TILE_MUD_TYPE)
  {
      increment = increment/1.5f;
  }
  if(m_CurrentTile->getType() == TILE_WATER_TYPE)
  {
      increment = increment/2;
  }
    
  if(fabs(increment) > fabs(aTarget - aCurrent))
  {
    return aTarget;
  }
  else
  {
    aCurrent += increment;
  }
    
  return aCurrent;
}

void Player::startAnimating()
{
	m_CanAnimate = true;
	m_AnimationPathNodeIndex = 0;
}

void Player::stopAnimating()
{
	m_CanAnimate = false;
	m_AnimationPathNodeIndex = -1;
}

bool Player::isAnimating()
{
  return m_CanAnimate;
}
