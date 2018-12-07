#include"Enemy.h"
Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	die = SDL_GetTicks() + 2000;	//생성후 2초후 죽음
	setEnemyPosition = rand() % 820 - 100;
	if (setEnemyPosition <= -45 || setEnemyPosition >= 720) {	//x축이 양수일때 y가 보이지 않는 범위에서 생성
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