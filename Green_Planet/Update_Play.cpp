#include"Game.hpp"

void Game::update_play() {

	const double d_time = Scene::DeltaTime();

	
	player.update(d_time);

	for (auto& e : enemy) {
		e.update(d_time);
	}

	for (auto& p : player_bullet) {
		p.update(d_time);
	}

	weapon.update(d_time);

	//VS_Block
	player_vs_block();
	enemy_vs_block();

	use_weapon();

	//VS_Player_Bullet
	player_bullet_vs_block();
	player_bullet_vs_enemy();

	death_enemy();

	player_vs_enemy();
	player_vs_item();

	delete_player_bullet();
	delete_enemy_bullet();

	check_event();

	control_scroll();

	
}

void Game::player_vs_block() {

	player.set_ground(false);

	RectF old_rect = player.get_old_rect();
	RectF rect = player.get_rect();
	double move_x = rect.x - old_rect.x;
	double move_y = rect.y - old_rect.y;

	//x座標だけ動かしたもの・y座標だけ動かしたもの
	RectF rect_x = old_rect.movedBy(move_x, 0);
	RectF rect_y = old_rect.movedBy(0, move_y);

	for (auto& b : block) {

		if (player.get_rect().intersects(b.get_rect())) {

			bool right = 0;
			bool left = 0;
			bool top = 0;
			bool bottom = 0;

			//右
			if (move_x > 0) {

				//プレイヤーの右の辺をブロックの左に合わせる
				if (rect_x.intersects(b.get_rect())) {
					right = true;
				}
			}
			//左
			else if (move_x < 0) {

				//プレイヤーの右の辺をブロックの左に合わせる
				if (rect_x.intersects(b.get_rect())) {
					left = true;
				}
			}

			//下
			if (move_y > 0) {

				//プレイヤーの下の辺をブロックの上に合わせる
				if (rect_y.intersects(b.get_rect())) {
					bottom = true;
				}
			}//上
			else if (move_y < 0) {

				//プレイヤーの上の辺をブロックの下に合わせる
				if (rect_y.intersects(b.get_rect())) {
					top = 1;
				}
			}


			//斜め判定
			if (left == true or right == true) {
				if (top == true or bottom == true) {
					left = false;
					right = false;
				}
			}

			if (right == true) {
				player.set_pos_x(b.get_rect().x - player.get_size());
				player.zero_inertia();
				
			}
			else if (left == true) {
				player.set_pos_x(b.get_rect().x + b.get_rect().w);
				player.zero_inertia();
				
			}
			

			if (bottom == true) {

				player.set_pos_y(b.get_rect().y - player.get_size());

				//地上にいる判定にする
				player.set_ground(true);

				//重力加速度を0にする
				player.zero_speed_y();

				//コヨーテタイム
				player.set_coyote_time(0.2);
			}
			else if (top == true) {
				player.set_pos_y(b.get_rect().y + b.get_rect().h);

				//重力加速度を0にする
				player.zero_speed_y();
			}

		
		}
	}
}

void Game::player_bullet_vs_block() {

	player_bullet.remove_if([&](Player_Bullet p) {

		for (size_t i = 0; i < block.size(); i++) {

			if (block[i].get_rect().intersects(p.get_circle())) {
				return true;
			}
		}

		return false;

			});
}

void Game::enemy_vs_block() {

	for (auto& e : enemy) {

		e.set_ground(false);

		RectF old_rect = e.get_old_rect();
		RectF rect = e.get_rect();
		double move_x = rect.x - old_rect.x;
		double move_y = rect.y - old_rect.y;

		//x座標だけ動かしたもの・y座標だけ動かしたもの
		RectF rect_x = old_rect.movedBy(move_x, 0);
		RectF rect_y = old_rect.movedBy(0, move_y);

		for (auto& b : block) {

			if (e.get_rect().intersects(b.get_rect())) {

				bool right = 0;
				bool left = 0;
				bool top = 0;
				bool bottom = 0;

				//右
				if (move_x > 0) {

					//プレイヤーの右の辺をブロックの左に合わせる
					if (rect_x.intersects(b.get_rect())) {
						right = true;
					}
				}
				//左
				else if (move_x < 0) {

					//プレイヤーの右の辺をブロックの左に合わせる
					if (rect_x.intersects(b.get_rect())) {
						left = true;
					}
				}

				//下
				if (move_y > 0) {

					//プレイヤーの下の辺をブロックの上に合わせる
					if (rect_y.intersects(b.get_rect())) {
						bottom = true;
					}
				}//上
				else if (move_y < 0) {

					//プレイヤーの上の辺をブロックの下に合わせる
					if (rect_y.intersects(b.get_rect())) {
						top = 1;
					}
				}

				//斜め判定
				if (left == true or right == true) {
					if (top == true or bottom == true) {
						left = false;
						right = false;
					}
				}

				if (right == true) {
					e.set_pos_x(b.get_rect().x - e.get_size_w());
					
				}
				else if (left == true) {
					e.set_pos_x(b.get_rect().x + b.get_rect().w);
					
				}


				if (bottom == true) {

					e.set_pos_y(b.get_rect().y - e.get_size_h());

					//地上にいる判定にする
					e.set_ground(true);

					//重力加速度を0にする
					e.zero_speed_y();

					
				}
				else if (top == true) {
					e.set_pos_y(b.get_rect().y + b.get_rect().h);

					//重力加速度を0にする
					e.zero_speed_y();
				}


			}
		}
	}
}

void Game::use_weapon() {

	String name = weapon.get_name();
	Vec2 pos = player.get_pos();
	bool can_use = weapon.get_can_use();
	int direction = player.get_direction();

	

	if (name == U"shot_gun") {

		if (can_use == true) {

			if (KeyX.pressed()) {

				double speed = 950;
				double angle = 0;
				int power = 1;

				if (direction == 3) {
					angle = 180;
				}
				else if (direction == 4) {
					angle = 0;
				}


				player_bullet.push_back(Player_Bullet(U"normal", pos.x, pos.y, speed, angle,power));

				weapon.set_cool_time(0.2);
			}
		}
		
	}
}

void Game::player_vs_enemy() {

	for (auto& e : enemy) {

		if (player.get_hit_rect().intersects(e.get_hit_rect())) {

			int damage = e.get_hit_damage();
			player.damage(damage);
		}
	}
}

void Game::player_bullet_vs_enemy() {

	player_bullet.remove_if([&](Player_Bullet p) {

		int power = p.get_power();

		for (size_t i = 0; i < enemy.size(); i++) {

			if (enemy[i].get_hit_rect().intersects(p.get_circle())) {
				enemy[i].damage(power);
				return true;
			}
		}

		return false;

			});
}

void Game::death_enemy() {

	enemy.remove_if([&](Enemy e) {

		if (e.get_hp() <= 0) {
			return true;
		}

		return false;

			});
}

void Game::player_vs_item() {

	item.remove_if([&](Item i) {

		if (player.get_hit_rect().intersects(i.get_hit_rect())) {
			return true;
		}

		return false;

			});
}

void Game::delete_player_bullet() {

	player_bullet.remove_if([&](Player_Bullet b) {

		if (b.get_delete() == true) {
			return true;
		}
		return false;

			});
}

void Game::delete_enemy_bullet() {

	enemy_bullet.remove_if([&](Enemy_Bullet b) {

		if (b.get_delete() == true) {
			return true;
		}
		return false;

			});
}

void Game::control_scroll() {

	const int WIN_W = 1920;
	const int WIN_H = 1080;

	//まだ不確定
	int map_chip = 100;

	int map_chip_w = Definition::block_size;
	int map_chip_h =Definition::block_size;

	const int MAP_X = map_chip * map_chip_w;
	const int MAP_Y = map_chip * map_chip_h;



	//プレイヤーの座標を取得
	RectF p_r = player.get_rect();

	//通常スクロール
	scroll_x = p_r.x + p_r.w / 2 - WIN_W / 2;
	scroll_y = p_r.y + p_r.h / 2 - WIN_H / 2;

	//マップ一番左
	double left = 0;

	//マップ一番右
	double right = MAP_X;

	//マップ一番上
	double top = 0;

	//マップ一番下
	double bottom = stage_under_line;



	//以下画面端、プレイヤーの中心を基準にスクロール



	//左スクロール停止
	if (p_r.x + p_r.w / 2 < left + WIN_W / 2) {
		scroll_x = left;
	}

	//右スクロール停止
	if (p_r.x + p_r.w / 2 > right - WIN_W / 2) {
		scroll_x = right - WIN_W;
	}

	//上スクロール停止
	if (p_r.y + p_r.h / 2 < top + WIN_H / 2) {
		scroll_y = top;
	}

	//下スクロール停止
	if (p_r.y + p_r.h / 2 > bottom - WIN_H / 2) {
		scroll_y = bottom - WIN_H;
	}
}

void Game::check_event() {

	if (KeyDown.down()) {

		if (player.get_ground() == true) {

			

			for (auto& e : event) {
				//調べて起動なら
				if (e.get_start() == 0) {

					//触れているか
					if (player.get_rect().intersects(e.get_rect())) {

						event_number = e.get_number();
						main_scene = 1;

						//慣性を切る
						player.zero_inertia();
					}
				}
			}
		}
	}
}











void Game::go_edit() {
	main_scene = 100;
}
