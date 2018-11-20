#pragma once
#include<SDL.h>
#include<string>
#include"LoaderParams.h"

class GameObject {
public:
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual bool clean() = 0;
protected:
	GameObject(const LoaderParams* pParams) {}
	virtual ~GameObject() {}
};