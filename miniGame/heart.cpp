#include"heart.h"

Heart::Heart(const LoaderParams* pParams) : SDLGameObject(pParams) {
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_currentFrame = 0;
}
void Heart::draw() {
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Heart::update() {
	SDLGameObject::update();
}
void Heart::clean() {
}