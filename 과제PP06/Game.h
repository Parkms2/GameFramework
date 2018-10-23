#pragma once

#include"SDL.h"
#include <iostream>
#include<vector>
#include"TextureManager.h"
#include"GameObject.h"
#include"Player.h"
#include"Monster.h"

class Game {
public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEventes();
	void clean();
	bool running() { return m_bRunning; }

private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

	int m_currentFrame;

	std::vector<GameObject*> m_gameObjects;

	GameObject* m_monster;
	GameObject* m_monster2;

};
