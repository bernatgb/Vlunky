#ifndef _GAME_INCLUDE
#define _GAME_INCLUDE

#include <windows.h> 
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib") // Link to the winmm library

#include "Scene.h"

#include "Menu.h"


#define SCREEN_WIDTH 1088 // 1152
#define SCREEN_HEIGHT 832 // 768


// Game is a singleton (a class with a single instance) that represents our whole application


class Game
{

public:
	Game() {}
	
	
	static Game &instance()
	{
		static Game G;
	
		return G;
	}
	
	void init();
	bool update(int deltaTime);
	void render();
	
	// Input callback methods
	void keyPressed(int key);
	void keyReleased(int key);
	void specialKeyPressed(int key);
	void specialKeyReleased(int key);
	void mouseMove(int x, int y);
	void mousePress(int button);
	void mouseRelease(int button);
	
	bool getKey(int key) const;
	bool getSpecialKey(int key) const;

	LPWSTR Game::ConvertString(const std::string& instr);


private:
	bool bPlay;                       // Continue to play game?
	Scene scene;                      // Scene to render
	bool keys[256], specialKeys[256]; // Store key states so that 
	                                  // we can have access at any time
	bool pause = false;
	Menu menu;
	bool triat = false;
	int op = 0;
	bool fi = true;
};


#endif // _GAME_INCLUDE


