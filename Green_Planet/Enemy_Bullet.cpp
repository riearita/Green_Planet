#include"Enemy_Bullet.hpp"

void Enemy_Bullet::first() {

	if (name == U"normal") {
		r = 30;
		delete_count = 1;
	}
}

void Enemy_Bullet::update(double d_time) {

	count += d_time;

	pos.x += cos(angle) * speed * d_time;
	pos.y += sin(angle) * speed * d_time;




}

void Enemy_Bullet::draw(double x, double y) {

	Circle(pos.x, pos.y, r).movedBy(-x, -y).draw(Palette::Green);

}

bool Enemy_Bullet::get_delete() {

	if (count >= delete_count) {
		return true;
	}

	return false;
}

