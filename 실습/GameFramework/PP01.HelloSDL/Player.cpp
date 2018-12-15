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
	isRight();
	m_currentFrame = int(((SDL_GetTicks() / 100) % 5));
	m_acceleration.setX(1);

	SDLGameObject::update();
}

void Player::clean()
{
	SDLGameObject::clean();
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
	if (!TheTextureManager::Instance()->load("Assets/smoke.png", "smoke"
		, TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (isRight() == true)
	{
		Missile* missile = new Missile(new LoaderParams(m_position.getX() + 140, m_position.getY(), 78, 55, "missile"));
		missile->velocity = 10;
		PlayState::Instance()->m_gameObjects.push_back(missile);

		SDLGameObject* smoke = new SDLGameObject(new LoaderParams(missile->getPosition().getX()+55, missile->getPosition().getY(), 55, 55, "smoke"));
		PlayState::Instance()->m_gameObjects.push_back(smoke);

		missile->reloadUI();
	}
	else if (isRight() == false)
	{
		Missile* missile = new Missile(new LoaderParams(m_position.getX() - 78, m_position.getY(), 78, 55, "missile"));
		missile->velocity = -10;
		PlayState::Instance()->m_gameObjects.push_back(missile);

		SDLGameObject* smoke = new SDLGameObject(new LoaderParams(missile->getPosition().getX()-55, missile->getPosition().getY(), 55, 55, "smoke"));
		PlayState::Instance()->m_gameObjects.push_back(smoke);

		missile->reloadUI();
	}

	return true;
}

bool Player::isRight()
{
	if (InputHandler::Instance()->getMousePosition()->getX() > m_position.getX())
	{
		return true;
	}
	else
	{
		return false;
	}
}