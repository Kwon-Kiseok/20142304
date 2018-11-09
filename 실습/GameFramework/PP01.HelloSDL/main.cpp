/*
	2018.11.08		
	Kwon Kiseok
	main.cpp
*/
#include "Game.h"
#include <iostream>

Game* Game::s_pInstance = 0;

int main(int argc, char* args[])
{
	std::cout << "game init attempt...\n";
	if (TheGame::Instance()->init("Chapter 1", 100, 100, 640, 480, false))
	{
		std::cout << "game init success!\n";
		while (TheGame::Instance()->running())
		{
			TheGame::Instance()->handleEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();
			SDL_Delay(10);
		}
	}
	else
	{
		std::cout << "game init failure - " << SDL_GetError() << "\n";
		return -1;
	}
	std::cout << "game closing...\n";
	TheGame::Instance()->clean();
	return 0;
}

/*
	이론
	dll 동적 라이브러리 , 정적 라이브러리 설명 , 차이점 , 왜 필요한지 , dll 파일 찾는 순서
*/