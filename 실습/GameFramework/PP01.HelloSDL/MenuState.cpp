#include "MenuState.h"
#include "MenuButton.h"
#include "PlayState.h"
#include "Game.h"
#include <SDL_mixer.h>

const std::string MenuState::s_menuID = "MENU";
Mix_Music* MTM = NULL;

void MenuState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void MenuState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onEnter()
{
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
	Mix_VolumeMusic(18);
	MTM = Mix_LoadMUS("Assets/Title.mp3");
	Mix_PlayMusic(MTM, -1);
	if (!TheTextureManager::Instance()->load("Assets/MenuBG.png", "MenuBG",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/button.png", "playbutton",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/exit.png", "exitbutton",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* menuBG = new SDLGameObject(new LoaderParams(0, 0, 1024, 768, "MenuBG"));
	GameObject* button1 = new MenuButton(
		new LoaderParams(312, 334, 400, 100, "playbutton"), s_menuToPlay);
	std::cout << "entering MenuState\n";
	GameObject* button2 = new MenuButton(
		new LoaderParams(312, 500, 400, 100, "exitbutton"), s_exitFromMenu);
	m_gameObjects.push_back(menuBG);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering MenuState\n";
	return true;
}

bool MenuState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("MenuBG");
	TheTextureManager::Instance()->clearFromTextureMap("playbutton");
	TheTextureManager::Instance()->clearFromTextureMap("exitbutton");

	Mix_FreeMusic(MTM);
	Mix_CloseAudio();
	std::cout << "exiting MenuState\n";
	return true;
}

void MenuState::s_menuToPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(PlayState::Instance());
	std::cout << "Play button clicked\n";
}

void MenuState::s_exitFromMenu()
{
	std::cout << "Exit button clicked\n";
	TheGame::Instance()->quit();
}

