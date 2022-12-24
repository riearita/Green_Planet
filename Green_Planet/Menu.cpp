#include"Game.hpp"

void Game::update_menu() {

	const double d_time = Scene::DeltaTime();

	if (menu_scene == 0) {

		update_menu_main();
	}
	else if (menu_scene == 1) {

		update_menu_weapon();
	}
	else if (menu_scene == 2) {
		update_menu_item();
	}
	else if (menu_scene == 3) {
		
	}

	


}

void Game::draw_menu() {

	if (menu_scene == 0) {

		draw_menu_main();
	}
	else if (menu_scene == 1) {

		draw_menu_weapon();
	}
	else if (menu_scene == 2) {
		draw_menu_item();

	}

	
}

void Game::update_menu_main() {

	if (KeyLeft.down()) {
		menu_main_cur_x--;
	}
	else if (KeyRight.down()) {
		menu_main_cur_x++;
	}
	else if (KeyUp.down()) {
		menu_main_cur_y--;
	}
	else if (KeyDown.down()) {
		menu_main_cur_y++;
	}

	if (KeyZ.down()) {
		menu_scene = 1;
	}
}

void Game::draw_menu_main() {

	TextureAsset(U"menu_back").draw(0, 0);

	TextureAsset(U"menu_weapon_icon").draw(300, 300);
}

void Game::update_menu_weapon() {

}

void Game::draw_menu_weapon() {

}

void Game::update_menu_item() {

}

void Game::draw_menu_item() {

}

void Game::update_menu_setting() {

}

void Game::draw_menu_setting() {

}
