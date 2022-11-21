#include"Enemy_Bullet.hpp"

void Enemy_Bullet::first() {

	if (name == U"blue") {
		r = 20;
		delete_count = 1;

		adjust_x = -20;
		adjust_y = -20;
	}
}

void Enemy_Bullet::update(double d_time) {

	count += d_time;

	pos.x += cos(angle) * speed * d_time;
	pos.y += sin(angle) * speed * d_time;




}

void Enemy_Bullet::draw(double x, double y) {

	get_circle().movedBy(-x, -y).draw(Palette::Green);

	String image_name = U"bullet_enemy_" + name;

	TextureAsset(image_name).draw(pos.x + adjust_x - x, pos.y + adjust_y - y);

	

}

bool Enemy_Bullet::get_delete() {

	if (count >= delete_count) {
		return true;
	}

	return false;
}

