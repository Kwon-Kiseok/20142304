#pragma once
#include "SDLGameObject.h"

class Missile : public SDLGameObject
{
public:
	Missile(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	int velocity = 0;
};