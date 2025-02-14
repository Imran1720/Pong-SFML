#include "../../Header/Gameplay/Ball/Ball.h"
#include <iostream>

namespace Gameplay
{
	Ball::Ball()
	{
		loadTexture();
		initializeVariables();
	}

	void Ball::render(RenderWindow* game_window)
	{
		game_window->draw(pong_ball_sprite);
	}

	void Ball::handlePaddleCollision(Paddle* player1, Paddle* player2)
	{
		const RectangleShape& player1Paddle = player1->getPaddleSprite();
		const RectangleShape& player2Paddle = player2->getPaddleSprite();
	
		FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();
		FloatRect player1_bounds = player1Paddle.getGlobalBounds();
		FloatRect player2_bounds = player2Paddle.getGlobalBounds();

		if (ball_bounds.intersects(player1_bounds) && velocity.x < 0)
		{
			velocity.x = -velocity.x;
		}
		if (ball_bounds.intersects(player2_bounds) && velocity.x > 0)
		{
			velocity.x = -velocity.x;
		}
	}

	void Ball::handleBoundaryCollision()
	{
		FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();
		if ((ball_bounds.top <= top_boundary && velocity.y < 0) ||
			(ball_bounds.top + ball_bounds.height >= bottom_boundary && velocity.y > 0))
		{
			velocity.y = -velocity.y; 
		}
	}

	void Ball::handleOutofBoundCollision()
	{
		FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();

		if (ball_bounds.left <= left_boundary)
		{
			reset();
		}

		if (ball_bounds.left + ball_bounds.width >= right_boundary)
		{
			//std::cout << "right boundary touched"<<std::endl;
			reset();
		}
	}

	void Ball::reset()
	{
		current_state = BallState::Idle;
		pong_ball_sprite.setPosition(Vector2f(center_position_x, center_position_y));
		velocity = Vector2f(ball_speed, ball_speed);
	}

	void Ball::onCollision(Paddle* player1, Paddle* player2)
	{
		handleBoundaryCollision();
		handlePaddleCollision(player1, player2);
		handleOutofBoundCollision();
	}

	void Ball::loadTexture()
	{
		if (!pong_ball_texture.loadFromFile(texture_path))
		{
			throw std::runtime_error("Failed to load ball texture");
		}
	}

	void Ball::initializeVariables()
	{
		pong_ball_texture.setSmooth(true);
		pong_ball_sprite.setTexture(pong_ball_texture);
		pong_ball_sprite.setScale(scale_x, scale_y);
		pong_ball_sprite.setPosition(Vector2f(position_x, position_y));

		current_state = BallState::Idle;
	}

	void Ball::move(TimeService* time_service)
	{
		updateDelayTime(time_service->getDeltaTime());
		if (current_state == BallState::Moving)
		{
			pong_ball_sprite.move(velocity * time_service->getDeltaTime() * speed_multiplier);
		}
	}

	void Ball::update(Paddle* player1, Paddle* player2,TimeService* time_service)
	{
		move(time_service);
		onCollision(player1, player2);
	}

	void Ball::updateDelayTime(float delta_time)
	{
		if (current_state == BallState::Idle)
		{
			elapsed_delay_time += delta_time;
			if (elapsed_delay_time >= delay_duration)
			{
				current_state = BallState::Moving;
				elapsed_delay_time = 0;

			}
			else
			{
				return;
			}
		}
	}
}