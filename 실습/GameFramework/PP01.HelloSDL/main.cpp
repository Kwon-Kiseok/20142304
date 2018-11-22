/*
	2018.11.08		
	Kwon Kiseok
	main.cpp
*/
#include "Game.h"
#include <iostream>

Game* Game::s_pInstance = 0;
PlayState* PlayState::s_pInstance = 0;
MenuState* MenuState::s_pInstance = 0;
TheInputHandler* TheInputHandler::s_pInstance = 0;

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

Uint32 frameStart, frameTime;

int main(int argc, char* args[])
{
	std::cout << "game init attempt...\n";
	if (TheGame::Instance()->init("Chapter 1", 100, 100, 640, 480, false))
	{
		std::cout << "game init success!\n";
		while (TheGame::Instance()->running())
		{
			frameStart = SDL_GetTicks();
			TheGame::Instance()->handleEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();
			frameTime = SDL_GetTicks() - frameStart;

			if (frameTime < DELAY_TIME)
			{
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}
		}
	}
	else
	{
		std::cout << "game init failure - " << SDL_GetError() << "\n";
		return -1;
	}
	std::cout << "game closing...\n";
	TheGame::Instance()->quit();
	return 0;
}

/*
	이론
	dll 동적 라이브러리 , 정적 라이브러리 설명 , 차이점 , 왜 필요한지 , dll 파일 찾는 순서
*/