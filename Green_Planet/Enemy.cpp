#include"Enemy.hpp"

void Enemy::first() {

	if (name == U"maru") {
		size_w = 80;
		size_h = 80;

		hp = 5;
	}
}

void Enemy::update(double _d_time) {

	d_time = _d_time;

	set_old_pos();

	add_gravity();


	if (name == U"maru") {
		update_maru();
	}

	if (turn_count > 0) {
		turn_count -= d_time;
	}

	if (first_direction_guard_count > 0) {
		first_direction_guard_count -= d_time;
		if (first_direction_guard_count < 0) {
			first_direction_guard_count = 0;
		}
	}

	pos += speed;
}

void Enemy::draw(double x,double y) {

	String image = name + U"_" + Format(direction);

	TextureAsset(image).draw(pos.x - x, pos.y - y);

	FontAsset(U"font_45")(Format(direction)).draw(pos.x - x, pos.y - y);
}

void Enemy::add_gravity() {

	//重力として下に加速度を与える
	speed.y += gravity * d_time;

	//加速制限
	if (speed.y >= 60) {
		speed.y = 60;
	}
}

void Enemy::damage(int v) {
	hp -= v;
	if (hp < 0) {
		hp = 0;
	}
}

void Enemy::turn_direction() {



		if (direction == 3) {
			
			direction = 4;
		}
		else if (direction == 4) {
			
			direction = 3;
		}


	
}

void Enemy::turn_direction_cliff() {

	

		if (turn_count <= 0) {

			if (direction == 3) {
				direction = 4;
			}
			else if (direction == 4) {
				direction = 3;
			}

			turn_count = 1;
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
	else if (scene == 1) {

	}
}
