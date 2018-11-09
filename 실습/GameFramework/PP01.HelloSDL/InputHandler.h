#pragma once
#include <SDL.h>
#include "Game.h"

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	void update();
	void clean();
	bool isKeyDown(SDL_Scancode key);
private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;

	const Uint8* m_keystates;
};

typedef InputHandler TheInputHandler;