#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

namespace UI
{
	class UIService
	{
	private:
		Font font;

		Text left_score_text;
		Text right_score_text;
		string texture_path = "Assets/Fonts/Aloevera-OVoWO.ttf";
		int font_size = 40;
		Color font_color = Color::White;

		string initial_string = "00";

		float left_score_position_x = 880.0f;
		float left_score_position_y = 20.0f;

		float right_score_position_x = 1000.0f;
		float right_score_position_y = 20.0f;

		int player1_score = 0;

	public:
		UIService();
		void loadFontTexture();
		void createLeftScoreText();
		void createRightScoreText();
		void render(RenderWindow* game_window);
	};
}