#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

namespace Gameplay
{
	class Ball
	{
	private:
		Texture pong_ball_texture;
		Sprite pong_ball_sprite;

		std::string texture_path = "Assets/Textures/Ball.png";

		const float scale_x = 0.04f;
		const float scale_y = 0.04f;
		
		const float position_x = 960.0f;
		const float position_y = 540.0f;

		void loadTexture();
		void initializeVariables();

	public:
		Ball();
		void update();
		void render(RenderWindow* game_window);

	};
}