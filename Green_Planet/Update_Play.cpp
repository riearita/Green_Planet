#include"Game.hpp"

void Game::update_play() {

	const double d_time = Scene::DeltaTime();

	
	player.update(d_time);

	player_vs_block();

	control_scroll();

	if (KeyE.down()) {
		go_edit();
	}
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


void Game::control_scroll() {

	const int WIN_W = 1920;
	const int WIN_H = 1080;

	int map_chip = 120;

	int map_chip_w = 100;
	int map_chip_h = 100;

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
	double bottom = MAP_Y;



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

void Game::go_edit() {
	main_scene = 100;
}
