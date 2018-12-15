#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams)
	:SDLGameObject(pParams)
{
	m_velocity.setY(5);
	m_velocity.setX(0.001);
}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames));

	if (m_position.getY() > 700 && m_position.getX() < 800)
	{
		m_velocity.setY(-5);
		m_velocity.setX(5);
	}
	else if (m_position.getY() < 0 && m_position.getX() >= 800)
	{
		m_velocity.setY(5);
		m_velocity.setX(0);
	}
	else if (m_position.getY() > 700 && m_position.getX() > 800)
	{
		m_velocity.setX(-5);
		m_velocity.setY(-5);
	}
	else if (m_position.getY() < 0 && m_position.getX() < 800)
	{
		m_velocity.setX(0.001);
		m_velocity.setY(5);
	}

	SDLGameObject::update();
}

void Enemy::clean()
{
	SDLGameObject::clean();
}

