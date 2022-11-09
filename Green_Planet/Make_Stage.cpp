#include"Game.hpp"

void Game::make_stage() {

	for (auto b : block_data) {

		String name = b.get_name();
		int x = b.get_x() * Definition::block_size;
		int y = b.get_y() * Definition::block_size;
		int size = Definition::block_size;

		block.push_back(Block(name, x, y,size));
	}
}
