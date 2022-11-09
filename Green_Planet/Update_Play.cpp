#include"Game.hpp"

void Game::update_play() {

	const double d_time = Scene::DeltaTime();

	
	player.update(d_time);

	player_vs_block();
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

				//プレイヤーの下の辺をブロックの上に合わせる
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
			}
			else if (left == true) {
				player.set_pos_x(b.get_rect().x + b.get_rect().w);
			}

			if (bottom == true) {

				player.set_pos_y(b.get_rect().y - player.get_size());

				//地上にいる判定にする
				player.set_ground(true);
			}
			else if (top == true) {
				player.set_pos_y(b.get_rect().y + b.get_rect().h);
			}

		
		}
	}
}
