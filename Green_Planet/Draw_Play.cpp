#include"Game.hpp"

void Game::draw_play() {

	draw_object();
}

void Game::draw_object() {

	player.draw(scroll_x,scroll_y);

	for (auto& b : block) {
		b.draw(scroll_x,scroll_y);
	}

	for (auto& e : enemy) {
		e.draw(scroll_x,scroll_y);
	}

	for (auto& i : item) {
		i.draw();
	}
}
