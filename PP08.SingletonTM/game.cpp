#include "game.h"
#include<SDL_image.h>
#include"TextureManager.h"

bool Game::init(const char*title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			m_bRunning = true;
			SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);

			if (!TheTextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer)) return false;
		}
		else return false;
	}
	return true;
}
void Game::render() {
	SDL_RenderClear(m_pRenderer);
	TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82, m_current, m_pRenderer);
	TheTextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);
	SDL_RenderPresent(m_pRenderer);
}
void Game::update() {
	m_currentFrame = int(SDL_GetTicks() / 100 % 6);
	m_current = int(SDL_GetTicks() / 50 % 6);;
}
void Game::handleEventes() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}
void Game::clean() {
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}
