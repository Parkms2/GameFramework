#include"game.h"

Game* g_game = 0;

int main(int argc, char* argv[]) {
	g_game = new Game();
	g_game->init("Chapter 1", 100, 100, 640, 480, false);
	g_game->m_bRunning = true;
	while (g_game->runnung()) {
		g_game->handleEventes();
		g_game->update();
		g_game->render();
	}


	SDL_Delay(1000);
	g_game->clean();
	return 0;
}