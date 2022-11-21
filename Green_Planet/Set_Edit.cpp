#include"Game.hpp"

void Game::set_edit() {

	//スクロール・コントローラー

	//上
	scroll_contorller.push_back(Rect(150, 700, 100, 100));
	//下
	scroll_contorller.push_back(Rect(150, 900, 100, 100));
	//左
	scroll_contorller.push_back(Rect(50, 800, 100, 100));
	//右
	scroll_contorller.push_back(Rect(250, 800, 100, 100));

	//Edit_Type

	edit_type_select_bar = Rect(100, 30, 200, 70);

	//データの種類
	int type_number = 7;

	for (int i = 0; i < type_number; i++) {
		edit_type_select_bar_1.push_back(Rect(100, 30 + (70 * (i + 1)), 200, 70));
	}

	for (int i = 0; i < type_number; i++) {
		edit_type_select_seek_bar_1.push_back(Rect(100 - 50, 30 + (70 * (i + 1)), 50, 70));
	}


	//Edit ←→ Play

	edit_go_play = Rect(600,30,200,70);

	play_go_edit = Rect(600, 30, 200, 70);





	//タイプサンプル

	edit_sub_close = Rect(400,180,200,70);


	edit_type_sample = Rect(400,10,120,120);

		edit_block.push_back(Edit_Block(U"soil"));
		edit_block.push_back(Edit_Block(U"soil_grass"));
		edit_block.push_back(Edit_Block(U"soil_grass_left_cut"));
		edit_block.push_back(Edit_Block(U"soil_grass_right_cut"));
		edit_block.push_back(Edit_Block(U"soil_grass_double_cut"));
		edit_block.push_back(Edit_Block(U"break_block"));

		//edit_block.push_back(Edit_Block(U"move_block"));
		//edit_block.push_back(Edit_Block(U"move_block_2"));

		edit_enemy.push_back(Edit_Enemy(U"maru"));
		edit_enemy.push_back(Edit_Enemy(U"don"));
		edit_enemy.push_back(Edit_Enemy(U"pyou"));

		edit_event.push_back(Edit_Event(U"life_server"));
		edit_event.push_back(Edit_Event(U"save_server"));

	for (size_t i = 0; i < edit_block.size(); i++) {

		int x = int(i) % 10;
		int y = int(i) / 10;

		edit_select_block.push_back(Rect(360 + x * 120, 300 + y * 120, 120, 120));
	}

	for (size_t i = 0; i < edit_enemy.size(); i++) {

		int x = int(i) % 10;
		int y = int(i) / 10;

		edit_select_enemy.push_back(Rect(360 + x * 120, 300 + y * 120, 120, 120));
	}

	for (size_t i = 0; i < edit_event.size(); i++) {

		int x = int(i) % 10;
		int y = int(i) / 10;

		edit_select_event.push_back(Rect(360 + x * 120, 300 + y * 120, 120, 120));
	}


	//数字が入力



	int v = 0;

	edit_number_button.push_back(Edit_Number_Button(0, 1, -1));

	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {

			v++;
			edit_number_button.push_back(Edit_Number_Button(v, x, y));
		}
	}

	edit_number_button_enter = Rect(0 * 120 + 200, 3 * 120 + 500, 340, 100);

	edit_detail_close = Rect(400, 180, 200, 70);

	//Event_Detail

	edit_event_number_rect = Rect(1050,300,100,100);
	edit_event_start_rect = Rect(1050, 600, 100, 100);

}
