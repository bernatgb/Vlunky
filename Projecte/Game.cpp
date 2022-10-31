#include <GL/glew.h>
#include <GL/glut.h>
#include "Game.h"

#include <windows.h> 
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib") // Link to the winmm library


void Game::init()
{
	bPlay = true;
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	menu.init();
	scene.init();

	LPWSTR audio0 = ConvertString("open \"music/Title.mp3\" type mpegvideo alias 0mp3");
	mciSendString(audio0, NULL, 0, NULL);
	mciSendString(ConvertString("play 0mp3"), NULL, 0, NULL);
	LPWSTR audio1 = ConvertString("open \"music/Game1.mp3\" type mpegvideo alias 1mp3");
	mciSendString(audio1, NULL, 0, NULL);
	LPWSTR audio2 = ConvertString("open \"music/Game2.mp3\" type mpegvideo alias 2mp3");
	mciSendString(audio2, NULL, 0, NULL);
}

bool Game::update(int deltaTime)
{	
	if (!triat) {
		menu.update(deltaTime, op);
		mciSendString(ConvertString("stop 1mp3"), NULL, 0, NULL);
		mciSendString(ConvertString("stop 2mp3"), NULL, 0, NULL);
		mciSendString(ConvertString("stop 3mp3"), NULL, 0, NULL);
		mciSendString(ConvertString("play 0mp3 repeat"), NULL, 0, NULL);
	}
	else {
		if (op == 0)
			if (!pause) {
				scene.update(deltaTime, false);
				if (scene.ret_nivell() < 9) {
					mciSendString(ConvertString("stop 0mp3"), NULL, 0, NULL);
					mciSendString(ConvertString("stop 2mp3"), NULL, 0, NULL);
					mciSendString(ConvertString("stop 3mp3"), NULL, 0, NULL);
					mciSendString(ConvertString("play 1mp3 repeat"), NULL, 0, NULL);
				}
				else {
					mciSendString(ConvertString("stop 0mp3"), NULL, 0, NULL);
					mciSendString(ConvertString("stop 1mp3"), NULL, 0, NULL);
					mciSendString(ConvertString("stop 3mp3"), NULL, 0, NULL);
					mciSendString(ConvertString("play 2mp3 repeat"), NULL, 0, NULL);
				}
			}
				
		if (op == 1)
			if (!pause) {
				scene.update(deltaTime, true);
				if (scene.ret_nivell() < 9) {
					mciSendString(ConvertString("stop 0mp3"), NULL, 0, NULL);
					mciSendString(ConvertString("stop 2mp3"), NULL, 0, NULL);
					mciSendString(ConvertString("stop 3mp3"), NULL, 0, NULL);
					mciSendString(ConvertString("play 1mp3 repeat"), NULL, 0, NULL);
				}
				else {
					mciSendString(ConvertString("stop 0mp3"), NULL, 0, NULL);
					mciSendString(ConvertString("stop 1mp3"), NULL, 0, NULL);
					mciSendString(ConvertString("stop 3mp3"), NULL, 0, NULL);
					mciSendString(ConvertString("play 2mp3 repeat"), NULL, 0, NULL);
				}
			}
	}
	return bPlay;
}

void Game::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (!triat)
		menu.render(0);
	else {
		if (op == 0 && !scene.guanyat()) {
			scene.render(false);
		}
		else if (op == 1 && !scene.guanyat()) {
			scene.render(true);
		}
		else if (op == 2) 
			menu.render(1);
		else if (op == 3)
			menu.render(2);
		else {
			mciSendString(ConvertString("stop 0mp3"), NULL, 0, NULL);
			mciSendString(ConvertString("stop 1mp3"), NULL, 0, NULL);
			mciSendString(ConvertString("stop 2mp3"), NULL, 0, NULL);
			mciSendString(ConvertString("play 3mp3 from 0"), NULL, 0, NULL);
			menu.render(3);
		}
	}
}

void Game::keyPressed(int key)
{
	if (key == 13 || key == 32)
		triat = true;
	if (key == 'q') {
		triat = false;
		scene.init();
		mciSendString(ConvertString("stop 1mp3"), NULL, 0, NULL);
		mciSendString(ConvertString("play 1mp3 repeat"), NULL, 0, NULL);
	}

	if (key == 'p') {
		pause = !pause;
		mciSendString(ConvertString("pause 1mp3"), NULL, 0, NULL);
		mciSendString(ConvertString("pause 2mp3"), NULL, 0, NULL);
	}
	if (key == 'z') {
		scene.canviaNivell();
	}
	if(key == 27) // Escape code
		bPlay = false;
	keys[key] = true;
}

void Game::keyReleased(int key)
{
	keys[key] = false;
}

void Game::specialKeyPressed(int key)
{
	if (!triat) {
		if (key == GLUT_KEY_DOWN)
		{
			++op;
			if (op > 3)
				op = 0;
		}
		if (key == GLUT_KEY_UP)
		{
			--op;
			if (op < 0)
				op = 3;

		}
	}
	specialKeys[key] = true;
}

void Game::specialKeyReleased(int key)
{
	specialKeys[key] = false;
}

void Game::mouseMove(int x, int y)
{
}

void Game::mousePress(int button)
{
}

void Game::mouseRelease(int button)
{
}

bool Game::getKey(int key) const
{
	return keys[key];
}

bool Game::getSpecialKey(int key) const
{
	return specialKeys[key];
}

LPWSTR Game::ConvertString(const std::string& instr)
{
	// Assumes std::string is encoded in the current Windows ANSI codepage
	int bufferlen = ::MultiByteToWideChar(CP_ACP, 0, instr.c_str(), instr.size(), NULL, 0);

	if (bufferlen == 0)
	{
		// Something went wrong. Perhaps, check GetLastError() and log.
		return 0;
	}

	// Allocate new LPWSTR - must deallocate it later
	LPWSTR widestr = new WCHAR[bufferlen + 1];

	::MultiByteToWideChar(CP_ACP, 0, instr.c_str(), instr.size(), widestr, bufferlen);

	// Ensure wide string is null terminated
	widestr[bufferlen] = 0;

	// Do something with widestr
	return widestr;
	//delete[] widestr;
}