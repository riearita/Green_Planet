#include"Game.hpp"

void Game::update() {

	switch (main_scene)
	{
	case 0:
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
		break;
	case 100:
		draw_edit();
		break;
	default:
		break;
	}
}
