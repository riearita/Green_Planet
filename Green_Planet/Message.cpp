#include"Game.hpp"

void Game::update_message(double d_time) {

	message_count += d_time;

	//メッセージ描画前
	if (message_scene == 0) {

	}
	//メッセージ描画
	else if (message_scene == 1) {

		//文字が全てでている場合は終了可
		if (message_count * 20 > message_text.size()) {
		
			message_scene = 3;
		}

        //最後まで一気に描画
		if (KeyZ.down()) {

			message_scene = 2;
			message_count = double(message_text.size()) + 1;
		}
	}
	//メッセージ描画後
	else if (message_scene == 2) {

		if (KeyZ.down()) {
			message_scene = 3;
		}
	}
}

void Game::draw_message() {

	int x = 1920 / 2 - 1200 / 2;
	int y = 1080 - 20 - 280;

	//message_box
	TextureAsset(U"message_box").draw(x,y);

	// 文字カウントを 0.1 秒ごとに増やす
	const size_t length = static_cast<size_t>(message_count / 0.05);

	// text の文字数以上の length は切り捨てられる
	FontAsset(U"font_45")(message_text.substr(0, length)).draw(x + 60, y + 50-20+6);
}

void Game::set_message(String v) {

	message_box = true;

	//一回しか通らない
	if (message_lock == false) {

		message_text = U"";

		int text_count = 0;
	

		for (size_t i = 0; i < v.size(); i++) {

			String word = U"";
			word += v[i];

			if (word != U"\n") {

				//20文字になったら改行
				if (text_count == 24) {

					message_text += U"\n";
					
					text_count = 0;
				}

				text_count++;
			}
			//改行があった場合
			else {
				text_count = 0;
			}
		
			message_text += v[i];

		}

	

		message_count = 0;

		message_lock = true;

		message_scene = 1;
	}
}
