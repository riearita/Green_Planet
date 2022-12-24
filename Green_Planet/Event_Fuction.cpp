#include"Game.hpp"

void Game::update_event() {

	const double d_time = Scene::DeltaTime();

	message_box = false;

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
	case 3:
		ev_3();
		break;
	case 4:
		ev_4();
		break;
	case 5:
		ev_5();
		break;
	case 6:
		ev_6();
		break;
	case 7:
		ev_7();
		break;
	case 8:
		ev_8();
		break;
	case 9:
		ev_9();
		break;
	case 10:
		ev_10();
		break;
	case 11:
		break;
	case 12:
		break;
	default:
		break;
	}
}

void Game::draw_event() {

	if (message_box == true) {
		draw_message();
	}
}

//ライフサーバー
void Game::ev_0() {

	if (es == 0) {
		set_message(U"ライフとエネルギーが全回復した！！");
		player.full_hp();
		weapon.full_energy();
		z_end();
	}
	
	
}

//セーブサーバー
void Game::ev_1() {

	if (es == 0) {
		set_message(U"セーブしました！！");
	
		z_end();
	}
}

//change_map
void Game::ev_2() {
	if (es == 0) {
		change_stage(U"base");
		end();
	}
}

void Game::ev_3() {

	if (es == 0) {
		set_message(U"テストようの文字列、長さを確保するため結構長くするのですよおおおおおおおおおおおおおおおおおおおおおおおおおおおお");
		z();
	}
	else if (es == 1) {
		set_message(U"二言めはこちらです、表示てすとおおおおお");
		z_end();
	}
}

void Game::ev_4() {

}

void Game::ev_5() {

}

void Game::ev_6() {

}

void Game::ev_7() {

}

void Game::ev_8() {

}

void Game::ev_9() {

}

void Game::ev_10() {

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

void Game::end() {

	main_scene = 0;

	es = 0;

	message_count = 0;
	message_lock = false;
	message_scene = false;
}

void Game::next() {
	es++;
	message_count = 0;
	message_lock = false;
}

void Game::z_end() {

	if (KeyZ.down()) {

		if (message_scene==0 or message_scene == 3) {

			end();

		}
	}
}

void Game::change_map(String v) {

	stage = v;

	load_stage();
	make_stage();

	message_count = 0;
	message_lock = false;
	message_scene = false;
}
