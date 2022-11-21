#include"Enemy.hpp"

void Enemy::update_each() {

	if (name == U"maru") {
		update_maru();
	}
	else if (name == U"don") {
		update_don();
	}

}

void Enemy::update_maru() {

	if (scene == 0) {

		if (direction == 3) {
			pos.x -= 50 * d_time;
		}
		else if (direction == 4) {
			pos.x += 50 * d_time;
		}
	}

}

void Enemy::update_don() {

	if (scene == 0) {

		if (count >= 3) {
			make_bullet = 0;
			make_bullet_x = 10;
			make_bullet_y = 40;

			count = 0;
		}

	}
}
