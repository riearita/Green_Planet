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
	else if (name == U"enemy_smoke") {

		//画像のサイズ
		wide = 120;
		height = 120;


		//初期サイズ
		size = 1;

		//画像位置調整
		adjust_x = wide * size / 2;
		adjust_y = height * size / 2;

		//１秒あたりの拡大率
		size_up = 0;

		//消去カウント
		delete_count = 0.5;

		//初期fade
		fade_v = 1;

		//fadeの消える量
		fade_delete = 1 / delete_count;

		fade_on = false;


		page_on = true;
		page_max = 10;

		page_change = delete_count / page_max;

	}
	else if (name == U"block_smoke") {

		//画像のサイズ
		wide = 100;
		height = 100;


		//初期サイズ
		size = 1;

		//画像位置調整
		adjust_x = wide * size / 2;
		adjust_y = height * size / 2;

		//１秒あたりの拡大率
		size_up = 0;

		//消去カウント
		delete_count = 0.5;

		//初期fade
		fade_v = 1;

		//fadeの消える量
		fade_delete = 1 / delete_count;

		fade_on = false;


		page_on = true;
		page_max = 8;

		page_change = delete_count / page_max;

	}
}


void My_Effect::update(double d_time) {

	count += d_time;

	//サイズ変更
	size += size_up * d_time;

	adjust_x = (wide * size / 2);
	adjust_y = (height * size / 2);

	if (fade_on == true) {
		fade_v -= fade_delete * d_time;
	}

	if (page_on == true) {

		page_count += d_time;

		if (page_count >= page_change) {
			page++;
			page_count = 0;
		}
	}
}

void My_Effect::draw(double x, double y) {

	String image_name = name;

	if (page_on == true) {

		image_name += (U"_" + Format(page));
	}

	TextureAsset(image_name).scaled(size).draw(pos.x-adjust_x - x, pos.y-adjust_y - y, ColorF(1.0, fade_v));

	//Print << U"image_name::" << image_name;
}

bool My_Effect::get_delete() {

	if (count >= delete_count) {
		return true;
	}

	return false;
}
