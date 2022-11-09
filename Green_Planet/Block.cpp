#include"Block.hpp"

void Block::draw() {
	TextureAsset(name).draw(rect.x, rect.y);
}
