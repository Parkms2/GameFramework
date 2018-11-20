#include"Fire.h"
#include"InputHandler.h"

Fire::Fire(const LoaderParams* pParams) : SDLGameObject(pParams) {
}
void Fire::draw() {
	SDLGameObject::draw2();
}
void Fire::update() {
	m_velocity.setX(10);
	SDLGameObject::update();
}
bool Fire::clean() {
	if (this->m_position.getX() >= 700) {	//화면밖
		return true;
	}
	if (this->m_position.getY() >= (63 -32)&& this->m_position.getY() <= 181) {	//만약 장애물에 닿으면
		if (this->m_position.getX() >= 400) {
			return true;
		}
	}
	return false;
}