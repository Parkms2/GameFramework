#include "game.h"
#include<SDL_image.h>
Game* Game::s_pInstance = 0;

bool Game::init(const char*title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
		if (m_pWindow != 0) m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		m_bRunning = true;
		SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
		if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer)) return false;
		if (!TheTextureManager::Instance()->load("assets/fire.png", "fire", m_pRenderer)) return false;
		if (!TheTextureManager::Instance()->load("assets/wall.png", "wall", m_pRenderer)) return false;
		if (!TheTextureManager::Instance()->load("assets/wall2.png", "wall2", m_pRenderer)) return false;
		m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
		m_gameObjects.push_back(new Enemy(new LoaderParams(400, 62, 80, 120, "wall")));
		m_gameObjects.push_back(new Enemy(new LoaderParams(400, 62, 40, 65, "wall2"))); //65/40
	}
	else return false;
	return true;
}

void Game::render() {
	SDL_RenderClear(m_pRenderer);
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
	TheFireManager::Instance()->drawFire();
	SDL_RenderPresent(m_pRenderer);
}
void Game::update() {
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
	TheFireManager::Instance()->updateFire();
}
void Game::handleEvents() {
	TheInputHandler::Instance()->update();
}
void Game::clean() {
	std::cout << "cleaning game\n";
	TheInputHandler::Instance()->clean();
	//SDL_DestroyWindow(m_pWindow);
	//SDL_DestroyRenderer(m_pRenderer);
	//SDL_Quit();
}
void Game::quit() {
	m_bRunning = false;
}
