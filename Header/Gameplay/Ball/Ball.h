#pragma once
#include "../../Header/Gameplay/Paddle/Paddle.h"
#include "../../Header/Utility/TimeService.h"
#include <SFML/Graphics.hpp>

using namespace Utility;
using namespace sf;

 enum class BallState
{
	Idle,
	Moving
};

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

		float speed_multiplier = 50.0f;
		float ball_speed = 10.0f;
		Vector2f velocity = Vector2f(ball_speed,ball_speed);

		float elapsed_delay_time = 0.0f;
		float delay_duration = 2.0f;
		BallState current_state;

		bool had_left_collision = false;
		bool had_right_collision = false;


		void loadTexture();
		void initializeVariables();
		void move(TimeService* time_service);
		void updateDelayTime(float delta_time);

	public:
		Ball();
		void update(Paddle* player1, Paddle* player2,TimeService* time_service);
		void render(RenderWindow* game_window);
		void handlePaddleCollision(Paddle* player1, Paddle* player2);
		void handleBoundaryCollision();
		void handleOutofBoundCollision();
		void reset();
		void onCollision(Paddle* player1, Paddle* player2);

		bool isLeftCollisionOccurred();
		void updateLeftCollisionState(bool value);

		bool isRightCollisionOccurred();
		void updateRightCollisionState(bool value);

	};
}