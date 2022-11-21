#include"Game.hpp"

void Game::draw_play() {

	draw_object();

	draw_UI();

	
}

void Game::draw_object() {

	//背景
	back.draw(scroll_x, scroll_y);

	for (auto& t : tile) {
		if (t.get_layer() == 1) {
			t.draw(scroll_x, scroll_y);
		}
	}

	for (auto& t : tile) {
		if (t.get_layer() == 0) {
			t.draw(scroll_x, scroll_y);
		}
	}

	if (eco_block_draw == false) {

		for (auto& b : block) {
			b.draw(scroll_x, scroll_y);
		}
	}
	else if (eco_block_draw == true) {

		int x1 = scroll_x - 1920 / 2 - Definition::block_size;
		int x2 = scroll_x + 1920 + Definition::block_size;
		int y1 = scroll_y - 1080 / 2 - Definition::block_size;
		int y2 = scroll_y + 1080 + Definition::block_size;

		

		

		for (auto& b : block) {

			bool in = true;

			RectF rect = b.get_rect();

			if ((rect.x + Definition::block_size) < x1) {
				in = false;
			}
			else if (x2 < rect.x) {
				in = false;
			}
			else if ((rect.y + Definition::block_size) < y1) {
				in = false;
			}
			else if (y2 < rect.y) {
				in = false;
			}

			if (in == true) {
				b.draw(scroll_x, scroll_y);
			}
		}
	}

	for (auto& e : event) {
		e.draw(scroll_x, scroll_y);
	}

	for (auto& e : enemy) {
		
		if (e.get_white() == false) {
			e.draw(scroll_x, scroll_y);
		}
		else if (e.get_white() == true) {

		    const ScopedCustomShader2D shader{ psWhite };

			cbWhite->strength = e.get_white_count();

			Graphics2D::SetPSConstantBuffer(1, cbWhite);


			e.draw(scroll_x, scroll_y);
		}

		

	
	}

	for (auto& i : item) {
		i.draw(scroll_x, scroll_y);
	}

	player.draw(scroll_x,scroll_y);


	for (auto& p : player_bullet) {
		p.draw(scroll_x, scroll_y);
	}

	for (auto& e : enemy_bullet) {
		e.draw(scroll_x, scroll_y);
	}

	for (auto& m : my_effect) {
		m.draw(scroll_x, scroll_y);
	}

	for (auto& t : tile) {
		if (t.get_layer() == -1) {
			t.draw(scroll_x, scroll_y);
		}
	}
}

void Game::draw_UI() {


	TextureAsset(U"weapon_box").draw(30, 10);

	TextureAsset(U"shot_gun").draw(30, 10);

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


	double e = weapon.get_energy();
	double max_e = weapon.get_max_energy();

	double d_e = e;
	double d_max_e = max_e;

	int energy_bar_w = 250 * (d_e / d_max_e);
	const int energy_bar_h = 50;



	TextureAsset(U"energy_bar")(0, 0, energy_bar_w, energy_bar_h).draw(30 + 120 + 10, 10 + 5 + 50 + 10-5);

}
