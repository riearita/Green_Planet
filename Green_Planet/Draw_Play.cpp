#include"Game.hpp"

void Game::draw_play() {

	draw_object();

	draw_UI();

	
}

void Game::draw_object() {

	//背景
	back.draw();

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


	TextureAsset(U"weapon_box").draw(30, 10);

	TextureAsset(U"bar_frame").draw(30 + 120 + 10, 10 + 5+5);
	

	int hp = player.get_hp();
	int max_hp = player.get_max_hp();

	double d_hp = hp;
	double d_max_hp = max_hp;
	
	int hp_bar_w = 250 * (d_hp / d_max_hp);
	const int hp_bar_h = 50;



	TextureAsset(U"hp_bar")(0, 0, hp_bar_w, hp_bar_h).draw(30+120+10, 10+5+5);

	//font_50(hp).draw(10, 200);
	//font_50(max_hp).draw(100, 200);


	//Energy

	TextureAsset(U"bar_frame").draw(30 + 120 + 10, 10 + 5 + 50 + 10-5);


	int e = weapon.get_energy();
	int max_e = weapon.get_max_energy();

	double d_e = e;
	double d_max_e = max_e;

	int energy_bar_w = 250 * (d_e / d_max_e);
	const int energy_bar_h = 50;



	TextureAsset(U"energy_bar")(0, 0, energy_bar_w, energy_bar_h).draw(30 + 120 + 10, 10 + 5 + 50 + 10-5);

}
