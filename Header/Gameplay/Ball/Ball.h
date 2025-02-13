#pragma once
#include "../../Header/Gameplay/Paddle/Paddle.h"
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
		const float top_boundary = 20.0f;
		const float bottom_boundary = 1060.0f;

		const float left_boundary = 0.0f;
		const float right_boundary = 1920.0f;

		const float center_position_x = 960.0f;
		const float center_position_y = 540.0f;

		float ball_speed = 0.15f;
		Vector2f velocity = Vector2f(ball_speed,ball_speed);

		void loadTexture();
		void initializeVariables();
		void move();

	public:
		Ball();
		void update(Paddle* player1, Paddle* player2);
		void render(RenderWindow* game_window);
		void handlePaddleCollision(Paddle* player1, Paddle* player2);
		void handleBoundaryCollision();
		void handleOutofBoundCollision();
		void reset();
		void onCollision(Paddle* player1, Paddle* player2);

	};
}