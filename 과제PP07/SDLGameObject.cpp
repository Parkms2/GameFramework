#include"SDLGameObject.h"
#include"Game.h"
SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject(pParams), m_position(pParams->getX(), pParams->getY()), 
	m_velocity(0.0f, 0.0f), m_acceleration(0.0f, 0.0f){

	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();
	m_currentRow = 1;
	m_currentFrame = 1;
}

void SDLGameObject::draw() {
	TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame,
		TheGame::Instance()->getRenderer());
}
void SDLGameObject::draw2() {
	TextureManager::Instance()->draw(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, TheGame::Instance()->getRenderer());
}
void SDLGameObject::update() {		//가속도 연산
	m_velocity += m_acceleration;	//속도가 가속도만큼 점차 증가됨
	m_position += m_velocity;

}
bool SDLGameObject::clean() {
	return false;
}