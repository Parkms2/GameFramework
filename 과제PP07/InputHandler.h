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
	void clean();  // ����̽� ���� �ʱ�ȭ�� �κ��� clear �ϴ� �Լ� �ۼ��ϸ�ȴ�.
	bool isKeyDown(SDL_Scancode key);	//�ش�Ű�� �������ִ��� Ȯ��	(����)
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

	
