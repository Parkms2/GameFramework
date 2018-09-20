#include "game.h"
bool Game::init(const char*title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			m_bRunning = true;

			SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/animate.bmp");
			m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
			SDL_FreeSurface(pTempSurface);
			//SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
			m_sourceRectangle.w = 128;
			m_sourceRectangle.h = 82;
			m_destinationRectangle.x = m_sourceRectangle.x = 0;
			m_destinationRectangle.y = m_sourceRectangle.y = 0;
			m_destinationRectangle.w = m_sourceRectangle.w;
			m_destinationRectangle.h = m_sourceRectangle.h;
		}
		else return false;
	}
	return true;
}
void Game::render() {
	SDL_RenderClear(m_pRenderer);
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
	SDL_RenderPresent(m_pRenderer);

	//DrawSurface(screen, x, y, ch); 
	//SDL_Flip(screen);

}
void Game::update() {
	int pixel = 128, fps = 10, imageSum = 6;
	// pixel은 한 장면의 픽셀, fps은 장면당 호출시간(1000 = 1초) ,imageSum은 장면의 수
	m_sourceRectangle.x = pixel * int(((SDL_GetTicks() / fps) % imageSum));
}
void Game::handleEventes() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			m_bRunning = false; break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_LEFT: // 왼쪽키 
				x--; break;
			case SDLK_RIGHT: // 오른쪽키 
				x++; break;
			case SDLK_UP: // 위쪽키 
				y--; break;
			case SDLK_DOWN: // 아래쪽키 
				y++; break;
			}
		default:
			break;
	}
}

void Game::clean() {
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}