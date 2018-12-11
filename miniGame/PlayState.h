#pragma once
#include "GameState.h"
#include"SDLGameObject.h"

class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);
	virtual std::string getStateID() const { return s_playID; }
	static PlayState* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new PlayState();
			return s_pInstance;
		}
		return s_pInstance;
	}
	bool colli = false;		//������� ���� + player �������� üũ
private:
	static const std::string s_playID;
	static PlayState* s_pInstance;
	std::vector<GameObject*> m_gameObjects;
	std::vector<GameObject*> m_heart;
	std::vector<GameObject*> m_back;
	int TimeLeft = 250;	//1000 -> 1��
	int invinTime = 1700;	//1.7�� ����
	int nextTime = 0;			//���� ���� ������ �ð� (����ð� + TimeLeft �� ����)
	int myHeart = 4;		//�����
	int invin = 0;	//�����ð� üŷ
};