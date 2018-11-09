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
	�̷�
	dll ���� ���̺귯�� , ���� ���̺귯�� ���� , ������ , �� �ʿ����� , dll ���� ã�� ����
*/