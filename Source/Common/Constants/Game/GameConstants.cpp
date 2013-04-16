#include "GameConstants.h"


//Game Constants
const char* GAME_SCREEN_NAME = "Game";

//Tiles Constants
const char* TILE_WALL_TYPE = "WallTile";
const char* TILE_GROUND_TYPE = "GroundTile";
const char* TILE_MUD_TYPE = "MudTile";
const char* TILE_WATER_TYPE = "WaterTile";
const char* TILE_TREE_TYPE = "TreeTile";
const int TILE_PADDING = 2;
const OpenGLColor TILE_PADDING_COLOR = OpenGLColor(0.2f, 0.2f, 0.2f, 1.0f);
const OpenGLColor TILE_WALL_COLOR = OpenGLColor(0.0f, 0.0f, 0.0f, 1.0f);
const OpenGLColor TILE_GROUND_COLOR = OpenGLColor(1.0f, 1.0f, 1.0f, 1.0f);
const OpenGLColor TILE_SELECTED_COLOR = OpenGLColor(0.392156862745098f, 0.5843137254901961f, 0.9294117647058824f, 1.0f);
const OpenGLColor TILE_PATH_COLOR = OpenGLColor(0.007843137255f, 0.6431372549f, 0.8274509804f, 1.0f);
const OpenGLColor TILE_MUD_COLOR = OpenGLColor(0.5f, 0.35f, 0.05f, 1.0f);
const OpenGLColor TILE_WATER_COLOR = OpenGLColor(0.0f, 0.5647058823529412f, 1.0f, 1.0f);
const OpenGLColor TILE_TREE_COLOR = OpenGLColor(0.0f, 0.0f, 1.0f, 1.0f);

//Player Constants
const char* PLAYER_TYPE = "Player";
const int PLAYER_SIZE = 32;
const float PLAYER_SPEED = 150.0f;
const OpenGLColor PLAYER_INSIDE_COLOR = OpenGLColor(1.0f, 1.0f, 0.0f, 1.0f);
const OpenGLColor PLAYER_OUTLINE_COLOR = OpenGLColor(0.0f, 0.0f, 0.0f, 1.0f);
