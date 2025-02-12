#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace Events
{
	class EventManager
	{
	public:
		void pollEvents(RenderWindow* game_window);
		bool isKeyPressed(sf::Keyboard::Key key);
		bool isLeftMouseButtonClicked();
	};
}