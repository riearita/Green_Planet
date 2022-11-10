#include"Player_Bullet.hpp"

void Player_Bullet::first() {

	if (name == U"normal") {
		r = 30;
		delete_count = 0.5;
	}
}

void Player_Bullet::update(double d_time) {

	count += d_time;

	pos.x += cos(angle) * speed * d_time;
	pos.y += sin(angle) * speed * d_time;

	

	
}

void Player_Bullet::draw(double x,double y) {

	Circle(pos.x, pos.y, r).movedBy(-x, -y).draw(Palette::Green);
	
}



bool Player_Bullet::get_delete() {

	if (count >= delete_count) {
		return true;
	}

	return false;
}
