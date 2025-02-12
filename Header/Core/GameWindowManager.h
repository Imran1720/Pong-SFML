#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace Core
{
	class GameWindowManager
	{
	private:
		int game_window_width = 1920;
		int game_window_height = 1080;

		std::string game_title = "SFML-PONG";


		RenderWindow* game_window;

		void createGameWindow();

	public:
		void initialize();
		RenderWindow* getGameWindow();
		bool isGameRunning();
		void render();

		void clearGameWindow();
		void displayGameWindow();
	};

}