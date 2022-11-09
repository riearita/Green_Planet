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
}
