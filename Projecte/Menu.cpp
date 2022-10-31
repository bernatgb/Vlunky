#include <iostream>
#include <cmath>
#include <glm/gtc/matrix_transform.hpp>
#include "Menu.h"
#include "Game.h"


Menu::Menu()
{
	map = NULL;
	mainMenu = NULL;
	instruccions = NULL;
	credits = NULL;
	pic = NULL;
	win = NULL;
}

Menu::~Menu()
{
	if (map != NULL)
		delete map;
	if (mainMenu != NULL)
		delete mainMenu;
	if (instruccions != NULL)
		delete instruccions;
	if (credits != NULL)
		delete credits;
	if (pic != NULL)
		delete pic;
	if (win != NULL)
		delete win;
}


void Menu::init()
{
	initShaders();
	map = TileMap::createTileMap("levels/L1.txt", glm::vec2(0, 0), texProgram);

	mainMenu = new Imatge();
	mainMenu->init(glm::ivec2(0, 0), texProgram, 0);
	mainMenu->setPosition(glm::vec2(0, 0));
	mainMenu->setTileMap(map);


	instruccions = new Imatge();
	instruccions->init(glm::ivec2(0, 0), texProgram, 1);
	instruccions->setPosition(glm::vec2(0, 0));
	instruccions->setTileMap(map);

	credits = new Imatge();
	credits->init(glm::ivec2(0, 0), texProgram, 2);
	credits->setPosition(glm::vec2(0, 0));
	credits->setTileMap(map);

	pic = new Imatge();
	pic->init(glm::ivec2(0, 0), texProgram, 3);
	pic->setPosition(glm::vec2(80, 50));
	pic->setTileMap(map);

	win = new Imatge();
	win->init(glm::ivec2(0, 0), texProgram, 4);
	win->setPosition(glm::vec2(0, 0));
	win->setTileMap(map);

	projection = glm::ortho(0.f, float(SCREEN_WIDTH - 1), float(SCREEN_HEIGHT - 1), 0.f);
	currentTime = 0.0f;
}

void Menu::update(int deltaTime, int op)
{
	currentTime += deltaTime;

	pic->update(deltaTime, 3, op);
}

void Menu::render(int opcio)
{
	glm::mat4 modelview;

	texProgram.use();
	texProgram.setUniformMatrix4f("projection", projection);
	texProgram.setUniform4f("color", 1.0f, 1.0f, 1.0f, 1.0f);
	modelview = glm::mat4(1.0f);
	texProgram.setUniformMatrix4f("modelview", modelview);
	texProgram.setUniform2f("texCoordDispl", 0.f, 0.f);
	
	map->render();

	if (opcio == 0) {
		mainMenu->render();
		pic->render();
	}
	else if (opcio == 1)
		instruccions->render();
	else if (opcio == 2)
		credits->render();
	else if (opcio == 3)
		win->render();
}

void Menu::initShaders()
{
	Shader vShader, fShader;

	vShader.initFromFile(VERTEX_SHADER, "shaders/texture.vert");
	if (!vShader.isCompiled())
	{
		cout << "Vertex Shader Error" << endl;
		cout << "" << vShader.log() << endl << endl;
	}
	fShader.initFromFile(FRAGMENT_SHADER, "shaders/texture.frag");
	if (!fShader.isCompiled())
	{
		cout << "Fragment Shader Error" << endl;
		cout << "" << fShader.log() << endl << endl;
	}
	texProgram.init();
	texProgram.addShader(vShader);
	texProgram.addShader(fShader);
	texProgram.link();
	if (!texProgram.isLinked())
	{
		cout << "Shader Linking Error" << endl;
		cout << "" << texProgram.log() << endl << endl;
	}
	texProgram.bindFragmentOutput("outColor");
	vShader.free();
	fShader.free();
}