#include"Enemy.hpp"

void Enemy::first() {

}

void Enemy::update(double d_time) {

}

void Enemy::draw(double x,double y) {
	TextureAsset(name).draw(pos.x - x, pos.y - y);
}
