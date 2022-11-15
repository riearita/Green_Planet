#include"Game.hpp"

void Game::update_edit() {

	switch (edit_scene)
	{
	case 0:
		update_edit_main();
		break;
	case 1:
		update_edit_sub();
		break;
	case 2:
		update_edit_detail();
		break;
	default:
		break;
	}	
}

void Game::update_edit_main() {

	edit_cur_x = (Cursor::Pos().x + scroll_x) / Definition::block_size;
	edit_cur_y = (Cursor::Pos().y + scroll_y) / Definition::block_size;
	edit_lock = false;


	update_edit_scroll_controller();

	update_edit_type_select();

	update_edit_go_play();

	update_edit_type_sample();

	if (edit_lock_press == true) {

		edit_lock = true;

		if (MouseL.pressed() != true) {
			edit_lock_press = false;
		}
	}

	if (edit_lock == false) {
		write_edit();
		erase_edit();
	}

	


	if (KeyS.down()) {
		save_edit();
	}
}

void Game::update_edit_sub() {

	if (edit_sub_close.leftClicked()) {
		edit_scene = 0;
		edit_lock_press = true;
	}


	if (edit_type == U"block") {

		for (size_t i = 0; i < edit_select_block.size();i++) {

			if (edit_select_block[i].leftClicked()) {
				
				edit_block_name = edit_block[i].get_name();
			}
		}
	}
	else if (edit_type == U"enemy") {

		
	}
}

void Game::update_edit_detail() {

	if (edit_detail_close.leftClicked()) {
		edit_scene = 0;
		edit_lock_press = true;
	}

	if (edit_type == U"event") {

		edit_update_number_input();

		if (edit_number_button_enter.leftClicked()) {

			if (edit_input_number != U"") {

				int v = Parse<int>(edit_input_number);

				if (edit_event_number == true) {
					event_data[edit_index].set_number(v);
				}
				else if (edit_event_start == true) {
					event_data[edit_index].set_start(v);
				}

				edit_input_number = U"";
			}
		}

		if (edit_event_number_rect.leftClicked()) {

			edit_event_number = true;

			edit_event_start = false;	
		}

		if (edit_event_start_rect.leftClicked()) {

			edit_event_start = true;

			edit_event_number = false;
		}
	}
}

void Game::edit_update_number_input() {

	for (auto& b : edit_number_button) {

		if (b.get_rect().leftClicked()) {

			int v = b.get_v();
			String s_v = Format(v);
			edit_input_number += s_v;
		}
	}
}


void Game::update_edit_scroll_controller() {

	int speed = 8;

	if (scroll_contorller[0].leftPressed()) {
		scroll_y -= speed;
		edit_lock = true;
	}
	else if (scroll_contorller[1].leftPressed()) {
		scroll_y += speed;
		edit_lock = true;
	}
	else if (scroll_contorller[2].leftPressed()) {
		scroll_x -= speed;
		edit_lock = true;
	}
	else if (scroll_contorller[3].leftPressed()) {
		scroll_x += speed;
		edit_lock = true;
	}

	if (scroll_x < 0) {
		scroll_x = 0;
	}

	if (scroll_y < 0) {
		scroll_y = 0;
	}

}

void Game::write_edit() {

	if (edit_type == U"block") {
		write_block_edit();
	}
	else if (edit_type == U"enemy") {
		write_enemy_edit();
	}
	else if (edit_type == U"tile") {
		write_tile_edit();
	}
	else if (edit_type == U"event") {
		write_event_edit();
	}
	else if (edit_type == U"start") {
		write_start_edit();
	}
}

void Game::erase_edit() {

	if (edit_type == U"block") {
		erase_block_edit();
	}
	else if (edit_type == U"enemy") {
		erase_enemy_edit();
	}
	else if (edit_type == U"tile") {
		erase_tile_edit();
	}
	else if (edit_type == U"event") {
		erase_event_edit();
	}
	else if (edit_type == U"start") {
		erase_start_edit();
	}
}

void Game::write_block_edit() {


	if (MouseL.pressed()) {//ペン
	
		int exist = 0;

		for (size_t i = 0; i < block_data.size(); i++) {

			int x = block_data[i].get_x();
			int y = block_data[i].get_y();

			if (edit_cur_x == x && edit_cur_y == y) {//すでにある
				exist = 1;

				block_data[i].set_name(edit_block_name);
			}
		}

		if (exist == 0) {//まだない

			block_data.push_back(Block_Data(edit_block_name, edit_cur_x, edit_cur_y));
		}
	}
}

void Game::erase_block_edit() {

	if (MouseR.pressed()) {

		block_data.remove_if([&](Block_Data d) {

			int x = d.get_x();
			int y = d.get_y();

			if (edit_cur_x == x and edit_cur_y == y) {
				return true;
			}

			return false;

			});
	}
}

void Game::write_enemy_edit() {

	if (MouseL.pressed()) {//ペン

		int exist = 0;

		for (size_t i = 0; i < enemy_data.size(); i++) {

			int x = enemy_data[i].get_x();
			int y = enemy_data[i].get_y();

			if (edit_cur_x == x && edit_cur_y == y) {//すでにある
				exist = 1;

				enemy_data[i].set_name(edit_enemy_name);
			}
		}

		if (exist == 0) {//まだない

			enemy_data.push_back(Enemy_Data(edit_enemy_name, edit_cur_x, edit_cur_y));
		}
	}
}

void Game::erase_enemy_edit() {

	if (MouseR.pressed()) {

		enemy_data.remove_if([&](Enemy_Data e) {

			int x = e.get_x();
			int y = e.get_y();

			if (edit_cur_x == x and edit_cur_y == y) {
				return true;
			}

			return false;

			});
	}
}

void Game::write_tile_edit() {

	if (MouseL.pressed()) {//ペン

		int exist = 0;

		for (size_t i = 0; i < tile_data.size(); i++) {

			int x = tile_data[i].get_x();
			int y = tile_data[i].get_y();

			if (edit_cur_x == x && edit_cur_y == y) {//すでにある
				exist = 1;

				tile_data[i].set_name(edit_tile_name);
			}
		}

		if (exist == 0) {//まだない

			tile_data.push_back(Tile_Data(edit_tile_name, edit_cur_x, edit_cur_y));
		}
	}
}

void Game::erase_tile_edit() {

	if (MouseR.pressed()) {

		tile_data.remove_if([&](Tile_Data t) {

			int x = t.get_x();
			int y = t.get_y();

			if (edit_cur_x == x and edit_cur_y == y) {
				return true;
			}

			return false;

			});
	}
}

void Game::write_event_edit() {

	if (MouseL.down()) {//ペン

		int exist = 0;

		for (size_t i = 0; i < event_data.size(); i++) {

			int x = event_data[i].get_x();
			int y = event_data[i].get_y();

			if (edit_cur_x == x && edit_cur_y == y) {//すでにある

				exist = 1;

				edit_scene = 2;
				edit_index = i;
			}
		}

		if (exist == 0) {//まだない

			event_data.push_back(Event_Data(edit_event_name, edit_cur_x, edit_cur_y));
		}
	}
}

void Game::erase_event_edit() {

	if (MouseR.pressed()) {

		event_data.remove_if([&](Event_Data e) {

			int x = e.get_x();
			int y = e.get_y();

			if (edit_cur_x == x and edit_cur_y == y) {
				return true;
			}

			return false;

			});
	}
}


void Game::write_start_edit() {

	if (MouseL.pressed()) {//ペン

		int exist = 0;

		for (size_t i = 0; i < start_point.size(); i++) {

			int x = start_point[i].get_x();
			int y = start_point[i].get_y();

			if (edit_cur_x == x && edit_cur_y == y) {//すでにある

			

				start_point.clear();
			}
		}

		

		start_point.push_back(Start_Point(U"start", edit_cur_x, edit_cur_y));
		


	}
}

void Game::erase_start_edit() {

	if (MouseR.pressed()) {

		start_point.remove_if([&](Start_Point s) {

			int x = s.get_x();
			int y = s.get_y();

			if (edit_cur_x == x and edit_cur_y == y) {
				return true;
			}

			return false;

			});
	}
}


void Game::update_edit_type_select() {

	if (edit_type_select_scene == 0) {

		if (edit_type_select_bar.leftClicked()) {
			edit_type_select_scene = 1;
			edit_lock_press = true;
		}
	}
	else if (edit_type_select_scene == 1) {

		if (edit_type_select_bar.leftClicked()) {
			edit_type_select_scene = 0;
			edit_lock_press = true;
		}


		for (size_t i = 0; i < edit_type_select_bar_1.size();i++) {

			if (edit_type_select_bar_1[i].leftClicked()) {

				edit_type_select_scene = 0;
				edit_lock_press = true;

				switch (i)
				{
				case 0://block
					edit_type = U"block";
					break;
				case 1://Enemy
					edit_type = U"enemy";
					break;
				case 2://Tile
					edit_type = U"tile";
					break;
				case 3://Tile
					edit_type = U"event";
					break;
				case 4://Start_Point
					edit_type = U"start";
					break;
				default:
					break;
				}
			}
		}

		//Seek

		for (size_t i = 0; i < edit_type_select_seek_bar_1.size(); i++) {

			if (edit_type_select_seek_bar_1[i].leftClicked()) {

				
				edit_lock_press = true;

				switch (i)
				{
				case 0://block
					if (edit_block_seek == false) {
						edit_block_seek = true;
					}
					else {
						edit_block_seek = false;
					}
					break;
				case 1://Enemy
					if (edit_enemy_seek == false) {
						edit_enemy_seek = true;
					}
					else {
						edit_enemy_seek = false;
					}
					break;
				case 2://Tile
					if (edit_tile_seek == false) {
						edit_tile_seek = true;
					}
					else {
						edit_tile_seek = false;
					}
					break;
				case 3://Start_Point
					if (edit_start_seek == false) {
						edit_start_seek = true;
					}
					else {
						edit_start_seek = false;
					}
					break;
				default:
					break;
				}
			}
		}
	}
}

void Game::update_edit_go_play() {

	if (edit_go_play.leftClicked()) {
		main_scene = 0;
		save_edit();
		load_stage();
		make_stage();

		edit_lock = true;
		
	}
}

void Game::update_go_edit() {

	if (play_go_edit.leftClicked()) {
		main_scene = 100;
		edit_lock_press = true;
	}
}

void Game::update_edit_type_sample() {

	if(edit_type_sample.leftClicked()) {
		edit_scene = 1;
		edit_lock = true;
	}
}

void Game::save_edit() {


	{
		String adress = U"stage/" + stage + U"/block.bin";
	

		// バイナリファイルをオープン
		Serializer<BinaryWriter> Writer{ adress };

		if (not Writer) // もしオープンに失敗したら
		{
			throw Error{ U"Failed to open " + adress };
		}

		// シリアライズに対応したデータを記録
		Writer(block_data);

	}

	{
		String adress = U"stage/" + stage + U"/enemy.bin";


		// バイナリファイルをオープン
		Serializer<BinaryWriter> Writer{ adress };

		if (not Writer) // もしオープンに失敗したら
		{
			throw Error{ U"Failed to open " + adress };
		}

		// シリアライズに対応したデータを記録
		Writer(enemy_data);

	}

	{
		String adress = U"stage/" + stage + U"/start.bin";


		// バイナリファイルをオープン
		Serializer<BinaryWriter> Writer{ adress };

		if (not Writer) // もしオープンに失敗したら
		{
			throw Error{ U"Failed to open " + adress };
		}

		// シリアライズに対応したデータを記録
		Writer(start_point);

	}

	{
		String adress = U"stage/" + stage + U"/tile.bin";


		// バイナリファイルをオープン
		Serializer<BinaryWriter> Writer{ adress };

		if (not Writer) // もしオープンに失敗したら
		{
			throw Error{ U"Failed to open " + adress };
		}

		// シリアライズに対応したデータを記録
		Writer(tile_data);

	}

	{
		String adress = U"stage/" + stage + U"/event.bin";


		// バイナリファイルをオープン
		Serializer<BinaryWriter> Writer{ adress };

		if (not Writer) // もしオープンに失敗したら
		{
			throw Error{ U"Failed to open " + adress };
		}

		// シリアライズに対応したデータを記録
		Writer(event_data);

	}
}

