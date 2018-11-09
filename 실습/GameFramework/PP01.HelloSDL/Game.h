#pragma once
#include "Player.h"
#include "Enemy.h"
#include "InputHandler.h"
#include <vector>

class Game
{
public:
	~Game() {}
	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	void quit();
	bool running() { return m_bRunning; }

	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

	SDL_Renderer* getRenderer() const { return m_pRenderer; }

private:
	Game() {}

	static Game* s_pInstance;

	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	//SDL_Texture* m_pTexture;		//SDL_Texture 
	//SDL_Rect m_sourceRectangle;		//원본 사각형
	//SDL_Rect m_destinationRectangle;//대상 사각형
	int m_currentFrame;
	//TextureManager m_textureManager;
	
	std::vector<GameObject*> m_gameObjects;
	
	//GameObject* m_go;
	//GameObject* m_player;
	//GameObject* m_enemy;
	bool m_bRunning;
};
typedef Game TheGame;