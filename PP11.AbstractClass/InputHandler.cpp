#include"InputHandelr.h"

InputHandler::InputHandler()
{
	// 생성자 
}

void InputHandler::clean()
{
	// 향후 추가 
}

void InputHandler::update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			TheGame::Instance()->quit();
		}
	}
}