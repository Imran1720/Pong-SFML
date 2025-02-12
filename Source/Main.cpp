#include <iostream>
//#include <SFML/Graphics.hpp>
#include "../Header/Core/GameWindowManager.h"
#include "../Header/Event/EventManager.h"

int main()
{
	//Game window manager instance
    Core::GameWindowManager gameWindowManager;

	Events::EventManager eventManager;
	//window initialization
    gameWindowManager.initialize();


	while (gameWindowManager.isGameRunning())
	{
		eventManager.pollEvents(gameWindowManager.getGameWindow());
		gameWindowManager.render();
	}

	return 0;
}