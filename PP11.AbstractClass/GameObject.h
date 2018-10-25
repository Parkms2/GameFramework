#pragma once
#include"SDL.h"
#include<iostream>
#include"TextureManager.h"
#include"LoaderParams.h"
#include"SDLGameObject.h"

class GameObject {
public:
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
protected:
	std::string m_textureID;
	int m_currentFrame;
	int m_currentRow;
	double m_x;
	int m_y;
	int m_width;
	int m_height;

	GameObject(const LoaderParams* pParams) {}
	virtual ~GameObject() {}
};
