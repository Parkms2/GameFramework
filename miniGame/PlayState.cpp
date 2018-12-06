#include "PlayState.h"
#include"Player.h"
#include"Enemy.h"
#include"heart.h"
#include"PauseState.h"
#include"GameOverState.h"

const std::string PlayState::s_playID = "PLAY";
PlayState* PlayState::s_pInstance = 0;

void PlayState::update() {
	 if (SDL_GetTicks()  > nextTime)  {		//날라오는 적들
            nextTime = SDL_GetTicks()  + TimeLeft;
			m_gameObjects.push_back(new Enemy(new LoaderParams(-200, 0, 128, 55, "helicopter2")));
        }
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
		if (i > 0 && checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[0]), dynamic_cast<SDLGameObject*>(m_gameObjects[i]))) {
			if (myHeart == 0) {
				TheGame::Instance()->getStateMachine()->changeState(GameOverState::Instance());
			}
			else if (!colli) {		//닿으면 1초간 반짝반짝거리면서 무적상태, 목숨수 -1
				invin = SDL_GetTicks() + invinTime;
				myHeart--;
				if (m_heart.size() != 0)
					m_heart.erase(m_heart.begin());
				colli = true;
			}
		}
		for (int i = 0; i < m_heart.size(); i++) {
			m_heart[i]->update();
			if (colli) {
				if (invin < SDL_GetTicks()) {
					colli = false;
				}
			}
		}
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {		//pause상태
		TheGame::Instance()->getStateMachine()->changeState(PauseState::Instance());
	}
}
void PlayState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
	for (int i = 0; i < m_heart.size(); i++) {
		m_heart[i]->draw();
	}
}
bool PlayState::onEnter() {
	if (!TheTextureManager::Instance()->load("assets/helicopter.png", "helicopter", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/helicopter2.png", "helicopter2", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/heart.png", "myHeart", TheGame::Instance()->getRenderer())) {
		return false;
	}
	m_gameObjects.push_back(new Player(new LoaderParams(1000, 400, 128, 55, "helicopter")));

	m_heart.push_back(new Heart(new LoaderParams(1000, 36, 51, 44, "myHeart")));
	m_heart.push_back(new Heart(new LoaderParams(1060, 36, 51, 44, "myHeart")));
	m_heart.push_back(new Heart(new LoaderParams(1120, 36, 51, 44, "myHeart")));
	m_heart.push_back(new Heart(new LoaderParams(1180, 36, 51, 44, "myHeart")));
	myHeart = 4;
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