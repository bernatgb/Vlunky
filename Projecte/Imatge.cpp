#include <cmath>
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include "Player.h"
#include "Game.h"


enum ImatgeAnims
{
	I1, I2, I3, I4
};


void Imatge::init(const glm::ivec2 &tileMapPos, ShaderProgram &shaderProgram, int imatge)
{
	ops.resize(4);
	ops[0] = 286;
	ops[1] = 350;
	ops[2] = 414;
	ops[3] = 478;

	switch (imatge) {
	case 0:
		spritesheet.loadFromFile("images/Main_menu.jpg", TEXTURE_PIXEL_FORMAT_RGBA);
		sprite = Sprite::createSprite(glm::ivec2(1088, 832), glm::vec2(1, 1), &spritesheet, &shaderProgram);
		sprite->setNumberAnimations(1);

		sprite->setAnimationSpeed(I1, 12);
		sprite->addKeyframe(I1, glm::vec2(0.f, 0.f));
		break;

	case 1:
		spritesheet.loadFromFile("images/Instructions.jpg", TEXTURE_PIXEL_FORMAT_RGBA);
		sprite = Sprite::createSprite(glm::ivec2(1088, 832), glm::vec2(1, 1), &spritesheet, &shaderProgram);
		sprite->setNumberAnimations(1);

		sprite->setAnimationSpeed(I1, 12);
		sprite->addKeyframe(I1, glm::vec2(0.f, 0.f));
		break;

	case 2:
		spritesheet.loadFromFile("images/Credits.jpg", TEXTURE_PIXEL_FORMAT_RGBA);
		sprite = Sprite::createSprite(glm::ivec2(1088, 832), glm::vec2(1, 1), &spritesheet, &shaderProgram);
		sprite->setNumberAnimations(1);

		sprite->setAnimationSpeed(I1, 12);
		sprite->addKeyframe(I1, glm::vec2(0.f, 0.f));
		break;

	case 3:
		spritesheet.loadFromFile("images/Weapon.png", TEXTURE_PIXEL_FORMAT_RGBA);
		sprite = Sprite::createSprite(glm::ivec2(64, 64), glm::vec2(0.166666666667, 1), &spritesheet, &shaderProgram);
		sprite->setNumberAnimations(2);

		sprite->setAnimationSpeed(I1, 15);
		sprite->addKeyframe(I1, glm::vec2(0.666666666667f, 0.f));
		sprite->addKeyframe(I1, glm::vec2(0.333333333333f, 0.f));
		sprite->addKeyframe(I1, glm::vec2(0.f, 0.f));
		sprite->addKeyframe(I1, glm::vec2(0.166666666667f, 0.f));
		sprite->addKeyframe(I1, glm::vec2(0.5f, 0.f));
		sprite->addKeyframe(I1, glm::vec2(0.833333333333f, 0.f));
		sprite->addKeyframe(I1, glm::vec2(0.833333333333f, 0.f));
		sprite->addKeyframe(I1, glm::vec2(0.5f, 0.f));
		sprite->addKeyframe(I1, glm::vec2(0.166666666667f, 0.f));
		sprite->addKeyframe(I1, glm::vec2(0.f, 0.f));
		sprite->addKeyframe(I1, glm::vec2(0.333333333333f, 0.f));
		sprite->addKeyframe(I1, glm::vec2(0.666666666667f, 0.f));
		break;

	case 4:
		spritesheet.loadFromFile("images/Win_Menu.jpg", TEXTURE_PIXEL_FORMAT_RGBA);
		sprite = Sprite::createSprite(glm::ivec2(1088, 832), glm::vec2(1, 1), &spritesheet, &shaderProgram); 
		sprite->setNumberAnimations(1);

		sprite->setAnimationSpeed(I1, 12);
		sprite->addKeyframe(I1, glm::vec2(0.f, 0.f));
		break;

	case 5:
		spritesheet.loadFromFile("images/Map1Title.jpg", TEXTURE_PIXEL_FORMAT_RGBA);
		sprite = Sprite::createSprite(glm::ivec2(1088, 832), glm::vec2(1, 1), &spritesheet, &shaderProgram);
		sprite->setNumberAnimations(1);

		sprite->setAnimationSpeed(I1, 12);
		sprite->addKeyframe(I1, glm::vec2(0.f, 0.f));
		break;

	case 6:
		spritesheet.loadFromFile("images/Map2Title.jpg", TEXTURE_PIXEL_FORMAT_RGBA);
		sprite = Sprite::createSprite(glm::ivec2(1088, 832), glm::vec2(1, 1), &spritesheet, &shaderProgram);
		sprite->setNumberAnimations(1);

		sprite->setAnimationSpeed(I1, 12);
		sprite->addKeyframe(I1, glm::vec2(0.f, 0.f));
		break;

	}
	sprite->changeAnimation(0);
	tileMapDispl = tileMapPos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + posImatge.x), float(tileMapDispl.y + posImatge.y)));


}

void Imatge::update(int deltaTime, int imatge, int op)
{
	switch (imatge) {
		case 0:
			if (sprite->animation() != I1)
				sprite->changeAnimation(I1);
			break;

		case 1:
			if (sprite->animation() != I1)
				sprite->changeAnimation(I1);
			break;

		case 2:
			if (sprite->animation() != I1)
				sprite->changeAnimation(I1);
			break;

		case 3:
			sprite->update(deltaTime);
			if (sprite->animation() != I1)
				sprite->changeAnimation(I1);

			posImatge.y = ops[op];
			sprite->setPosition(glm::vec2(float(tileMapDispl.x + posImatge.x), float(tileMapDispl.y + posImatge.y)));
			break;

		case 4:
			if (sprite->animation() != I1)
				sprite->changeAnimation(I1);
			break;

		case 5:
			if (sprite->animation() != I1)
				sprite->changeAnimation(I1);
			break;

		case 6:
			if (sprite->animation() != I1)
				sprite->changeAnimation(I1);
			break;
	}
}

void Imatge::render()
{
	sprite->render();
}

void Imatge::setPosition(const glm::vec2 &pos)
{
	posImatge = pos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + posImatge.x), float(tileMapDispl.y + posImatge.y)));
}

void Imatge::setTileMap(TileMap *tileMap)
{
	map = tileMap;
}

void Imatge::ret_opcio(int &y) {
	y = posImatge.y;
}