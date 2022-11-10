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

	for (int i = 0; i < 4; i++) {
		edit_type_select_bar_1.push_back(Rect(100, 30 + (70 * (i + 1)), 200, 70));
	}

	for (int i = 0; i < 4; i++) {
		edit_type_select_seek_bar_1.push_back(Rect(100 - 50, 30 + (70 * (i + 1)), 50, 70));
	}


	//Edit ←→ Play

	edit_go_play = Rect(600,30,200,70);

	play_go_edit = Rect(600, 30, 200, 70);

}
