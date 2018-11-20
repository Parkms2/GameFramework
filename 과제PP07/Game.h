#pragma once
#include <iostream>
#include<vector>
#include"SDL.h"
#include"TextureManager.h"
#include"Player.h"
#include"Enemy.h"
#include"InputHandler.h"
#include"fireManager.h"
class Game {
public:
	~Game() {}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	void quit();
	bool running() { return m_bRunning; }
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	SDL_Renderer* getRenderer() const { return m_pRenderer; }
private:
	Game() {}
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
	static Game* s_pInstance;
	int m_currentFrame;
	std::vector<GameObject*> m_gameObjects;
};

typedef Game TheGame;