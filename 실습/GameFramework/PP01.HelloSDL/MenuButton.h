#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"

enum Button_states
{
	MOUSE_OUT = 0, CLICKED = 1, MOUSE_OVER = 2
};

class MenuButton : public SDLGameObject
{
public:
	void(*m_callback)();
	bool m_bReleased;
	MenuButton(const LoaderParams* pParams, void(*callback)());
	void update();
};