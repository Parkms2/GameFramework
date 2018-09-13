#pragma once

#include"SDL.h"
#include <iostream>

class Game {
public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEventes();
	void clean();
	bool runnung() { return m_bRunning; }

	bool m_bRunning;
private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Texture* m_pTexture;
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;
};