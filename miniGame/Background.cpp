#include"Background.h"

Background::Background(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_currentFrame = 0;
	myPosition = m_position.getX();
}
void Background::draw()
{
	SDLGameObject::draw();
}
void Background::update()	//정상적인 방법이 아님
{
	m_velocity.setX(-10);	//2^4 * 103 = 1648
	if (m_position.getX() <= myPosition - 1648) {
		m_position.setX(myPosition);
	}
	SDLGameObject::update();

}
void Background::clean()
{
}