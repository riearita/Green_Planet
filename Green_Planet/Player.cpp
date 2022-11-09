#include"Player.hpp"

void Player::update(double d_time) {

	set_old_pos();

	walk();

	add_gravity();
}

void Player::walk() {

	double walk_speed = 5;

	if (KeyLeft.pressed()) {
		pos.x -= walk_speed;
	}
	else if (KeyRight.pressed()) {
		pos.x += walk_speed;
	}



}

void Player::add_gravity() {

	pos.y += gravity;
}

void Player::draw() {

	TextureAsset(U"player").draw(pos.x,pos.y);
}
