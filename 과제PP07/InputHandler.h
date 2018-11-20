#pragma once
#include "SDL.h"
#include<vector>
#include"Vector2D.h"

class InputHandler {
public:
	static InputHandler* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	void update();
	void clean();  // 디바이스 관련 초기화된 부분을 clear 하는 함수 작성하면된다.
	bool isKeyDown(SDL_Scancode key);	//해당키가 눌려져있는지 확인	(지속)
	const Uint8* m_keystates;
	bool useKeyS;
private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;
	void onKeyDown();
	void onKeyUp();
};

typedef InputHandler TheInputHandler;

	
