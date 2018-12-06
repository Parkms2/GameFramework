#include"Enemy.h"
Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	setEnemyPosition = rand() % 820 - 100;
	if (setEnemyPosition <= -45 || setEnemyPosition >= 720) {
		m_position.setX(rand() % 400);
	}
	m_position.setY(setEnemyPosition);
	m_velocity.setX(20);
	m_velocity.setY(rand() % 15 - 8);
}
void Enemy::draw()
{
	SDLGameObject::draw();
}
void Enemy::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 5));
	SDLGameObject::update();
}
void Enemy::clean()
{
}
void Enemy::handleInput() {
}