#include"Block.hpp"

void Block::draw(double x,double y) {
	TextureAsset(name).draw(rect.x - x, rect.y - y);
}
