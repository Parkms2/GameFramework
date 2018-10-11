#pragma once
#include"SDL.h"
#include<map>
using namespace std;

class TextureManager {
private:
	TextureManager() {};
	static TextureManager* s_pInstance;

public:
	
	~TextureManager() {};

	bool load(string fileName, string id, SDL_Renderer* pRenderer);
	void draw(string id, int x, int y, int width, int height, int current, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	static TextureManager* Instance() {
		if (s_pInstance == 0)	 {
			s_pInstance = new TextureManager();
			return s_pInstance;
		}
		return s_pInstance;
	}
private:
	map < string, SDL_Texture* > m_textureMap;
};

typedef TextureManager TheTextureManager;