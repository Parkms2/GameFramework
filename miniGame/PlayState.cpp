#include "PlayState.h"
#include"Player.h"
#include"Enemy.h"
#include"PauseState.h"
#include"GameOverState.h"

const std::string PlayState::s_playID = "PLAY";
PlayState* PlayState::s_pInstance = 0;

void PlayState::update()
{
	if (SDL_GetTicks() % 40 == 0) {
		m_gameObjects.push_back(new Enemy(new LoaderParams(-200, 0, 128, 55, "helicopter2")));
	}
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
		if (i > 0 && checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[0]), dynamic_cast<SDLGameObject*>(m_gameObjects[i]))) {
			TheGame::Instance()->getStateMachine()->changeState(GameOverState::Instance());
		}
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
		TheGame::Instance()->getStateMachine()->changeState(PauseState::Instance());
	}
}
void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}
bool PlayState::onEnter() {
	if (!TheTextureManager::Instance()->load("assets/helicopter.png", "helicopter", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/helicopter2.png", "helicopter2", TheGame::Instance()->getRenderer())) {
		return false;
	}

	m_gameObjects.push_back(new Player(new LoaderParams(1000, 400, 128, 55, "helicopter")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(-200, 0, 128, 55, "helicopter2")));

	std::cout << "entering PlayState\n";
	return true;

}

bool PlayState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	TheTextureManager::Instance()->clearFromTextureMap("helicopter2");
	std::cout << "exiting PlayState\n";
	return true;
}


bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2) {	//y축이 반대라서 위아래 바꿔야함...
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = p1->m_position.getX();
	rightA = p1->m_position.getX() + p1->m_width;
	bottomA = p1->m_position.getY();
	topA = p1->m_position.getY() + p1->m_height;

	//Calculate the sides of rect B
	leftB = p2->m_position.getX();
	rightB = p2->m_position.getX() + p2->m_width;
	bottomB = p2->m_position.getY();
	topB = p2->m_position.getY() + p2->m_height;

	if (rightA > leftB && rightB > leftA && topA > bottomB && topB > bottomA) {

		cout << "wow" << endl;
		return true;
	}
	return false;
}