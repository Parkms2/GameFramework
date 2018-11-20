#pragma once
#include"SDLGameObject.h"

class Player : public SDLGameObject{
public:
	Player(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual bool clean();
private:
	void handleInput();
	float nextFire;
	float fireRate = 200;	//발사 주기	0.2초
};
