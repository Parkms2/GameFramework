#include"Monster.h"

void Monster::update()
{
	if (m_x <540 && wall == true) {
		m_x += 1;
		m_currentFrame = int(SDL_GetTicks() / 40 % 4);
	}
	else if (m_x >= 540 || wall == false) {
		wall = false;
		m_x -= 1;
		m_currentFrame = int(SDL_GetTicks() / 40 % 4);
		if (m_x < 0) wall = true;
	}
}