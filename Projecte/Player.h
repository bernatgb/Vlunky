#ifndef _PLAYER_INCLUDE
#define _PLAYER_INCLUDE


#include "Sprite.h"
#include "TileMap.h"

#include <windows.h> 
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib") // Link to the winmm library


// Player is basically a Sprite that represents the player. As such it has
// all properties it needs to track its movement, jumping, and collisions.


class Player
{

public:
	void init(const glm::ivec2 &tileMapPos, ShaderProgram &shaderProgram, bool character);
	void update(int deltaTime, bool coop, Player *player);
	void render();
	void morir();
	void ret_pos(int &x,int &y);
	void setTileMap(TileMap *tileMap);
	void setPosition(const glm::vec2 &pos);
	void changeGroundT();
	void changeGroundB();
	void ChangeBarra1();
	void ChangeBarra2();
	glm::ivec2 ret_ini_pos();
	void changeCheck(int checkX, int checkY);
	void setInitPos(glm::ivec2 initpos);
	bool ret_tornat();
	void jaTornat();
	LPWSTR ConvertString(const std::string& instr);

	
private:
	float timer = 1;
	bool mort = false;;
	bool ground = 1;
	bool jump = 0;
	bool barra1 = 0;
	bool barra2 = 0;
	glm::ivec2 tileMapDispl, posPlayer;
	int jumpAngle, startY;
	Texture spritesheet;
	Sprite *sprite;
	TileMap *map;
	int v = 1;
	float ACC = 1;
	glm::ivec2 ini_pos;
	int lastCheck = 0;
	bool tornat = false;
};


#endif // _PLAYER_INCLUDE


