#include "../../Header/Core/GameWindowManager.h"

namespace Core
{
	void GameWindowManager::initialize()
	{
		game_window = new RenderWindow();
		createGameWindow();
	}

	void GameWindowManager::createGameWindow()
	{
		game_window->create(
			VideoMode(game_window_width,game_window_height),
			game_title
		);
	}

	bool GameWindowManager::isGameRunning()
	{
		return game_window->isOpen();
	}

	void GameWindowManager::render()
	{

	}

	RenderWindow* GameWindowManager::getGameWindow()
	{
		return game_window;
	}

}