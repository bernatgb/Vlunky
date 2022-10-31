#ifndef _ENEMY_INCLUDE
#define _ENEMY_INCLUDE


#include "Sprite.h"
#include "TileMap.h"
#include "Player.h"

#include <windows.h> 
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib") // Link to the winmm library


// Enemy is basically a Sprite that represents the Enemy. As such it has
// all properties it needs to track its movement, jumping, and collisions.


class Enemy
{

public:
	void init(const glm::ivec2 &tileMapPos, ShaderProgram &shaderProgram, int look);
	void update(int deltaTime, int move, Player *player, Player *player2, int nbarra);
	void render();

	void setTileMap(TileMap *tileMap);
	void setPosition(const glm::vec2 &pos);

	bool ret_activat();
	void jaActivat();

	LPWSTR Enemy::ConvertString(const std::string& instr);

private:
	bool bJumping;
	glm::ivec2 tileMapDispl, posEnemy;
	int jumpAngle, startY;
	Texture spritesheet;
	Sprite *sprite;
	TileMap *map;

	bool left = true;
	int anada = 1;
	int tSalt = 40;
	int platX = 100;
	int checkX = -1;
	int checkY = -1;
	bool activat = false;
};


#endif // _ENEMY_INCLUDE
