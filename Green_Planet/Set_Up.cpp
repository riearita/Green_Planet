#include"Game.hpp"

void Game::set_up() {

	set_screen();
	set_image();
	set_font();
	set_music();
	set_edit();
	set_debug();
}

void Game::set_screen() {

	Scene::Resize(1920, 1080);
	Scene::SetResizeMode(ResizeMode::Keep);
	Window::SetFullscreen(true);
}

void Game::set_image() {

	//player
	TextureAsset::Register(U"player_left", U"image/player/left.png");
	TextureAsset::Register(U"player_right", U"image/player/right.png");

	//block
	TextureAsset::Register(U"soil", U"image/block/soil.png");
	TextureAsset::Register(U"soil_grass", U"image/block/soil_grass.png");
	TextureAsset::Register(U"move_block", U"image/block/move_block.png");

	//enemy
	TextureAsset::Register(U"maru_3", U"image/enemy/maru_3.png");
	TextureAsset::Register(U"maru_4", U"image/enemy/maru_4.png");

	//start
	TextureAsset::Register(U"start", U"image/start.png");

	//tile
	//TextureAsset::Register(U"sky", U"image/sky.png");

	//event
	TextureAsset::Register(U"event", U"image/event.png");

	//back
	TextureAsset::Register(U"sky", U"image/back/sky.png");

	//bullet
	TextureAsset::Register(U"bullet_green", U"image/bullet/green.png");

	//weapon
	TextureAsset::Register(U"shot_gun", U"image/weapon/shot_gun.png");

	//My_Effect
	TextureAsset::Register(U"bullet_end_green", U"image/effect/bullet_end_green.png");

	//UI
	TextureAsset::Register(U"message_box", U"image/UI/message_box.png");
	TextureAsset::Register(U"weapon_box", U"image/UI/weapon_box.png");

	TextureAsset::Register(U"bar_frame", U"image/UI/bar_frame.png");
	TextureAsset::Register(U"hp_bar", U"image/UI/hp_bar.png");
	TextureAsset::Register(U"energy_bar", U"image/UI/energy_bar.png");
}

void Game::set_font() {

	FontAsset::Register(U"font_45",45, U"font/NotoSansJP-Medium.otf");
}

void Game::set_music() {

	//bgm 
	for (int i = 0; i < 5; i++) {
		String str;
		str = U"bgm{}"_fmt(i);
		bgm << str;
	}

	//se 
	for (int i = 0; i < 15; i++) {
		String str;
		str = U"se{}"_fmt(i);
		se << str;
	}

	//Bgm
	AudioAsset::Register(bgm[0], Audio::Stream, U"bgm/タイトル.ogg", Loop::Yes);

	//Se
	AudioAsset::Register(se[0], U"se/アイテムゲット.mp3");
	AudioAsset::Load(se[0]);
}


