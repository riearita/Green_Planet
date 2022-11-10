#include"Game.hpp"

void Game::make_stage() {

	block.clear();
	enemy.clear();
	tile.clear();
	start_point.clear();

	for (auto& b : block_data) {

		String name = b.get_name();
		int x = b.get_x() * Definition::block_size;
		int y = b.get_y() * Definition::block_size;
		int size = Definition::block_size;

		block.push_back(Block(name, x, y,size));
	}

	for (auto& e : enemy_data) {

		String name = e.get_name();
		int x = e.get_x() * Definition::block_size;
		int y = e.get_y() * Definition::block_size;
		int size = Definition::block_size;

		enemy.push_back(Enemy(name, x, y));
	}

	for (auto& t : tile_data) {

		String name = t.get_name();
		int x = t.get_x() * Definition::block_size;
		int y = t.get_y() * Definition::block_size;
		int size = Definition::block_size;

		tile.push_back(Tile(name, x, y));
	}

	if (start_point.size() > 0) {

		int s_x = start_point[0].get_x() * Definition::block_size;
		int s_y = start_point[0].get_y() * Definition::block_size;

		player.set_pos_x(s_x);
		player.set_pos_y(s_y);
	}
}
