#include"Event.hpp"

void Event::draw(double x, double y) {
	TextureAsset(name).draw(rect.x - x, rect.y - y);
}

