#include"Moji_Effect.hpp"

void Moji_Effect::update(double d_time) {
	count += d_time;
}

void Moji_Effect::draw(double _x,double _y) {
	FontAsset(U"font_k_30")(word).draw(x - _x, y - _y, color);

}
