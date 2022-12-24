#include"Enemy.hpp"


void Enemy::first() {

	if (name == U"maru") {
		size_w = 80;
		size_h = 80;

		hp = 3;
	}
	else if (name == U"don") {
		size_w = 80;
		size_h = 80;

		hp = 3;
	}
	else if (name == U"huwa") {
		size_w = 200;
		size_h = 100;

		hp = 3;

		fly = true;

		use_page = true;
	}
	if (name == U"maru_quick") {
		size_w = 80;
		size_h = 80;

		hp = 8;
	}
}

void Enemy::update(double _d_time) {

	d_time = _d_time;

	set_old_pos();

	add_gravity();

	count += d_time;
	count_2 += d_time;

	update_each();

	

	if (turn_count > 0) {
		turn_count -= d_time;
	}

	if (white_time > 0) {
		white_time -= d_time;
	}

	pos += speed;
}

void Enemy::draw(double x,double y) {

	String image;

	if (use_page == false) {

		image = name + U"_" + Format(direction);

	}
	else if (use_page == true) {

		image = name + U"_" + Format(page) + U"_" + Format(direction);

	}
		TextureAsset(image).draw(pos.x - x, pos.y - y);
	
	
	

	//FontAsset(U"font_45")(Format(direction)).draw(pos.x - x, pos.y - y);
}



void Enemy::add_gravity() {

	if (fly == false) {

		//重力として下に加速度を与える
		speed.y += gravity * d_time;

		//加速制限
		if (speed.y >= 60) {
			speed.y = 60;
		}
	}
}

void Enemy::damage(int v) {
	hp -= v;

	white_time = 1;
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



