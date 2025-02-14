#pragma once
#include <SFML/Graphics.hpp>
#include "GameWindowManager.h"
#include "../Event/EventManager.h"
#include "../Gameplay/GameplayManager.h"
#include "../Sound/SoundManager.h"

using namespace sf;
using namespace Core;
using namespace Events;
using namespace std;
using namespace Gameplay;
using namespace Sound;

namespace Core
{
	class GameLoop
	{
	private:
		GameWindowManager* game_window_manager;
		EventManager* event_manager;
		GameplayManager* gameplay_Manager;
		SoundManager* sound_manager;

	public:
		void initialize();
		bool isGameRunning();
		void pollEvent();
		void update();
		void render();
	};
}
