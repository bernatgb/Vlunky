#ifndef _SCENE_INCLUDE
#define _SCENE_INCLUDE

#include <vector>
#include <map>
#include <glm/glm.hpp>
#include "ShaderProgram.h"
#include "TileMap.h"
#include "Player.h"
#include "Enemy.h"
#include "Imatge.h"
#include "Sprite.h"


// Scene contains all the entities of our game.
// It is responsible for updating and render them.


class Scene
{

public:
	Scene();
	~Scene();

	void init();
	void update(int deltaTime, bool coop);
	void render(bool coop);
	//glm::ivec2 get_pos();
	int ret_nivell();
	void canviaNivell();
	bool guanyat();
	void recomençar();

private:
	void initShaders();
	

private:
	TileMap *map1,*map2;
	Player *player, *player2;
	Enemy *enemy0, *enemy1, *enemy2, *enemy3, *enemy4, *enemy5, *enemy6, *enemy7;
	Imatge *lvl1;
	Texture spritesheet;
	Sprite *sprite1, *sprite2;
	glm::ivec2 end;
	ShaderProgram texProgram;
	float currentTime;
	glm::mat4 projection;
	
	int nivell = 0;
	vector<TileMap*> fons;
	vector<TileMap*> mapa;
	vector<vector<vector<glm::ivec2>>> obertures1;
	vector<vector<vector<glm::ivec2>>> obertures2;
	vector<vector<int>> enemic;
	vector<vector<glm::ivec2>> posE;
	vector<glm::ivec2> finalP1;

	float temps = 10;
	bool next = false;
	bool prev = false;
	bool alter = false;
	int guardat = 0;
	bool winScreen = false;
};


#endif // _SCENE_INCLUDE

