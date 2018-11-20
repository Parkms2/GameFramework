#include"Player.h"
#include"InputHandler.h"
#include"fireManager.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {
}
void Player::draw() {
	SDLGameObject::draw();
}
void Player::update() {
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput(); // add our function
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	SDLGameObject::update();
}
bool Player::clean() {
	return false;
}
void Player::handleInput() {
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		m_velocity.setX(5);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
		m_velocity.setX(-5);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
		m_velocity.setY(-5);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
		m_velocity.setY(5);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_S)) {
		if (SDL_GetTicks() > nextFire) {
			nextFire = SDL_GetTicks() + fireRate;		//발사후, 발사주기를 더한값을 다음 발사시간에 저장

			TheFireManager::Instance()->initFire(this->m_position.getX() + 128, this->m_position.getY() + 25);;
		}
	}
}