#include "Game.h"
#include <iostream>

bool Game::init(const char*title, int xpos, int ypos,
	int width, int height, bool fullscreen)
{
	//main.cpp에서 m_bRunning 으로 게임 반복문의 조건을 보고 있음
	//Game.h 에서 m_bRunning 이 false 값으로 초기화 되어있기 때문에 
	//init이 될 때 게임이 돌아간다는 것을 보여주기 위해 true로 할당해줌
	m_bRunning = true;
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow("HOSEO BAR",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			640, 480, SDL_WINDOW_SHOWN);
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}
		//SDL_Surface* pTempSurface = IMG_Load("Assets/animate.png");		
		//SDL_Surface* pTempSurface = IMG_Load("Assets/animate-alpha.png");	//알파
		SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
		//m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
		//SDL_FreeSurface(pTempSurface);
		//m_textureManager.load("Assets/animate-alpha.png", "animate", m_pRenderer);
		if (!TheTextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer))
		{
			return false;
		}
		//m_go.load(100, 100, 128, 82, "animate");
		//m_player.load(300, 300, 128, 82, "animate");
		//m_sourceRectangle.w = 128;
		//m_sourceRectangle.h = 82;
		//원본 사각형 : m_sourceRectangle    대상 사각형 : m_destinationRectangle
		//m_destinationRectangle.x = m_sourceRectangle.x = 0;
		//m_destinationRectangle.y = m_sourceRectangle.y = 0;
		//m_destinationRectangle.w = m_sourceRectangle.w;
		//m_destinationRectangle.h = m_sourceRectangle.h;

		//m_go = new GameObject();
		//m_player = new Player();
		//m_enemy = new Enemy();
		
		//m_go->load(100, 100, 128, 82, "animate");
		//m_player->load(300, 300, 128, 82, "animate");
		//m_enemy->load(0, 0, 128, 82, "animate");

		m_gameObjects.push_back(new Player(new LoaderParams(100,100,128,82,"animate")));
		m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));
	}
	else
	{
		return 1;
	}
	return true;
}
void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	//원본 사각형과 대상 사각형의 위치와 크기에 따라 화면에 다르게 나타남
	//SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
	//m_textureManager.draw("animate", 0, 0, 128, 82, m_pRenderer);
	//m_textureManager.drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);
	//TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82, m_pRenderer);
	//TheTextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);
	//m_go.draw(m_pRenderer);
	//m_player.draw(m_pRenderer);

	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}

	SDL_RenderPresent(m_pRenderer);
}
void Game::update()
{
	//m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));
	//m_destinationRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));
	//m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	//m_go.update();
	//m_player.update();

	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}
void Game::quit()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}
void Game::clean()
{
	TheInputHandler::Instance()->clean();
}
void Game::handleEvents()
{
	TheInputHandler::Instance()->update();
}