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
	TextureAsset::Register(U"player", U"image/player.png");

	//block
	TextureAsset::Register(U"soil", U"image/soil.png");

	//enemy
	TextureAsset::Register(U"puni", U"image/puni.png");

	//start
	TextureAsset::Register(U"start", U"image/start.png");

	//tile
	TextureAsset::Register(U"sky", U"image/sky.png");

	//event
	TextureAsset::Register(U"event", U"image/event.png");
}

void Game::set_font() {

	FontAsset::Register(U"titleFont_180", 180, U"font/クロバラ.ttf");
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


