#include "PlayState.h"
#include"Player.h"
#include"Enemy.h"
const std::string PlayState::s_playID = "PLAY";
PlayState* PlayState::s_pInstance = 0;
void PlayState::update()
{
	for (std::vector<GameObject*>::size_type i = 0;	i != m_gameObjects.size(); i++)	{
		m_gameObjects[i]->update();
	}
}
void PlayState::render()
{
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}
bool PlayState::onEnter()
{
	m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));
	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	std::cout << "exiting PlayState\n";
	return true;
}