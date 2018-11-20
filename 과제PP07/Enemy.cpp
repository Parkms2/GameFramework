#include"Enemy.h"
#include"InputHandler.h"
#include"fireManager.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {
}
void Enemy::draw() {
	SDLGameObject::draw2();
}
void Enemy::update() {
}
bool Enemy::clean() {
	return false;
}