#include"Game.hpp"

void Game::draw_play() {

	draw_object();
}

void Game::draw_object() {

	player.draw();

	for (auto& b : block) {
		b.draw();
	}

	for (auto& e : enemy) {
		e.draw();
	}

	for (auto& i : item) {
		i.draw();
	}
}
