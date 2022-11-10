#include"Tile.hpp"

void Tile::draw(double x, double y) {
	TextureAsset(name).draw(pos.x - x, pos.y - y);
}
