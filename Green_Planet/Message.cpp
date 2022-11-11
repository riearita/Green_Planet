#include"Game.hpp"

void Game::update_message(double d_time) {

	message_count += d_time;

	//メッセージ描画前
	if (message_scene == 0) {

	}
	//メッセージ描画
	else if (message_scene == 1) {

		if (KeyZ.down()) {

			message_scene = 2;
			message_count = message_text.size() + 1;
		}

		if (message_count>message_text.size()) {

			message_scene = 2;
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

	// 文字カウントを 0.1 秒ごとに増やす
	const size_t length = static_cast<size_t>(message_count / 0.05);

	// text の文字数以上の length は切り捨てられる
	font_50(message_text.substr(0, length)).draw(50, 50);
}

void Game::set_message(String v) {

	//一回しか通らない
	if (message_lock == false) {
		message_text = v;

		message_count = 0;

		message_lock = true;

		message_scene = 1;
	}
}
