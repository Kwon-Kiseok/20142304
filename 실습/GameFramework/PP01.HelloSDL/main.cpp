/*
	2018.11.08		
	Kwon Kiseok
	main.cpp
*/
#include "Game.h"

Game* g_game = 0;		//게임 오브젝트

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
	이론
	dll 동적 라이브러리 , 정적 라이브러리 설명 , 차이점 , 왜 필요한지 , dll 파일 찾는 순서
*/