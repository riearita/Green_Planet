#include"Game.hpp"

void Game::set_debug() {

	load_stage();

	main_scene = 0;


	if (main_scene == 0) {
		make_stage();
	}
}
