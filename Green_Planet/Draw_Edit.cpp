#include"Game.hpp"

void Game::draw_edit() {

	draw_edit_object();

	draw_edit_line();

	draw_edit_scroll_controller();

	draw_edit_type_select();

	draw_edit_go_play();

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

	if (edit_tile_seek == true) {
		for (auto& t : tile_data) {
			t.draw(scroll_x, scroll_y);
		}
	}

	if (edit_block_seek == true) {
		for (auto& b : block_data) {
			b.draw(scroll_x, scroll_y);
		}
	}

	if (edit_enemy_seek == true) {
		for (auto& e : enemy_data) {
			e.draw(scroll_x, scroll_y);
		}
	}

	
	for (auto& i : item_data) {
		i.draw();
	}

	

	if (edit_start_seek == true) {
		for (auto& s : start_point) {
			s.draw(scroll_x, scroll_y);
		}
	}
}

void Game::draw_edit_type_select() {

	

	//Edit_Type

	edit_type_select_bar.draw(Palette::White);

	font_50(edit_type).draw(100+10, 30, Palette::Green);

	if (edit_type_select_scene == 1) {

		for (size_t i = 0; i < edit_type_select_bar_1.size(); i++) {

			edit_type_select_bar_1[i].draw();
		}

		for (size_t i = 0; i < edit_type_select_bar_1.size(); i++) {

			String type = U"";

			switch (i)
			{
			case 0://block
				type = U"block";
				break;
			case 1:
				type = U"enemy";
				break;
			case 2:
				type = U"tile";
				break;
			case 3:
				type = U"start";
				break;
			default:
				break;
			}

			font_50(type).draw(100 + 10, 30 + ((i + 1) * 70), Palette::Green);

			
		}

		//Seekのほうも展開


		for (size_t i = 0; i < edit_type_select_seek_bar_1.size(); i++) {

			edit_type_select_seek_bar_1[i].draw();

			//seekの方にも線を引く
			Rect red_line(100 - 50, 30 + ((i + 1) * 70), 200 + 50, 5);
			red_line.draw(Palette::Red);
		}


	}


}


void Game::draw_edit_go_play() {

	edit_go_play.draw();

	font_50(U"play").draw(600 + 10, 30, Palette::Green);
}

void Game::draw_go_edit() {

	edit_go_play.draw();

	font_50(U"edit").draw(600 + 10, 30, Palette::Green);
}
