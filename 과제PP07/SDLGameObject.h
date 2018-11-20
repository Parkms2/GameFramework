#pragma once
#include"GameObject.h"
#include"Vector2D.h"

class SDLGameObject : public GameObject {
public:
	SDLGameObject(const LoaderParams* pParams);
	virtual void draw();
	virtual void draw2();
	virtual void update();
	virtual bool clean();
protected:
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	std::string m_textureID;
	Vector2D m_position;		// ��ġ��
	Vector2D m_velocity;		// �ӵ�
	Vector2D m_acceleration;	// ����
};
