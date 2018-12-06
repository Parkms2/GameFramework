#include"Enemy.h"
Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	setEnemyPosition = rand() % (720 - this->m_height) + 100;	//enemy�� ȭ�鿡 �߸����ʰ� ���ü� �ִ� ����+ ������� ���;� �ϴ� ����
	m_position.setY(setEnemyPosition);
	m_velocity.setX(15);
	m_velocity.setY(0);
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