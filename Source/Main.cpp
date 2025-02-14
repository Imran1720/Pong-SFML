#include <iostream>
#include "../Header/Core/GameLoop.h"

using namespace Core;

int main()
{
	GameLoop* game_loop_manager = new GameLoop();

	game_loop_manager->initialize();

	while (game_loop_manager->isGameRunning())
	{
		game_loop_manager->pollEvent();
		game_loop_manager->update();
		game_loop_manager->render();
	}

	return 0;
}