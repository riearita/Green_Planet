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

	edit_type_select_bar = Rect(100, 50, 150, 50);

	for (int i = 0; i < 3; i++) {
		edit_type_select_bar_1.push_back(Rect(100, 50 + (50 * i + 1), 150, 50));
	}
	

}
