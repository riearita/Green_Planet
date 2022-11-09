#include"Game.hpp"

void Game::draw_edit() {

	draw_edit_object();

	draw_edit_line();

	draw_edit_scroll_controller();

}

void Game::draw_edit_line() {

	Array<Rect> rect;//Lineにすると軽くなるかも

	for (int x = 0; x < 20; x++) {//縦線(16+4)//両サイド分

		rect.push_back(Rect((x - 2) * 120, 0, 2, 1080 + 240));
	}

	for (int y = 0; y < 13; y++) {//横線(9+4)//両サイド分

		rect.push_back(Rect(-120, (y - 2) * 120, 1920 + 240, 2));
	}

	int line_adjust_x = int(scroll_x) % 120;
	int line_adjust_y = int(scroll_y) % 120;

	for (size_t i = 0; i < rect.size(); i++) {

		Rect rected;
		rected = rect[i].movedBy(-line_adjust_x, -line_adjust_y);
		rected.draw(Palette::Red);
	}
}

void Game::draw_edit_scroll_controller() {

    scroll_contorller[0].draw(Palette::White);
	FontAsset(U"uiFont_50")(U"↑").drawAt(150 + 50, 700 + 50, Palette::Red);

	scroll_contorller[1].draw(Palette::White);
	FontAsset(U"uiFont_50")(U"↓").drawAt(150 + 50, 900 + 50, Palette::Red);
	
	scroll_contorller[2].draw(Palette::White);
	FontAsset(U"uiFont_50")(U"←").drawAt(50 + 50, 800 + 50, Palette::Red);
	
	scroll_contorller[3].draw(Palette::White);
	FontAsset(U"uiFont_50")(U"→").drawAt(250 + 50, 800 + 50, Palette::Red);
}

void Game::draw_edit_object() {

	

	for (auto &b : block_data) {
		b.draw();
	}

	for (auto& e : enemy_data) {
		e.draw();
	}

	for (auto& i : item_data) {
		i.draw();
	}
}
