#include"Game.hpp"

void Game::draw_play() {

	draw_object();

	draw_UI();

	
}

void Game::draw_object() {

	for (auto& t : tile) {
		t.draw(scroll_x, scroll_y);
	}


	for (auto& b : block) {
		b.draw(scroll_x,scroll_y);
	}

	for (auto& e : event) {
		e.draw(scroll_x, scroll_y);
	}

	for (auto& e : enemy) {
		e.draw(scroll_x,scroll_y);
	}

	for (auto& i : item) {
		i.draw(scroll_x, scroll_y);
	}

	player.draw(scroll_x,scroll_y);


	for (auto& p : player_bullet) {
		p.draw(scroll_x, scroll_y);
	}
}

void Game::draw_UI() {

	//HP
	int hp = player.get_hp();
	font_50(hp).draw(10, 10);

	//Max_HP
	int max_hp = player.get_max_hp();
	font_50(max_hp).draw(100, 10);

}
