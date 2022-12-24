#include"Game.hpp"

void Game::update() {

	//update_input();

	if (change_scene_on == false) {

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
			update_menu();
			break;
		case 100:
			update_edit();
			break;
		default:
			break;
		}
	}
	else if (change_scene_on == true) {

		update_change_scene();
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
	case 2:
		draw_menu();
		break;
	case 100:
		draw_edit();
		break;
	default:
		break;
	}

	if (change_scene_on == true) {
		draw_change_scene();
	}

	//Rect rect(0, 0, 1920, 1080);
	//rect.draw(Palette::Black);
}
