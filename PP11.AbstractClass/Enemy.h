#pragma once
#include"GameObject.h"

class Enemy : public GameObject
{
public:
	Enemy(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();

};