#include"fireManager.h"
FireManager* FireManager::s_pInstance = 0;
void FireManager::initFire(int x, int y) {
	m_fire.push_back(new Fire(new LoaderParams(x, y, 32, 32, "fire"))); //200,141부분을 player 따라다니가 만들기 -> player값 가져오기
}
void FireManager::drawFire() {
	for (std::vector<GameObject*>::size_type i = 0; i < m_fire.size(); i++) {
	m_fire[i]->draw();
	FireManager::cleanFire();
	}
}
void FireManager::updateFire() {
	for (std::vector<GameObject*>::size_type i = 0; i < m_fire.size(); i++) m_fire[i]->update();
}
void FireManager::cleanFire() {
	for (std::vector<GameObject*>::size_type i = 0; i < m_fire.size(); i++) {
		if (m_fire[i]->clean())
		{
			m_fire.erase(m_fire.begin() + i);
		}
	}
}