#include"Game.hpp"

void Game::draw_outline_text(String _font, String text, int x, int y, Color color) {

	//輪郭の太さ
	const double outlineScale = 0.6;

	//輪郭の色
	const Color outlineColor{244, 244, 244 };


	const double fontSize = 120;

	FontAsset(_font)(text).draw(TextStyle::Outline(outlineScale, outlineColor), x, y, color);

}
