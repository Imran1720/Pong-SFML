#pragma once
#include "Ball/Ball.h"
#include "Paddle/Paddle.h"
#include "Boundary/Boundary.h"
#include "../Event/EventManager.h"
#include "../Utility/TimeService.h"
#include "../UI/UIService.h"

using namespace Events;
using namespace GameBoundary;
using namespace Utility;
using namespace UI;

namespace Gameplay
{
	class GameplayManager
	{
	private:
		float player1_position_x = 40.0f;
		float player1_position_y = 540.0f;

		float player2_postion_x = 1860.0f;
		float player2_postion_y = 540.0f;

		Ball* ball;

		Paddle* player1;
		Paddle* player2;
		EventManager* event_manager;
		Boundary* bounday;
		TimeService* time_service;
		UIService* ui_service;

		void initialize();

	public:
		GameplayManager(EventManager* manager);
		void update();

		void render(RenderWindow* game_window);

	};
}