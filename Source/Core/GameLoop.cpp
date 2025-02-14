#include "../../Header/Core/GameLoop.h"


namespace Core
{
	void GameLoop::initialize()
	{
		game_window_manager = new GameWindowManager();
		event_manager = new EventManager();
		gameplay_Manager = new GameplayManager(event_manager);
		sound_manager = new SoundManager();
		game_window_manager->initialize();
		sound_manager->PlayBackgroundMusic();
	}

	bool GameLoop::isGameRunning()
	{
		return game_window_manager->isGameRunning();
	}

	void GameLoop::pollEvent()
	{
		event_manager->pollEvents(game_window_manager->getGameWindow());
	}

	void GameLoop::update()
	{
		gameplay_Manager->update();
	}

	void GameLoop::render()
	{
		game_window_manager->clearGameWindow();

		gameplay_Manager->render(game_window_manager->getGameWindow());

		game_window_manager->displayGameWindow();
	}
}