#include"Item.hpp"

void Item::first() {

	if (name == U"heart") {
		size = 60;
	}
}

void Item::draw(double x,double y) {
	TextureAsset(name).draw(pos.x - x, pos.y - y);
}
