#include"Player_Bullet.hpp"

void Player_Bullet::first() {

	if (name == U"green") {
		r = 16;
		delete_count = 0.2;

		adjust_x = -28;
		adjust_y = -18;
	}
}

void Player_Bullet::update(double d_time) {

	count += d_time;

	pos.x += cos(angle) * speed * d_time;
	pos.y += sin(angle) * speed * d_time;

	

	
}

void Player_Bullet::draw(double x,double y) {

	//Circle(pos.x, pos.y, r).movedBy(-x, -y).draw(Palette::Green);

	String image_name = U"bullet_player_"+name;

	TextureAsset(image_name).draw(pos.x + adjust_x - x, pos.y + adjust_y - y);


}



bool Player_Bullet::get_delete() {

	if (count >= delete_count) {
		return true;
	}

	return false;
}
