#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace GameBoundary
{
	class Boundary
	{
	private:
		RectangleShape topBoundary;
		RectangleShape bottomBoundary;
		RectangleShape leftBoundary;
		RectangleShape rightBoundary;
		RectangleShape centerLine;
		
		const float horizontal_boundary_width = 1920.0f;
		const float horizontal_boundary_height = 20.0f;

		const float vertical_boundary_width = 20.0f;
		const float vertical_boundary_height = 1080.0f;

		const float top_position_x = 0.0f;
		const float top_position_y = 0.0f;
		const float bottom_position_y = 1060.0f;

		const float left_position_x = 0.0f;
		const float right_position_x = 1900.0f;
		const float left_position_y = 0.0f;

		const Color boundary_color = Color::Blue;
		const Color center_line_color = Color::White;

		const float center_line_width = 10.0f;
		const float center_line_height = 1040.0f;

		const float center_line_position_x = 960.0f;
		const float center_line_position_y = 20.0f;

		void createTopBoundary();
		void createBottomBoundary();
		void createLeftBoundary();
		void createRightBoundary();

		void createCenterLine();
		

	public:
		Boundary();

		void render(RenderWindow* game_window);

	};
}