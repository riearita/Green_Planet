#include"Enemy.hpp"

void Enemy::first() {

	if (name == U"puni") {
		size_w = 120;
		size_h = 120;

		hp = 3;
	}
}

void Enemy::update(double _d_time) {

	d_time = _d_time;

	set_old_pos();

	add_gravity();

	pos += speed;
}

void Enemy::draw(double x,double y) {
	TextureAsset(name).draw(pos.x - x, pos.y - y);
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
