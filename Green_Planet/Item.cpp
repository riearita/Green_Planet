#include"Item.hpp"

void Item::first() {

	if (name == U"heart") {
		size = 50;
		adjust_x = -5;
		adjust_y = -5;
	}
	else if (name == U"metal") {
		size = 50;
		adjust_x = -5;
		adjust_y = -5;
	}

	pos.x -= size/2;
	pos.y -= size/2;
}

void Item::draw(double x,double y) {
	TextureAsset(name).draw(pos.x + adjust_x - x, pos.y + adjust_y - y);
}
