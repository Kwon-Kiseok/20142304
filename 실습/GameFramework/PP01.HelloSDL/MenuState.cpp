#include "MenuState.h"
#include "MenuButton.h"
#include "Game.h"
const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{

}

void MenuState::render()
{

}

bool MenuState::onEnter()
{
	GameObject* button1 = new MenuButton(
		new LoaderParams(100, 100, 400, 100, "playbutton"), s_menuToPlay);
	std::cout << "entering MenuState\n";
	GameObject* button2 = new MenuButton(
		new LoaderParams(100, 300, 400, 100, "exitbutton"), s_exitFromMenu);
	return true;
}

bool MenuState::onExit()
{
	std::cout << "exiting MenuState\n";
	return true;
}

void MenuState::s_menuToPlay()
{
	std::cout << "Play button clicked\n";
}

void MenuState::s_exitFromMenu()
{
	std::cout << "Exit button clicked\n";
	TheGame::Instance()->quit();
}

