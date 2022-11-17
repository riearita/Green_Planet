#include"Game.hpp"

void Game::update() {

	//update_input();

	switch (main_scene)
	{
	case 0:
		update_go_edit();
		update_play();
		break;
	case 1:
		update_event();
		break;
	case 2:
		break;
	case 100:
		update_edit();
		break;
	default:
		break;
	}
}

void Game::draw() {

	switch (main_scene)
	{
	case 0:
		draw_play();
		draw_go_edit();
		break;
	case 1:
		draw_play();
		draw_event();
		break;
	case 100:
		draw_edit();
		break;
	default:
		break;
	}

	//Rect rect(0, 0, 1920, 1080);
	//rect.draw(Palette::Black);
}
