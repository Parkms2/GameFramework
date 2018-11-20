#pragma once
#include"SDLGameObject.h"
class Fire : public SDLGameObject {
public:
	Fire(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual bool clean();
};