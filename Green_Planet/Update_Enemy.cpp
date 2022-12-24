#include"Enemy.hpp"

void Enemy::update_each() {

	if (name == U"maru") {
		update_maru();
	}
	else if (name == U"don") {
		update_don();
	}
	else if (name == U"huwa") {
		update_huwa();
	}
	else if (name == U"maru_quick") {
		update_maru_quick();
	}

}

void Enemy::update_maru() {

	if (scene == 0) {

		if (direction == 3) {
			pos.x -= 100 * d_time;
		}
		else if (direction == 4) {
			pos.x += 100 * d_time;
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

void Enemy::update_huwa() {

	if (count >= 3) {

		turn_direction();
		count = 0;
	}



	if (direction == 3) {
		pos.x -= 50 * d_time;
	}
	else if (direction == 4) {
		pos.x += 50 * d_time;
	}

	//表情
	if (scene == 0) {

		if (count_2 >= 1.5) {
			page = 1;
			scene = 1;
			count_2 = 0;
		}
	}
	else if (scene == 1) {

		if (count_2 >= 0.3) {
			page = 0;
			scene = 0;
			count_2 = 0;
			make_bullet = 1;
			make_bullet_x = 100;
			make_bullet_y = 80;
		}
	}

}

void Enemy::update_maru_quick() {

	if (scene == 0) {

		if (direction == 3) {
			pos.x -= 200 * d_time;
		}
		else if (direction == 4) {
			pos.x += 200 * d_time;
		}
	}

}
