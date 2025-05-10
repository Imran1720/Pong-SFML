#include <iostream>
#include "../../Header/Event/EventManager.h"

namespace Events
{
	void EventManager::pollEvents(RenderWindow* game_window)
	{
		sf::Event event;
		while (game_window->pollEvent(event))
		{
			if (isKeyPressed(sf::Keyboard::Escape))
			{
				game_window->close();
			}

			if (isLeftMouseButtonClicked())
			{
				Vector2i position = sf::Mouse::getPosition(*game_window);

				std::cout << "Left Mouse click at : " << position.x << ", "<<position.y<<std::endl;
			}
		}
	}

	bool EventManager::isKeyPressed(sf::Keyboard::Key key)
	{
		return sf::Keyboard::isKeyPressed(key);
	}

	bool EventManager::isLeftMouseButtonClicked()
	{

		return sf::Mouse::isButtonPressed(sf::Mouse::Left);
	}
}