#include"My_Effect.hpp"

void My_Effect::first() {

	if (name == U"bullet_end_green") {

		//画像のサイズ
		wide = 56;
		height = 37;


		//初期サイズ
		size = 0;

		//画像位置調整
		adjust_x = wide * size / 2;
		adjust_y = height * size / 2;

		//１秒あたりの拡大率
		size_up = 5;

		//消去カウント
		delete_count = 0.6;

		//初期fade
		fade_v = 1;

		//fadeの消える量
		fade_delete = 1 / delete_count;
	}


}


void My_Effect::update(double d_time) {

	count += d_time;

	//サイズ変更
	size += size_up * d_time;

	adjust_x = (wide * size / 2);
	adjust_y = (height * size / 2);

	fade_v -= fade_delete * d_time;
}

void My_Effect::draw(double x, double y) {

	TextureAsset(name).scaled(size).draw(pos.x-adjust_x - x, pos.y-adjust_y - y, ColorF(1.0, fade_v));
}

bool My_Effect::get_delete() {

	if (count >= delete_count) {
		return true;
	}

	return false;
}
