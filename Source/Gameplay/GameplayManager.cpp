#include "../../Header/Gameplay/GameplayManager.h"

namespace Gameplay
{
	GameplayManager::GameplayManager(EventManager* manager)
	{
		event_manager = manager;
		bounday = new Boundary();
		time_service = new TimeService();
		time_service->initialize();
		initialize();

	}

	void GameplayManager::initialize()
	{
		ball = new Ball();

		player1 = new Paddle(player1_position_x, player1_position_y);
		player2 = new Paddle(player2_postion_x, player2_postion_y);

	}

	void GameplayManager::render(RenderWindow* game_window)
	{
		ball->render(game_window);
		player1->render(game_window);
		player2->render(game_window);
		bounday->render(game_window);

	}

	void GameplayManager::update()
	{
		time_service->update();
		ball->update(player1,player2, time_service);
		player1->update(event_manager->isKeyPressed(Keyboard::W), event_manager->isKeyPressed(Keyboard::S), time_service);
		player2->update(event_manager->isKeyPressed(Keyboard::Up), event_manager->isKeyPressed(Keyboard::Down), time_service);

	}
}