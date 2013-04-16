#include "Game.h"
#include "GameObject.h"
#include "Levels/TestLevel.h"
#include "Levels/Level2.h"
#include "Levels/Level3.h"
#include "Levels/Level4.h"
#include "Levels/Level5.h"
#include "../OpenGL/OpenGL.h"
#include "../Constants/Constants.h"
#include "../Utils/Utils.h"
#include "../Screen Manager/ScreenManager.h"


Game::Game()
{
  //Create the level object
    m_Level = NULL;
    
  //Load the level
  loadLevel(1);
  m_LevelToLoad = -1;

  //Reset everything
  reset();
}

Game::~Game()
{
  //Unload the level
  unloadLevel();
}

void Game::update(double aDelta)
{
    
  if(m_LevelToLoad != -1)
  {
      loadLevel(m_LevelToLoad);
      m_LevelToLoad = -1;
  }
    
  if(m_Level != NULL)
  {
    m_Level->update(aDelta);
  }
}

void Game::paint()
{
  if(m_Level != NULL)
  {
    m_Level->paint();
  }
}

void Game::reset()
{
  if(m_Level != NULL)
  {
    m_Level->reset();
  }
}

const char* Game::getName()
{
	return GAME_SCREEN_NAME;
}

void Game::loadLevel(int aLevel)
{
    //First unload the previous level, if we don't we'll have a memory leak.
    unloadLevel();
    
    //Now we can load the new level.
    switch (aLevel)
    {
        case 1:
            m_Level = new TestLevel();
            break;
            
        case 2:
            m_Level = new Level2();
            break;
            
        case 3:
            m_Level = new Level3();
            break;
            
        case 4:
            m_Level = new Level4();
            break;
            
        case 5:
            m_Level = new Level5();
            break;
            
        default:
            m_Level = NULL;
            break;
    }
}

void Game::unloadLevel()
{
    if(m_Level != NULL)
    {
        delete m_Level;
        m_Level = NULL;
    }
}

void Game::mouseLeftClickUpEvent(float aPositionX, float aPositionY)
{
  m_Level->mouseLeftClickUpEvent(aPositionX, aPositionY);
}

void Game::keyUpEvent(int aKeyCode)
{
  if(aKeyCode == KEYCODE_R)
  {
    reset();
  }
  else if(aKeyCode == KEYCODE_S)
  {
    if(m_Level != NULL)
    {
      m_Level->togglePaintTileScoring();
    }
  }
  else if(aKeyCode == KEYCODE_I)
  {
    if(m_Level != NULL)
    {
      m_Level->togglePaintTileIndexes();
    }
  }
  else if(aKeyCode == KEYCODE_1)
  {
      m_LevelToLoad = 1;
  }
  else if(aKeyCode == KEYCODE_2)
  {
      m_LevelToLoad = 2;
  }
  else if(aKeyCode == KEYCODE_3)
  {
      m_LevelToLoad = 3;
  }
  else if(aKeyCode == KEYCODE_4)
  {
      m_LevelToLoad = 4;
  }
  else if(aKeyCode == KEYCODE_5)
  {
      m_LevelToLoad = 5;
  }
}







