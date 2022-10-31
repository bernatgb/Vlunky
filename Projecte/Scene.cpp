#include <iostream>
#include <cmath>
#include <glm/gtc/matrix_transform.hpp>
#include "Scene.h"
#include "Game.h"


#define SCREEN_X 0
#define SCREEN_Y 0

#define NIVELLS 15


Scene::Scene()
{
	map1 = NULL;
	map2 = NULL;
	player = NULL;
	player2 = NULL;	// COOP
	enemy0 = NULL;	// CHECK POINT
	enemy1 = NULL;	// PLATAFORMA
	enemy2 = NULL;
	enemy3 = NULL;
	enemy4 = NULL;
	enemy5 = NULL;
	enemy6 = NULL;
	enemy7 = NULL;
	lvl1 = NULL;
}

Scene::~Scene()
{
	if(map1 != NULL)
		delete map1;
	if (map2 != NULL)
		delete map2;
	if(player != NULL)
		delete player;
	if (player2 != NULL)
		delete player2;
	if (enemy0 != NULL)
		delete enemy0;
	if (enemy1 != NULL)
		delete enemy1;
	if (enemy2 != NULL)
		delete enemy2;
	if (enemy3 != NULL)
		delete enemy3;
	if (enemy4 != NULL)
		delete enemy4;
	if (enemy5 != NULL)
		delete enemy5;
	if (enemy6 != NULL)
		delete enemy6;
	if (enemy7 != NULL)
		delete enemy7;
	if (lvl1 != NULL)
		delete lvl1;
}


void Scene::init()
{
	initShaders();
	fons.resize(NIVELLS);
	mapa.resize(NIVELLS);
	obertures1.resize(NIVELLS);
	for (int lvl = 0; lvl < NIVELLS; ++lvl) {
		obertures1[lvl].resize(4);
		for (int j = 0; j < 4; ++j) {
			obertures1[lvl][j].resize(5);
			for (int k = 0; k < 5; ++k) {
				obertures1[lvl][j][k] = { -1,-1 };
			}
		}
	}
	obertures2.resize(NIVELLS);
	for (int lvl = 0; lvl < NIVELLS; ++lvl) {
		obertures2[lvl].resize(4);
		for (int j = 0; j < 4; ++j) {
			obertures2[lvl][j].resize(5);
			for (int k = 0; k < 5; ++k) {
				obertures1[lvl][j][k] = { -1,-1 };
			}
		}
	}
	finalP1.resize(NIVELLS);
	enemic.resize(NIVELLS);
	for (int lvl = 0; lvl < NIVELLS; ++lvl) {
		enemic[lvl].resize(8);
	}
	posE.resize(NIVELLS);
	for (int lvl = 0; lvl < NIVELLS; ++lvl) {
		posE[lvl].resize(8);
	}

	// INFORMACIÓ DELS NIVELLS
	
	for (int lvl = 0; lvl < 9; ++lvl) {
		fons[lvl] = TileMap::createTileMap("levels/Lvl-1-fons.txt", glm::vec2(SCREEN_X, SCREEN_Y), texProgram);
	}
	for (int lvl = 9; lvl < NIVELLS; ++lvl) {
		fons[lvl] = TileMap::createTileMap("levels/Lvl-2-fons.txt", glm::vec2(SCREEN_X, SCREEN_Y), texProgram);
	}

	mapa[0] = TileMap::createTileMap("levels/Lvl-1-1.txt", glm::vec2(SCREEN_X, SCREEN_Y), texProgram);
	mapa[1] = TileMap::createTileMap("levels/Lvl-1-2.txt", glm::vec2(SCREEN_X, SCREEN_Y), texProgram);
	mapa[2] = TileMap::createTileMap("levels/Lvl-1-3.txt", glm::vec2(SCREEN_X, SCREEN_Y), texProgram);
	mapa[3] = TileMap::createTileMap("levels/Lvl-1-4.txt", glm::vec2(SCREEN_X, SCREEN_Y), texProgram);
	mapa[4] = TileMap::createTileMap("levels/Lvl-1-5.txt", glm::vec2(SCREEN_X, SCREEN_Y), texProgram);
	mapa[5] = TileMap::createTileMap("levels/Lvl-1-6.txt", glm::vec2(SCREEN_X, SCREEN_Y), texProgram);
	mapa[6] = TileMap::createTileMap("levels/Lvl-1-7.txt", glm::vec2(SCREEN_X, SCREEN_Y), texProgram);
	mapa[7] = TileMap::createTileMap("levels/Lvl-1-8.txt", glm::vec2(SCREEN_X, SCREEN_Y), texProgram);
	mapa[8] = TileMap::createTileMap("levels/Lvl-1-9.txt", glm::vec2(SCREEN_X, SCREEN_Y), texProgram);

	mapa[9] = TileMap::createTileMap("levels/Lvl-2-1.txt", glm::vec2(SCREEN_X, SCREEN_Y), texProgram);
	mapa[10] = TileMap::createTileMap("levels/Lvl-2-2.txt", glm::vec2(SCREEN_X, SCREEN_Y), texProgram);
	mapa[11] = TileMap::createTileMap("levels/Lvl-2-3.txt", glm::vec2(SCREEN_X, SCREEN_Y), texProgram);
	mapa[12] = TileMap::createTileMap("levels/Lvl-2-4.txt", glm::vec2(SCREEN_X, SCREEN_Y), texProgram);
	mapa[13] = TileMap::createTileMap("levels/Lvl-2-5.txt", glm::vec2(SCREEN_X, SCREEN_Y), texProgram);
	mapa[14] = TileMap::createTileMap("levels/Lvl-2-6.txt", glm::vec2(SCREEN_X, SCREEN_Y), texProgram);
	

	obertures1[0][0][0] = { 0, 11 };
	obertures1[0][1][0] = { 10, 12 };
	obertures1[0][1][1] = { 11, 12 };
	obertures1[1][0][0] = { 1, 0 };
	obertures1[1][0][1] = { 2, 0 };
	obertures1[1][1][0] = { 14, 12 };
	obertures1[1][1][1] = { 15, 12 };
	obertures1[2][0][0] = { 1, 0 };
	obertures1[2][0][1] = { 2, 0 };
	obertures1[2][1][0] = { 16, 1 };
	obertures1[2][1][1] = { 16, 2 };
	obertures1[3][0][0] = { 0, 1 };
	obertures1[3][0][1] = { 0, 2 };
	obertures1[3][1][0] = { 4, 12 };
	obertures1[3][1][1] = { 5, 12 };
	obertures1[3][1][2] = { 6, 12 };
	obertures1[3][1][3] = { 7, 12 };
	obertures1[3][2][0] = { 16, 4 };
	obertures1[3][2][1] = { 16, 5 };
	obertures1[3][2][2] = { 16, 6 };
	obertures1[3][2][3] = { 16, 7 };
	obertures1[3][2][3] = { 16, 8 }; 
	obertures1[4][0][0] = { 4, 0 };
	obertures1[4][0][1] = { 5, 0 };
	obertures1[4][0][2] = { 6, 0 };
	obertures1[4][0][3] = { 7, 0 };
	obertures1[4][1][0] = { 16, 5 };
	obertures1[4][1][1] = { 16, 6 };
	obertures1[4][1][2] = { 16, 7 };
	obertures1[5][0][0] = { 0, 4 };
	obertures1[5][0][1] = { 0, 5 };
	obertures1[5][0][2] = { 0, 6 };
	obertures1[5][0][3] = { 0, 7 };
	obertures1[5][0][4] = { 0, 8 };
	obertures1[5][1][0] = { 7, 12 };
	obertures1[5][1][1] = { 8, 12 };
	obertures1[5][1][2] = { 9, 12 };
	obertures1[5][1][3] = { 10, 12 };
	obertures1[5][2][0] = { 16, 4 };
	obertures1[5][2][1] = { 16, 5 };
	obertures1[5][2][2] = { 16, 6 };
	obertures1[5][2][3] = { 16, 7 };
	obertures1[5][2][4] = { 16, 8 };
	obertures1[6][0][0] = { 7, 0 };
	obertures1[6][0][1] = { 8, 0 };
	obertures1[6][0][2] = { 9, 0 };
	obertures1[6][0][3] = { 10, 0 };
	obertures1[6][1][0] = { 16, 9 };
	obertures1[6][1][1] = { 16, 10 };
	obertures1[6][1][2] = { 16, 11 };
	obertures1[6][2][0] = { 0, 5 };
	obertures1[6][2][1] = { 0, 6 };
	obertures1[6][2][2] = { 0, 7 };

	obertures1[7][0][0] = { 0, 4 };  // ESQUERRA_CENTRE
	obertures1[7][0][1] = { 0, 5 };  // ESQUERRA_CENTRE
	obertures1[7][0][2] = { 0, 6 };  // ESQUERRA_CENTRE
	obertures1[7][0][3] = { 0, 7 };  // ESQUERRA_CENTRE
	obertures1[7][0][4] = { 0, 8 };  // ESQUERRA_CENTRE
	obertures1[7][1][0] = { 16, 2 };//DRETA_DALT
	obertures1[7][1][1] = { 16, 3 };//DRETA_DALT
	obertures1[7][2][0] = { 3, 12 };
	obertures1[7][2][1] = { 4, 12 };
	obertures1[7][2][2] = { 5, 12 };
	obertures1[7][3][0] = { 12, 12 };//DRETA_BAIX
	obertures1[7][3][1] = { 13, 12 };//DRETA_BAIX
	obertures1[7][3][2] = { 14, 12 };//DRETA_BAIX
	obertures1[7][3][3] = { 15, 12 };//DRETA_BAIX

	obertures1[8][0][0] = { 0, 9 };  // ESQUERRA_BAIX
	obertures1[8][0][1] = { 0, 10 };  // ESQUERRA_BAIX
	obertures1[8][0][2] = { 0, 11 };  // ESQUERRA_BAIX
	obertures1[8][2][0] = { 4, 0 };//DALT_ESQUERRA
	obertures1[8][2][1] = { 5, 0 };//DALT_ESQUERRA
	obertures1[8][2][2] = { 6, 0 };//DALT_ESQUERRA
	obertures1[8][3][0] = { 12, 0 };//DALT_DRETA
	obertures1[8][3][1] = { 13, 0 };//DALT_DRETA
	obertures1[8][3][2] = { 14, 0 };//DALT_DRETA
	obertures1[8][3][3] = { 15, 0 };//DALT_DRETA


	obertures2[0][0][0] = { 0, 1 };
	obertures2[0][0][1] = { 0, 2 };
	obertures2[0][1][0] = { 16, 10 };
	obertures2[0][1][1] = { 16, 11 };

	obertures2[1][0][0] = { 0, 5 };
	obertures2[1][0][1] = { 0, 6 };
	obertures2[1][1][0] = { 16, 10 };
	obertures2[1][1][1] = { 16, 11 };

	obertures2[2][0][0] = { 0, 1 };
	obertures2[2][0][1] = { 0, 2 };
	obertures2[2][1][0] = { 14, 12 };
	obertures2[2][1][1] = { 15, 12 };

	obertures2[3][0][0] = { 1, 0 };
	obertures2[3][0][1] = { 2, 0 };
	obertures2[3][1][0] = { 13, 12 };
	obertures2[3][1][1] = { 14, 12 };

	obertures2[4][0][0] = { 1, 0 };
	obertures2[4][0][1] = { 2, 0 };
	obertures2[4][1][0] = { 16, 11 };
	obertures2[4][1][1] = { 16, 10 };

	obertures2[5][0][0] = { 0, 11 };
	obertures2[5][0][1] = { 0, 10 };
	obertures2[5][1][0] = { 16, 11 };
	obertures2[5][1][1] = { 16, 10 };

	finalP1[0] = { 18, 5 };
	finalP1[1] = { 18, 5 };
	finalP1[2] = { 18, 5 };
	finalP1[3] = { 18, 5 };

	enemic[0][0] = 4;
	posE[0][0] = { 3, 11 };
	enemic[0][1] = -1;
	posE[0][1] = { -1, -1 };
	enemic[0][2] = -1;
	posE[0][2] = { -1, -1 };
	enemic[0][3] = -1;
	posE[0][3] = { -1, -1 };
	enemic[0][4] = -1;
	posE[0][4] = { -1, -1 };
	enemic[0][5] = -1;
	posE[0][5] = { -1, -1 };
	enemic[0][6] = -1;
	posE[0][6] = { -1, -1 };
	enemic[0][7] = -1;
	posE[0][7] = { -1, -1 };

	enemic[1][0] = -1;
	posE[1][0] = { -1, -1 };
	enemic[1][1] = -1;
	posE[1][1] = { -1, -1 };
	enemic[1][2] = 1;
	posE[1][2] = { 8, 9 };
	enemic[1][3] = -1;
	posE[1][3] = { -1, -1 };
	enemic[1][4] = -1;
	posE[1][4] = { -1, -1 };
	enemic[1][5] = -1;
	posE[1][5] = { -1, -1 };
	enemic[1][6] = -1;
	posE[1][6] = { -1, -1 };
	enemic[1][7] = -1;
	posE[1][7] = { -1, -1 };

	enemic[2][0] = -1;
	posE[2][0] = { -1, -1 };
	enemic[2][1] = 0;
	posE[2][1] = { 8, 10 };
	enemic[2][2] = 0;
	posE[2][2] = { 9, 10 };
	enemic[2][3] = -1;
	posE[2][3] = { -1, -1 };
	enemic[2][4] = -1;
	posE[2][4] = { -1, -1 };
	enemic[2][5] = -1;
	posE[2][5] = { -1, -1 };
	enemic[2][6] = -1;
	posE[2][6] = { -1, -1 };
	enemic[2][7] = -1;
	posE[2][7] = { -1, -1 };

	enemic[3][0] = 4;
	posE[3][0] = { 2, 8 };
	enemic[3][1] = 0;
	posE[3][1] = { 7, 9 };
	enemic[3][2] = 1;
	posE[3][2] = { 12, 7 };
	enemic[3][3] = -1;
	posE[3][3] = { -1, -1 };
	enemic[3][4] = -1;
	posE[3][4] = { -1, -1 };
	enemic[3][5] = -1;
	posE[3][5] = { -1, -1 };
	enemic[3][6] = -1;
	posE[3][6] = { -1, -1 };
	enemic[3][7] = -1;
	posE[3][7] = { -1, -1 };

	enemic[4][0] = -1;
	posE[4][0] = { -1, -1 };
	enemic[4][1] = -1;
	posE[4][1] = { -1, -1 };
	enemic[4][2] = -1;
	posE[4][2] = { -1, -1 };
	enemic[4][3] = -1;
	posE[4][3] = { -1, -1 };
	enemic[4][4] = -1;
	posE[4][4] = { -1, -1 };
	enemic[4][5] = -1;
	posE[4][5] = { -1, -1 };
	enemic[4][6] = -1;
	posE[4][6] = { -1, -1 };
	enemic[4][7] = -1;
	posE[4][7] = { -1, -1 };

	enemic[5][0] = -1;
	posE[5][0] = { -1, -1 };
	enemic[5][1] = -1;
	posE[5][1] = { -1, -1 };
	enemic[5][2] = 2;
	posE[5][2] = { 2, 9 };
	enemic[5][3] = 2;
	posE[5][3] = { 13, 9 };
	enemic[5][4] = 2;
	posE[5][4] = { 5, 9 };
	enemic[5][5] = -1;
	posE[5][5] = { -1, -1 };
	enemic[5][6] = -1;
	posE[5][6] = { -1, -1 };
	enemic[5][7] = -1;
	posE[5][7] = { -1, -1 };

	enemic[6][0] = 4;
	posE[6][0] = { 2, 11 };
	enemic[6][1] = -1;
	posE[6][1] = { -1, -1 };
	enemic[6][2] = 3;
	posE[6][2] = { 15, 11 };
	enemic[6][3] = 2;
	posE[6][3] = { 5, 11 };
	enemic[6][4] = -1;
	posE[6][4] = { -1, -1 };
	enemic[6][5] = -1;
	posE[6][5] = { -1, -1 };
	enemic[6][6] = -1;
	posE[6][6] = { -1, -1 };
	enemic[6][7] = -1;
	posE[6][7] = { -1, -1 };

	enemic[7][0] = -1;
	posE[7][0] = { -1, -1 };
	enemic[7][1] = -1;
	posE[7][1] = { 5, 4 };
	enemic[7][2] = 2;
	posE[7][2] = { 12, 5 };
	enemic[7][3] = 0;
	posE[7][3] = { 5, 4 };
	enemic[7][4] = -1;
	posE[7][4] = { -1, -1 };
	enemic[7][5] = -1;
	posE[7][5] = { -1, -1 };
	enemic[7][6] = -1;
	posE[7][6] = { -1, -1 };
	enemic[7][7] = -1;
	posE[7][7] = { -1, -1 };

	enemic[8][0] = -1;
	posE[8][0] = { -1, -1 };
	enemic[8][1] = -1;
	posE[8][1] = { -1, -1 };
	enemic[8][2] = 2;
	posE[8][2] = { 9, 11 };
	enemic[8][3] = 3;
	posE[8][3] = { 15, 11 };
	enemic[8][4] = -1;
	posE[8][4] = { -1, -1 };
	enemic[8][5] = -1;
	posE[8][5] = { -1, -1 };
	enemic[8][6] = -1;
	posE[8][6] = { -1, -1 };
	enemic[8][7] = -1;
	posE[8][7] = { -1, -1 };

	enemic[9][0] = 4;
	posE[9][0] = { 1, 2 };
	enemic[9][1] = 0;
	posE[9][1] = { 5, 3 };
	enemic[9][2] = 3;
	posE[9][2] = { 9, 2 };
	enemic[9][3] = 3;
	posE[9][3] = { 13, 2 };
	enemic[9][4] = 1;
	posE[9][4] = { 13, 5 };
	enemic[9][5] = -1;
	posE[9][5] = { -1, -1 };
	enemic[9][6] = -1;
	posE[9][6] = { -1, -1 };
	enemic[9][7] = -1;
	posE[9][7] = { -1, -1 };

	enemic[10][0] = -1;
	posE[10][0] = { -1, -1 };
	enemic[10][1] = -1;
	posE[10][1] = { -1, -1 };
	enemic[10][2] = 2;
	posE[10][2] = { 6, 7 };
	enemic[10][3] = 2;
	posE[10][3] = { 8, 7 };
	enemic[10][4] = 2;
	posE[10][4] = { 12, 9 };
	enemic[10][5] = -1;
	posE[10][5] = { -1, -1 };
	enemic[10][6] = -1;
	posE[10][6] = { -1, -1 };
	enemic[10][7] = -1;
	posE[10][7] = { -1, -1 };

	enemic[11][0] = -1;
	posE[11][0] = { -1, -1 };
	enemic[11][1] = -1;
	posE[11][1] = { -1, -1 };
	enemic[11][2] = -1;
	posE[11][2] = { -1, -1 };
	enemic[11][3] = -1;
	posE[11][3] = { -1, -1 };
	enemic[11][4] = -1;
	posE[11][4] = { -1, -1 };
	enemic[11][5] = -1;
	posE[11][5] = { -1, -1 };
	enemic[11][6] = -1;
	posE[11][6] = { -1, -1 };
	enemic[11][7] = -1;
	posE[11][7] = { -1, -1 };

	enemic[12][0] = -1;
	posE[12][0] = { -1, -1 };
	enemic[12][1] = -1;
	posE[12][1] = { -1, -1 };
	enemic[12][2] = 2;
	posE[12][2] = { 8, 5 };
	enemic[12][3] = -1;
	posE[12][3] = { -1, -1 };
	enemic[12][4] = -1;
	posE[12][4] = { -1, -1 };
	enemic[12][5] = -1;
	posE[12][5] = { -1, -1 };
	enemic[12][6] = -1;
	posE[12][6] = { -1, -1 };
	enemic[12][7] = -1;
	posE[12][7] = { -1, -1 };

	enemic[13][0] = 4;
	posE[13][0] = { 3, 11 };
	enemic[13][1] = -1;
	posE[13][1] = { -1, -1 };
	enemic[13][2] = 2;
	posE[13][2] = { 7, 8 };
	enemic[13][3] = 2;
	posE[13][3] = { 10, 8 };
	enemic[13][4] = -1;
	posE[13][4] = { -1, -1 };
	enemic[13][5] = -1;
	posE[13][5] = { -1, -1 };
	enemic[13][6] = -1;
	posE[13][6] = { -1, -1 };
	enemic[13][7] = -1;
	posE[13][7] = { -1, -1 };

	enemic[14][0] = 4;
	posE[14][0] = { 1, 11 };
	enemic[14][3] = 5;
	posE[14][3] = { 15, 11 };
	enemic[14][2] = 0;
	posE[14][2] = { 5, 7 };
	enemic[14][1] = 0;
	posE[14][1] = { 14, 7 };
	enemic[14][4] = -1;
	posE[14][4] = { 14, 10 };
	enemic[14][5] = 1;
	posE[14][5] = { 4, 11 };
	enemic[14][6] = 2;
	posE[14][6] = { 8, 4 };
	enemic[14][7] = 3;
	posE[14][7] = { 9, 12 };


	// INICIA EL PRIMER NIVELL
	nivell = 0;

	map1 = fons[0];
	map2 = mapa[0];

	player = new Player();
	player->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, true);
	player->setInitPos({ obertures1[nivell][0][0].x + 1, obertures1[nivell][0][0].y });
	player->setPosition(glm::vec2((obertures1[nivell][0][0].x + 1) * map2->getTileSize(), obertures1[nivell][0][0].y * map2->getTileSize()));
	player->setTileMap(map2);

	player2 = new Player();
	player2->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, false);
	player2->setInitPos({ obertures1[nivell][0][0].x + 1, obertures1[nivell][0][0].y});
	player2->setPosition(glm::vec2((obertures1[nivell][0][0].x + 1) * map2->getTileSize(), obertures1[nivell][0][0].y * map2->getTileSize()));
	player2->setTileMap(map2);

	if (enemic[nivell][0] != -1) {
		enemy0 = new Enemy();
		enemy0->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][0]);
		enemy0->setPosition(glm::vec2(posE[nivell][0].x * map2->getTileSize(), posE[nivell][0].y * map2->getTileSize()));
		enemy0->setTileMap(map2);
	}

	if (enemic[nivell][1] != -1) {
		enemy1 = new Enemy();
		enemy1->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[0][1]);
		enemy1->setPosition(glm::vec2(posE[nivell][1].x * map2->getTileSize(), posE[nivell][1].y * map2->getTileSize()));
		enemy1->setTileMap(map2);
	}

	if (enemic[nivell][2] != -1) {
		enemy2 = new Enemy();
		enemy2->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[0][2]);
		enemy2->setPosition(glm::vec2(posE[nivell][2].x * map2->getTileSize(), posE[nivell][2].y * map2->getTileSize()));
		enemy2->setTileMap(map2);
	}

	if (enemic[nivell][3] != -1) {
		enemy3 = new Enemy();
		enemy3->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[0][3]);
		enemy3->setPosition(glm::vec2(posE[nivell][3].x * map2->getTileSize(), posE[nivell][3].y * map2->getTileSize()));
		enemy3->setTileMap(map2);
	}


	projection = glm::ortho(0.f, float(SCREEN_WIDTH - 1), float(SCREEN_HEIGHT - 1), 0.f);
	currentTime = 0.0f;
}

void Scene::update(int deltaTime, bool coop)
{
	currentTime += deltaTime;
	player->update(deltaTime, false, player);
	if (coop) player2->update(deltaTime, true, player);

	int xP1, yP1, xP2, yP2, ii, jj;
	jj = 0;
	player->ret_pos(xP1, yP1);
	if (coop) player2->ret_pos(xP2, yP2);
	else xP2 = yP2 = -1;
	xP1 = (xP1+32) / 64;
	yP1 = (yP1+32) / 64;
	xP2 = (xP2 / 64);
	yP2 = (yP2 / 64);

	if (nivell < 9) {
		for (int i = 0; i < obertures1[nivell].size(); ++i) {
			for (int j = 0; j < obertures1[nivell][i].size(); ++j) {
				if (obertures1[nivell][i][j].x != -1) {
					if (xP1 == obertures1[nivell][i][j].x && yP1 == obertures1[nivell][i][j].y || xP2 == obertures1[nivell][i][j].x && yP2 == obertures1[nivell][i][j].y) {
						if (i == 0) {
							ii = i;
							jj = j;
							prev = true;
						}
						else if (i == 1) {
							ii = i;
							jj = j;
							next = true;
						}
						else {
							ii = i;
							jj = j;
							alter = true;
						}
					}
				}
			}
		}
	}
	else {
		int niv = nivell - 9;
		for (int i = 0; i < obertures2[niv].size(); ++i) {
			for (int j = 0; j < obertures2[niv][i].size(); ++j) {
				if (obertures2[niv][i][j].x != -1) {
					if (xP1 == obertures2[niv][i][j].x && yP1 == obertures2[niv][i][j].y) {
						if (i == 0) {
							ii = i;
							jj = j;
							prev = true;
						}
						else if (i == 1) {
							ii = i;
							jj = j;
							next = true;
						}
						else {
							ii = i;
							jj = j;
							alter = true;
						}
					}
				}
			}
		}
	}
	
	if (next) {
		next = false;
		ii = 0;
		if (nivell == 6) {
			nivell = 8;
		}
		else if (nivell == 7) {
			nivell = 9;
		}
		else if (nivell == 4) {
			nivell = 6;
			ii = 2;
		}
		else if (nivell < NIVELLS-1) 
			++nivell;
		else 
			winScreen = true;
		
		/*if (nivell > -1) {
			win = true;
		}*/

		initShaders();
		
		map1 = fons[nivell];
		map2 = mapa[nivell];
		
		int despX, despY, obX, obY;
		despX = despY = obX = obY = 0;

		if (nivell < 9) {
			if (obertures1[nivell][ii][0].x == 0) obX = +1;
			if (obertures1[nivell][ii][0].y == 0) obY = +1;
			if (obertures1[nivell][ii][0].x == 16) obX = -1;
			if (obertures1[nivell][ii][0].y == 12) obY = -1;

			if (obertures1[nivell][0][0].x == 0) despX = +1;
			if (obertures1[nivell][0][0].y == 0) despY = +1;
			if (obertures1[nivell][0][0].x == 16) despX = -1;
			if (obertures1[nivell][0][0].y == 12) despY = -1;

			player->setPosition(glm::vec2((obertures1[nivell][ii][jj].x + obX) * map2->getTileSize(), (obertures1[nivell][ii][jj].y + obY) * map2->getTileSize()));
			player->setTileMap(map2);
			player2->setPosition(glm::vec2((obertures1[nivell][ii][jj].x + obX) * map2->getTileSize(), (obertures1[nivell][ii][jj].y + obY) * map2->getTileSize()));
			player2->setTileMap(map2);
		}
		else {
			int niv = nivell - 9;
			if (obertures2[niv][ii][0].x == 0) obX = +1;
			if (obertures2[niv][ii][0].y == 0) obY = +1;
			if (obertures2[niv][ii][0].x == 16) obX = -1;
			if (obertures2[niv][ii][0].y == 12) obY = -1;

			if (obertures2[niv][0][0].x == 0) despX = +1;
			if (obertures2[niv][0][0].y == 0) despY = +1;
			if (obertures2[niv][0][0].x == 16) despX = -1;
			if (obertures2[niv][0][0].y == 12) despY = -1;


			player->setPosition(glm::vec2((obertures2[niv][ii][jj].x + obX) * map2->getTileSize(), (obertures2[niv][ii][jj].y + obY) * map2->getTileSize()));
			player->setTileMap(map2);
			player2->setPosition(glm::vec2((obertures2[niv][ii][jj].x + obX) * map2->getTileSize(), (obertures2[niv][ii][jj].y + obY) * map2->getTileSize()));
			player2->setTileMap(map2);
		}
		
		if (enemic[nivell][0] != -1) {
			enemy0 = new Enemy();
			enemy0->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][0]);
			enemy0->setPosition(glm::vec2(posE[nivell][0].x * map2->getTileSize(), posE[nivell][0].y * map2->getTileSize()));
			enemy0->setTileMap(map2);
		}

		if (enemic[nivell][1] != -1) {
			enemy1 = new Enemy();
			enemy1->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][1]);
			enemy1->setPosition(glm::vec2(posE[nivell][1].x * map2->getTileSize(), posE[nivell][1].y * map2->getTileSize() + 32));
			enemy1->setTileMap(map2);
		}

		if (enemic[nivell][2] != -1) {
			enemy2 = new Enemy();
			enemy2->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][2]);
			if (enemic[nivell][2] == 0) enemy2->setPosition(glm::vec2(posE[nivell][2].x * map2->getTileSize(), posE[nivell][2].y * map2->getTileSize() + 32));
			else enemy2->setPosition(glm::vec2(posE[nivell][2].x * map2->getTileSize(), posE[nivell][2].y * map2->getTileSize()));
			enemy2->setTileMap(map2);
		}

		if (enemic[nivell][3] != -1) {
			enemy3 = new Enemy();
			enemy3->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][3]);
			enemy3->setPosition(glm::vec2(posE[nivell][3].x * map2->getTileSize(), posE[nivell][3].y * map2->getTileSize()));
			enemy3->setTileMap(map2);
		}

		if (enemic[nivell][4] != -1) {
			enemy4 = new Enemy();
			enemy4->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][4]);
			enemy4->setPosition(glm::vec2(posE[nivell][4].x * map2->getTileSize(), posE[nivell][4].y * map2->getTileSize()));
			enemy4->setTileMap(map2);
		}

		if (enemic[nivell][5] != -1) {
			enemy5 = new Enemy();
			enemy5->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][5]);
			enemy5->setPosition(glm::vec2(posE[nivell][5].x * map2->getTileSize(), posE[nivell][5].y * map2->getTileSize()));
			enemy5->setTileMap(map2);
		}

		if (enemic[nivell][6] != -1) {
			enemy6 = new Enemy();
			enemy6->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][6]);
			enemy6->setPosition(glm::vec2(posE[nivell][6].x * map2->getTileSize(), posE[nivell][6].y * map2->getTileSize()));
			enemy6->setTileMap(map2);
		}

		if (enemic[nivell][7] != -1) {
			enemy7 = new Enemy();
			enemy7->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][7]);
			enemy7->setPosition(glm::vec2(posE[nivell][7].x * map2->getTileSize(), posE[nivell][7].y * map2->getTileSize()));
			enemy7->setTileMap(map2);
		}

		projection = glm::ortho(0.f, float(SCREEN_WIDTH - 1), float(SCREEN_HEIGHT - 1), 0.f);
		currentTime = 0.0f;
	}

	if (prev) {
		prev = false;
		ii = 1;
		if (nivell == 5) {
			nivell = 3;
			ii = 2;
		}
		else if (nivell == 7) {
			nivell = 5;
			ii = 2;
		}
		else if (nivell > 0 && nivell != 9) 
			--nivell;
		else {
			ii = 0;
		}
			
		initShaders();

		map1 = fons[nivell];
		map2 = mapa[nivell];

		int despX, despY, obX, obY;
		despX = despY = obX = obY = 0;

		if (nivell < 9) {
			if (obertures1[nivell][ii][0].x == 0) obX = +1;
			if (obertures1[nivell][ii][0].y == 0) obY = +1;
			if (obertures1[nivell][ii][0].x == 16) obX = -1;
			if (obertures1[nivell][ii][0].y == 12) obY = -2;

			if (obertures1[nivell][0][0].x == 0) despX = +1;
			if (obertures1[nivell][0][0].y == 0) despY = +1;
			if (obertures1[nivell][0][0].x == 16) despX = -1;
			if (obertures1[nivell][0][0].y == 12) despY = -1;

			player->setInitPos({ obertures1[nivell][0][0].x + despX, obertures1[nivell][0][0].y + despY });
			player->setPosition(glm::vec2((obertures1[nivell][ii][jj].x + obX) * map2->getTileSize(), (obertures1[nivell][ii][jj].y + obY) * map2->getTileSize()));
			player->setTileMap(map2);
			player2->setPosition(glm::vec2((obertures1[nivell][ii][jj].x + obX) * map2->getTileSize(), (obertures1[nivell][ii][jj].y + obY) * map2->getTileSize()));
			player2->setTileMap(map2);
		}
		else {
			int niv = nivell - 9;
			if (obertures2[niv][ii][0].x == 0) obX = +1;
			if (obertures2[niv][ii][0].y == 0) obY = +1;
			if (obertures2[niv][ii][0].x == 16) obX = -1;
			if (obertures2[niv][ii][0].y == 12) obY = -2;

			if (obertures2[niv][0][0].x == 0) despX = +1;
			if (obertures2[niv][0][0].y == 0) despY = +1;
			if (obertures2[niv][0][0].x == 16) despX = -1;
			if (obertures2[niv][0][0].y == 12) despY = -1;

			player->setPosition(glm::vec2((obertures2[niv][ii][jj].x + obX) * map2->getTileSize(), (obertures2[niv][ii][jj].y + obY) * map2->getTileSize()));
			player->setTileMap(map2);
			player2->setPosition(glm::vec2((obertures2[niv][ii][jj].x + obX) * map2->getTileSize(), (obertures2[niv][ii][jj].y + obY) * map2->getTileSize()));
			player2->setTileMap(map2);
		}

		if (enemic[nivell][0] != -1) {
			enemy0 = new Enemy();
			enemy0->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][0]);
			enemy0->setPosition(glm::vec2(posE[nivell][0].x * map2->getTileSize(), posE[nivell][0].y * map2->getTileSize()));
			enemy0->setTileMap(map2);
		}

		if (enemic[nivell][1] != -1) {
			enemy1 = new Enemy();
			enemy1->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][1]);
			enemy1->setPosition(glm::vec2(posE[nivell][1].x * map2->getTileSize(), posE[nivell][1].y * map2->getTileSize() + 32));
			enemy1->setTileMap(map2);
		}

		if (enemic[nivell][2] != -1) {
			enemy2 = new Enemy();
			enemy2->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][2]);
			if (enemic[nivell][2] == 0) enemy2->setPosition(glm::vec2(posE[nivell][2].x * map2->getTileSize(), posE[nivell][2].y * map2->getTileSize() + 32));
			else enemy2->setPosition(glm::vec2(posE[nivell][2].x * map2->getTileSize(), posE[nivell][2].y * map2->getTileSize()));
			enemy2->setTileMap(map2);
		}

		if (enemic[nivell][3] != -1) {
			enemy3 = new Enemy();
			enemy3->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][3]);
			enemy3->setPosition(glm::vec2(posE[nivell][3].x * map2->getTileSize(), posE[nivell][3].y * map2->getTileSize()));
			enemy3->setTileMap(map2);
		}

		if (enemic[nivell][4] != -1) {
			enemy4 = new Enemy();
			enemy4->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][4]);
			enemy4->setPosition(glm::vec2(posE[nivell][4].x * map2->getTileSize(), posE[nivell][4].y * map2->getTileSize()));
			enemy4->setTileMap(map2);
		}

		if (enemic[nivell][5] != -1) {
			enemy5 = new Enemy();
			enemy5->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][5]);
			enemy5->setPosition(glm::vec2(posE[nivell][5].x * map2->getTileSize(), posE[nivell][5].y * map2->getTileSize()));
			enemy5->setTileMap(map2);
		}

		if (enemic[nivell][6] != -1) {
			enemy6 = new Enemy();
			enemy6->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][6]);
			enemy6->setPosition(glm::vec2(posE[nivell][6].x * map2->getTileSize(), posE[nivell][6].y * map2->getTileSize()));
			enemy6->setTileMap(map2);
		}

		if (enemic[nivell][7] != -1) {
			enemy7 = new Enemy();
			enemy7->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][7]);
			enemy7->setPosition(glm::vec2(posE[nivell][7].x * map2->getTileSize(), posE[nivell][7].y * map2->getTileSize()));
			enemy7->setTileMap(map2);
		}

		projection = glm::ortho(0.f, float(SCREEN_WIDTH - 1), float(SCREEN_HEIGHT - 1), 0.f);
		currentTime = 0.0f;
	}

	if (alter) {
		next = false;
		int entra = 0;
		if (nivell == 5) {
			nivell = 7;
			entra = 0;
		}
		else if (nivell == 3) {
			nivell = 5;
			entra = 0;
		}
		else if (nivell == 6) {
			nivell = 4;
			entra = 1;
		}
		else if (nivell == 7) {
			nivell = 8;
			entra = ii;
		}
		else if (nivell == 8) {
			nivell = 7;
			entra = ii;
		}

		initShaders();

		map1 = fons[nivell];
		map2 = mapa[nivell];

		int despX, despY, obX, obY;
		despX = despY = obX = obY = 0;

		if (obertures1[nivell][entra][0].x == 0) obX = +1;
		if (obertures1[nivell][entra][0].y == 0) obY = +1;
		if (obertures1[nivell][entra][0].x == 16) obX = -1;
		if (obertures1[nivell][entra][0].y == 12) obY = -1;

		if (obertures1[nivell][0][0].x == 0) despX = +1;
		if (obertures1[nivell][0][0].y == 0) despY = +1;
		if (obertures1[nivell][0][0].x == 16) despX = -1;
		if (obertures1[nivell][0][0].y == 12) despY = -1;

		player->setPosition(glm::vec2((obertures1[nivell][entra][jj].x + obX) * map2->getTileSize(), (obertures1[nivell][entra][jj].y + obY) * map2->getTileSize()));
		player->setTileMap(map2);
		player2->setPosition(glm::vec2((obertures1[nivell][entra][jj].x + obX) * map2->getTileSize(), (obertures1[nivell][entra][jj].y + obY) * map2->getTileSize()));
		player2->setTileMap(map2);

		if (enemic[nivell][0] != -1) {
			enemy0 = new Enemy();
			enemy0->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][0]);
			enemy0->setPosition(glm::vec2(posE[nivell][0].x * map2->getTileSize(), posE[nivell][0].y * map2->getTileSize()));
			enemy0->setTileMap(map2);
		}

		if (enemic[nivell][1] != -1) {
			enemy1 = new Enemy();
			enemy1->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][1]);
			enemy1->setPosition(glm::vec2(posE[nivell][1].x * map2->getTileSize(), posE[nivell][1].y * map2->getTileSize() + 32));
			enemy1->setTileMap(map2);
		}

		if (enemic[nivell][2] != -1) {
			enemy2 = new Enemy();
			enemy2->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][2]);
			if (enemic[nivell][2] == 0) enemy2->setPosition(glm::vec2(posE[nivell][2].x * map2->getTileSize(), posE[nivell][2].y * map2->getTileSize() + 32));
			else enemy2->setPosition(glm::vec2(posE[nivell][2].x * map2->getTileSize(), posE[nivell][2].y * map2->getTileSize()));
			enemy2->setTileMap(map2);
		}

		if (enemic[nivell][3] != -1) {
			enemy3 = new Enemy();
			enemy3->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][3]);
			enemy3->setPosition(glm::vec2(posE[nivell][3].x * map2->getTileSize(), posE[nivell][3].y * map2->getTileSize()));
			enemy3->setTileMap(map2);
		}

		if (enemic[nivell][4] != -1) {
			enemy4 = new Enemy();
			enemy4->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][4]);
			enemy4->setPosition(glm::vec2(posE[nivell][4].x * map2->getTileSize(), posE[nivell][4].y * map2->getTileSize()));
			enemy4->setTileMap(map2);
		}

		if (enemic[nivell][5] != -1) {
			enemy5 = new Enemy();
			enemy5->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][5]);
			enemy5->setPosition(glm::vec2(posE[nivell][5].x * map2->getTileSize(), posE[nivell][5].y * map2->getTileSize()));
			enemy5->setTileMap(map2);
		}

		if (enemic[nivell][6] != -1) {
			enemy6 = new Enemy();
			enemy6->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][6]);
			enemy6->setPosition(glm::vec2(posE[nivell][6].x * map2->getTileSize(), posE[nivell][6].y * map2->getTileSize()));
			enemy6->setTileMap(map2);
		}

		if (enemic[nivell][7] != -1) {
			enemy7 = new Enemy();
			enemy7->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][7]);
			enemy7->setPosition(glm::vec2(posE[nivell][7].x * map2->getTileSize(), posE[nivell][7].y * map2->getTileSize()));
			enemy7->setTileMap(map2);
		}

		projection = glm::ortho(0.f, float(SCREEN_WIDTH - 1), float(SCREEN_HEIGHT - 1), 0.f);
		currentTime = 0.0f;
	}
	
	if (player->ret_tornat() == true || player2->ret_tornat() == true) {
		player->jaTornat();
		player2->jaTornat();
		
		nivell = guardat;

		map1 = fons[nivell];
		map2 = mapa[nivell];

		player->setInitPos({ posE[guardat][0].x, posE[guardat][0].y });
		player->setPosition(glm::vec2(posE[guardat][0].x * map2->getTileSize(), posE[guardat][0].y * map2->getTileSize()));
		player->setTileMap(map2);
		player2->setInitPos({ posE[guardat][0].x, posE[guardat][0].y });
		player2->setPosition(glm::vec2(posE[guardat][0].x * map2->getTileSize(), posE[guardat][0].y * map2->getTileSize()));
		player2->setTileMap(map2);

		if (enemic[nivell][0] != -1) {
			enemy0 = new Enemy();
			enemy0->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][0]);
			enemy0->setPosition(glm::vec2(posE[nivell][0].x * map2->getTileSize(), posE[nivell][0].y * map2->getTileSize()));
			enemy0->setTileMap(map2);
		}

		if (enemic[nivell][1] != -1) {
			enemy1 = new Enemy();
			enemy1->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][1]);
			enemy1->setPosition(glm::vec2(posE[nivell][1].x * map2->getTileSize(), posE[nivell][1].y * map2->getTileSize() + 32));
			enemy1->setTileMap(map2);
		}

		if (enemic[nivell][2] != -1) {
			enemy2 = new Enemy();
			enemy2->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][2]);
			if (enemic[nivell][2] == 0) enemy2->setPosition(glm::vec2(posE[nivell][2].x * map2->getTileSize(), posE[nivell][2].y * map2->getTileSize() + 32));
			else enemy2->setPosition(glm::vec2(posE[nivell][2].x * map2->getTileSize(), posE[nivell][2].y * map2->getTileSize()));
			enemy2->setTileMap(map2);
		}

		if (enemic[nivell][3] != -1) {
			enemy3 = new Enemy();
			enemy3->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][3]);
			enemy3->setPosition(glm::vec2(posE[nivell][3].x * map2->getTileSize(), posE[nivell][3].y * map2->getTileSize()));
			enemy3->setTileMap(map2);
		}

		if (enemic[nivell][4] != -1) {
			enemy4 = new Enemy();
			enemy4->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][4]);
			enemy4->setPosition(glm::vec2(posE[nivell][4].x * map2->getTileSize(), posE[nivell][4].y * map2->getTileSize()));
			enemy4->setTileMap(map2);
		}

		if (enemic[nivell][5] != -1) {
			enemy5 = new Enemy();
			enemy5->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][5]);
			enemy5->setPosition(glm::vec2(posE[nivell][5].x * map2->getTileSize(), posE[nivell][5].y * map2->getTileSize()));
			enemy5->setTileMap(map2);
		}

		if (enemic[nivell][6] != -1) {
			enemy6 = new Enemy();
			enemy6->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][6]);
			enemy6->setPosition(glm::vec2(posE[nivell][6].x * map2->getTileSize(), posE[nivell][6].y * map2->getTileSize()));
			enemy6->setTileMap(map2);
		}

		if (enemic[nivell][7] != -1) {
			enemy7 = new Enemy();
			enemy7->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, enemic[nivell][7]);
			enemy7->setPosition(glm::vec2(posE[nivell][7].x * map2->getTileSize(), posE[nivell][7].y * map2->getTileSize()));
			enemy7->setTileMap(map2);
		}

		projection = glm::ortho(0.f, float(SCREEN_WIDTH - 1), float(SCREEN_HEIGHT - 1), 0.f);
		currentTime = 0.0f;
	}

	if (enemic[nivell][0] != -1) {
		enemy0->update(deltaTime, enemic[nivell][0], player, player2, 0);
		if (enemy0->ret_activat() == true) {
			guardat = nivell;
			enemy0->jaActivat();
		}
	}


	if (enemic[nivell][1] != -1) 
		enemy1->update(deltaTime, enemic[nivell][1], player, player2, 0);

	if (enemic[nivell][2] != -1) 
		enemy2->update(deltaTime, enemic[nivell][2], player, player2, 1);

	if (enemic[nivell][3] != -1) 
		enemy3->update(deltaTime, enemic[nivell][3], player, player2, 2);

	if (enemic[nivell][4] != -1)
		enemy4->update(deltaTime, enemic[nivell][4], player, player2, 0);

	if (enemic[nivell][5] != -1)
		enemy5->update(deltaTime, enemic[nivell][5], player, player2, 0);

	if (enemic[nivell][6] != -1)
		enemy6->update(deltaTime, enemic[nivell][6], player, player2, 0);

	if (enemic[nivell][7] != -1)
		enemy7->update(deltaTime, enemic[nivell][7], player, player2, 0);


	bool next = prev = alter = false;
}

void Scene::render(bool coop)
{
	glm::mat4 modelview;

	texProgram.use();
	texProgram.setUniformMatrix4f("projection", projection);
	texProgram.setUniform4f("color", 1.0f, 1.0f, 1.0f, 1.0f);
	modelview = glm::mat4(1.0f);
	texProgram.setUniformMatrix4f("modelview", modelview);
	texProgram.setUniform2f("texCoordDispl", 0.f, 0.f);
	map1->render();
	map2->render();

	if (enemic[nivell][0] != -1)
		enemy0->render();

	player->render();

	if (coop)
		player2->render();

	if (enemic[nivell][1] != -1)
		enemy1->render();

	if (enemic[nivell][2] != -1)
		enemy2->render();

	if (enemic[nivell][3] != -1)
		enemy3->render();

	if (enemic[nivell][4] != -1)
		enemy4->render();

	if (enemic[nivell][5] != -1)
		enemy5->render();

	if (enemic[nivell][6] != -1)
		enemy6->render();

	if (enemic[nivell][7] != -1)
		enemy7->render();
}

void Scene::initShaders()
{
	Shader vShader, fShader;

	vShader.initFromFile(VERTEX_SHADER, "shaders/texture.vert");
	if(!vShader.isCompiled())
	{
		cout << "Vertex Shader Error" << endl;
		cout << "" << vShader.log() << endl << endl;
	}
	fShader.initFromFile(FRAGMENT_SHADER, "shaders/texture.frag");
	if(!fShader.isCompiled())
	{
		cout << "Fragment Shader Error" << endl;
		cout << "" << fShader.log() << endl << endl;
	}
	texProgram.init();
	texProgram.addShader(vShader);
	texProgram.addShader(fShader);
	texProgram.link();
	if(!texProgram.isLinked())
	{
		cout << "Shader Linking Error" << endl;
		cout << "" << texProgram.log() << endl << endl;
	}
	texProgram.bindFragmentOutput("outColor");
	vShader.free();
	fShader.free();
}

int Scene::ret_nivell()
{
	return nivell;
}

void Scene::canviaNivell()
{
	next = true;
}

bool Scene::guanyat()
{
	return winScreen;
}