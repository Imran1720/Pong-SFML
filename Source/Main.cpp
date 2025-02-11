#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Header/Core/GameWindowManager.h"
int main()
{
	//Game window manager instance
    Core::GameWindowManager gameWindowManager;

	//window initialization
    gameWindowManager.initialize();


	while (gameWindowManager.isGameRunning())
	{
		gameWindowManager.render();
	}

	return 0;
}