#include "Player.h"
#include "Game.h"

Player::Player(const LoaderParams* pParams)
	: SDLGameObject(pParams)
{

}

void Player::draw()
{
	SDLGameObject::draw();
}

void Player::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput();
	m_currentFrame = int(((SDL_GetTicks() / 100) % 5));
	m_acceleration.setX(1);
	SDLGameObject::update();
}

void Player::clean()
{
}

void Player::handleInput()
{
	Vector2D* target = TheInputHandler::Instance()->getMousePosition();
	m_velocity = *target - m_position;
	m_velocity /= 50;

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE) && PlayState::Instance()->m_gameObjects.size() == 3)
	{
		createMissile();
	}
}

bool Player::createMissile()
{
	if (!TheTextureManager::Instance()->load("Assets/Missile.png", "missile"
		, TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* missile = new Missile(new LoaderParams(m_position.getX()-78, m_position.getY(), 78, 55, "missile"));

	PlayState::Instance()->m_gameObjects.push_back(missile);

	return true;
}