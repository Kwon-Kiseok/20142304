#include "VictoryState.h"
#include "MenuButton.h"
#include <SDL_mixer.h>

const std::string VictoryState::s_victoryID = "VICTORY";
Mix_Music* MVM = NULL;

void VictoryState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}
void VictoryState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
bool VictoryState::onEnter()
{
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
	Mix_VolumeMusic(18);
	MVM = Mix_LoadMUS("Assets/VictoryBGM.mp3");
	Mix_PlayMusic(MVM, -1);
	if (!TheTextureManager::Instance()->load("Assets/victory.png", "victory",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/main.png", "mainbutton",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/exit2.png", "exitbutton",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* victory = new SDLGameObject(new LoaderParams(120, 0, 380, 313, "victory"));
	GameObject* button1 = new MenuButton(new LoaderParams(200, 250, 200, 80, "mainbutton"), s_victoryToMain);
	GameObject* button2 = new MenuButton(new LoaderParams(200, 350, 200, 80, "exitbutton"), s_exitFromVictory);

	m_gameObjects.push_back(victory);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	return true;
}
bool VictoryState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("victory");
	TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
	TheTextureManager::Instance()->clearFromTextureMap("exitbutton");

	Mix_FreeMusic(MVM);
	Mix_CloseAudio();
	return true;
}

void VictoryState::s_victoryToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(MenuState::Instance());
	std::cout << "GoToMain button clicked\n";
}
void VictoryState::s_exitFromVictory()
{
	TheGame::Instance()->quit();
}