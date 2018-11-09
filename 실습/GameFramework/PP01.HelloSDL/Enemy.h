#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"

class Enemy : public SDLGameObject
{
public:
	//void load(int x, int y, int width, int height, std::string textureID);
	//void draw(SDL_Renderer* pRenderer);
	Enemy(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
private:
	void handleInput();
};