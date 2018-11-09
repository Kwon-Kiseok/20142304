#pragma once
#include "SDL.h"
#include "Player.h"
#include "Enemy.h"
#include "TextureManager.h"
#include <vector>

class Game
{
public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }
private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	//SDL_Texture* m_pTexture;		//SDL_Texture 
	//SDL_Rect m_sourceRectangle;		//원본 사각형
	//SDL_Rect m_destinationRectangle;//대상 사각형
	int m_currentFrame;
	//TextureManager m_textureManager;
	
	std::vector<GameObject*> m_gameObjects;
	
	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;
	bool m_bRunning;
};