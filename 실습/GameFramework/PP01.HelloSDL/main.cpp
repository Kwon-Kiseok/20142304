/*
	2018.11.08		
	Kwon Kiseok
	main.cpp
*/
#include "Game.h"

Game* g_game = 0;		//���� ������Ʈ

int main(int argc, char* args[])
{
	g_game = new Game();
	g_game->init("Chapter 1", 100, 100, 640, 480, false);

	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}
	g_game->clean();
	return 0;
}

/*
	�̷�
	dll ���� ���̺귯�� , ���� ���̺귯�� ���� , ������ , �� �ʿ����� , dll ���� ã�� ����
*/