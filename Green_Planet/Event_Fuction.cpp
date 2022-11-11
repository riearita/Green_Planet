#include"Game.hpp"

void Game::update_event() {

	const double d_time = Scene::DeltaTime();

	update_message(d_time);

	switch (event_number)
	{
	case 0:
		ev_0();
		break;
	case 1:
		ev_1();
		break;
	case 2:
		ev_2();
		break;
	default:
		break;
	}
}

void Game::draw_event() {

	draw_message();
}

void Game::ev_0() {

	if (es == 0) {
		set_message(U"テストようの文字列、長さを確保するため結構長くするのですてすううううううううううううううう");
		z();
	}
	else if (es == 1) {
		set_message(U"二言めはこちらです、表示てすとおおおおお");
		z_end();
	}
	
	
}
void Game::ev_1() {

}
void Game::ev_2() {

}

void Game::z() {

	if (KeyZ.down()) {

		if (message_scene==0 or message_scene == 3) {

			es++;
			message_count = 0;
			message_lock = false;
			message_scene = 0;
		}
	}
}

void Game::next() {
	es++;
	message_count = 0;
	message_lock = false;
}

void Game::z_end() {

	if (KeyZ.down()) {

		if (message_scene==0 or message_scene == 3) {

			main_scene = 0;

			es = 0;

			message_count = 0;
			message_lock = false;
			message_scene = false;

		}
	}
}
