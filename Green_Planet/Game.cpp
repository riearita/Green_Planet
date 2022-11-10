#include"Game.hpp"

void Game::update() {

	switch (main_scene)
	{
	case 0:
		update_go_edit();
		update_play();
		break;
	case 1:
		
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
	case 100:
		draw_edit();
		break;
	default:
		break;
	}
}
