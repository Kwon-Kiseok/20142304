#include "Missile.h"
#include "Game.h"

Missile::Missile(const LoaderParams* pParams)
	: SDLGameObject(pParams)
{
}

void Missile::draw()
{
	SDLGameObject::draw();
}
void Missile::update()
{
	m_velocity.setX(-5);

	if (PlayState::Instance()->checkCollision(
		dynamic_cast<SDLGameObject*>(PlayState::Instance()->m_gameObjects[2]),
		dynamic_cast<SDLGameObject*>(PlayState::Instance()->m_gameObjects[3])))
	{
		clean();
		PlayState::Instance()->m_gameObjects.pop_back();
		PlayState::Instance()->m_gameObjects.pop_back();
	}
	if (m_position.getX() <= 0)
	{
		clean();
		PlayState::Instance()->m_gameObjects.pop_back();
	}

	SDLGameObject::update();
}
void Missile::clean()
{
	SDLGameObject::clean();
}
