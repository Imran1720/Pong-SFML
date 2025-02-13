#include "../../Header/Gameplay/Paddle/Paddle.h"

namespace Gameplay
{
	Paddle::Paddle(float position_x, float position_y)
	{
		paddle_sprite.setSize(Vector2f(paddle_width, paddle_height));
		paddle_sprite.setPosition(position_x, position_y);
	}

	void Paddle::render(RenderWindow* game_window)
	{
		game_window->draw(paddle_sprite);
	}

	void Paddle::movePaddle(bool move_up_key_pressed, bool move_down_key_pressed)
	{
		if (move_up_key_pressed)
		{
			paddle_sprite.move(0, -paddle_speed);
		}

		if (move_down_key_pressed)
		{
			paddle_sprite.move(0, paddle_speed);
		}
	}

	void Paddle::update(bool move_up_key_pressed, bool move_down_key_pressed)
	{
		movePaddle(move_up_key_pressed, move_down_key_pressed);
	}
}