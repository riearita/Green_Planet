#include"Block.hpp"

void Block::first() {
	if (name == U"move_block") {

		type = U"move";
	}
}

void Block::update(double _d_time) {

	d_time = _d_time;
	count += _d_time;

	if (name == U"move_block") {
		move();
	}

}

void Block::move() {

	old_rect = rect;

	double speed = 60 * d_time;

	if (direction == 3) {
		rect.x -= speed;

		moved_x = -speed;

		if (count > 5) {
			count = 0;
			direction = 4;
		}
	}
	else if (direction == 4) {
		rect.x += speed;

		moved_x = speed;

		if (count > 5) {
			count = 0;
			direction = 3;
		}
	}
}

void Block::draw(double x,double y) {
	TextureAsset(name).draw(rect.x - x, rect.y - y);
}
