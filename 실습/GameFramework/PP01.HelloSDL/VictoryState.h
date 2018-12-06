#pragma once
#include "GameState.h"
#include "SDLGameObject.h"
#include "Game.h"

class VictoryState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_victoryID; }

	static VictoryState* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new VictoryState();
			return s_pInstance;
		}
		return s_pInstance;
	}
private:
	static void s_victoryToMain();
	static void s_exitFromVictory();
	static const std::string s_victoryID;
	static VictoryState* s_pInstance;
};