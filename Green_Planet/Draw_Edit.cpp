#include"Game.hpp"

void Game::draw_edit() {

	switch (edit_scene)
	{
	case 0:
		draw_edit_main();
		break;
	case 1:
		draw_edit_main();
		draw_edit_sub();
		break;
	case 2:
		draw_edit_main();
		draw_edit_detail();
		break;
	default:
		break;
	}

}

void Game::draw_edit_main() {

	back.draw(scroll_x, scroll_y);

	draw_edit_object();

	draw_edit_will_tile();

	draw_edit_line();

	draw_edit_scroll_controller();

	draw_edit_type_select();

	draw_edit_type_sample();

	draw_edit_go_play();
}

void Game::draw_edit_sub() {

	Rect rect(0, 0, 1920, 1080);
	rect.draw(ColorF(0, 0, 0, 0.5));

	edit_sub_close.draw();

	if (edit_type == U"block") {

		for (size_t i = 0; i < edit_select_block.size(); i++) {

			String name = edit_block[i].get_name();

			edit_select_block[i](TextureAsset(name)).draw();

		}
	}
	if (edit_type == U"enemy") {

		for (size_t i = 0; i < edit_select_enemy.size(); i++) {

			String name = edit_enemy[i].get_name() + U"_3";
			edit_select_enemy[i](TextureAsset(name)).draw();

		}
	}
	if (edit_type == U"event") {

		for (size_t i = 0; i < edit_select_event.size(); i++) {

			String name = edit_event[i].get_name();
			edit_select_event[i](TextureAsset(name)).draw();

		}
	}
}

void Game::draw_edit_detail() {

	Rect rect(0, 0, 1920, 1080);
	rect.draw(ColorF(0, 0, 0, 0.5));

	edit_detail_close.draw();

	if (edit_type == U"event") {

		font_50(U"number").draw(1200, 300);
		font_50(Format(event_data[edit_index].get_number())).draw(1200 + 300, 300);


		font_50(U"start").draw(1200, 600);
		font_50(Format(event_data[edit_index].get_start())).draw(1200 + 300, 600);

		edit_event_number_rect.draw();
		edit_event_start_rect.draw();

		if (edit_event_number == true) {
			edit_event_number_rect.draw(Palette::Yellow);
		}
		else if (edit_event_start == true) {
			edit_event_start_rect.draw(Palette::Yellow);
		}
	}

	draw_edit_number_input();
}

void Game::draw_edit_number_input() {

	//ボタン表示
	for (auto& b : edit_number_button) {
		b.draw();
	}

	//数字表示
	for (auto& b : edit_number_button) {

		int v = b.get_v();
		int x = b.get_x();
		int y = b.get_y();

		font_50(Format(v)).draw(x * 120 + 200+28, y * 120 + 500+10, Palette::Black);
		
	}

	//左上に表示
	font_50(Format(edit_input_number)).draw(300, 300);



	edit_number_button_enter.draw();

	font_50(U"Enter").draw(0 * 120 + 200+28, 3 * 120 + 500+10, Palette::Black);

}

void Game::draw_edit_line() {

	Array<Rect> rect;//Lineにすると軽くなるかも

	const int x_number = 1920 / Definition::block_size;

	for (int x = 0; x < (x_number + 6); x++) {//縦線(16+4)//両サイド分

		rect.push_back(Rect((x - 3) * Definition::block_size, 0, 2, 1080 + Definition::block_size * 3));
	}

	const int y_number= 1080 / Definition::block_size;

	for (int y = 0; y < (y_number+6); y++) {//横線(9+4)//両サイド分

		rect.push_back(Rect(-Definition::block_size, (y - 3) * Definition::block_size, 1920 + (Definition::block_size * 3), 2));
	}

	int line_adjust_x = int(scroll_x) % Definition::block_size;
	int line_adjust_y = int(scroll_y) % Definition::block_size;

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

	if (edit_tile_1_seek == true) {
		for (auto& t : tile_data) {
			if (t.get_layer() == 1) {
				t.draw(scroll_x, scroll_y);
			}
		}
	}

	if (edit_tile_0_seek == true) {
		for (auto& t : tile_data) {
			if (t.get_layer() == 0) {
				t.draw(scroll_x, scroll_y);
			}
		}
	}

	if (edit_block_seek == true) {
		for (auto& b : block_data) {
			b.draw(scroll_x, scroll_y);
		}
	}

	if (edit_tile_01_seek == true) {
		for (auto& t : tile_data) {
			if (t.get_layer() == -1) {
				t.draw(scroll_x, scroll_y);
			}
		}
	}

	if (edit_event_seek == true) {
		for (auto& e : event_data) {
			e.draw(scroll_x, scroll_y);
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
				type = U"tile_0";
				break;
			case 3:
				type = U"tile_1";
				break;
			case 4:
				type = U"tile_-1";
				break;
			case 5:
				type = U"event";
				break;
			case 6:
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

void Game::draw_edit_type_sample() {

	String name = U"";

	if (edit_type == U"block") {
		name = edit_block_name;
	}
	else if (edit_type == U"enemy") {
		name = edit_enemy_name + U"_3";
	}
	else if (edit_type == U"") {
		
	}

	

	edit_type_sample(TextureAsset(name)).draw();


}

void Game::draw_edit_will_tile() {

	int x = edit_cur_x * Definition::block_size;
	int y = edit_cur_y * Definition::block_size;


	if (edit_type == U"tile_0" or edit_type == U"tile_1" or edit_type == U"tile_-1") {

		TextureAsset(edit_tile_name).draw(x - scroll_x, y - scroll_y, ColorF(1.0, 0.5));


	}
}
