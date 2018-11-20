#pragma once
#include<vector>
#include"fire.h"
#include"SDLGameObject.h"
#include"TextureManager.h"
class FireManager { // player 위치값가져오기
public:
	FireManager() {}
	static FireManager* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new FireManager();
		}
		return s_pInstance;
	}
	void initFire(int x, int y);
	void drawFire();
	void updateFire();
	void cleanFire();
	std::vector<GameObject*> m_fire;
private:
	static FireManager* s_pInstance;
};
typedef FireManager TheFireManager;