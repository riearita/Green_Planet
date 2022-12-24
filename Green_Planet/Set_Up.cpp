#include"Game.hpp"

void Game::set_up() {

	set_screen();
	set_image();
	set_font();
	set_music();
	set_edit();
	set_shader();
	set_stage_data();
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
	TextureAsset::Register(U"player_left_jump", U"image/player/jump/left.png");
	TextureAsset::Register(U"player_right_jump", U"image/player/jump/right.png");

	for (int i = 0; i < 7; i++) {

		String name = U"player_left_walk_" + Format(i);
		String adress = U"image/player/walk/left/" + Format(i) + U".png";

		TextureAsset::Register(name, adress);
	}

	for (int i = 0; i < 7; i++) {

		String name = U"player_right_walk_" + Format(i);
		String adress = U"image/player/walk/right/" + Format(i) + U".png";

		TextureAsset::Register(name, adress);
	}

	//block
	TextureAsset::Register(U"soil", U"image/block/soil.png");
	TextureAsset::Register(U"soil_grass", U"image/block/soil_grass.png");
	TextureAsset::Register(U"soil_grass_left_cut", U"image/block/soil_grass_left_cut.png");
	TextureAsset::Register(U"soil_grass_right_cut", U"image/block/soil_grass_right_cut.png");
	TextureAsset::Register(U"soil_grass_double_cut", U"image/block/soil_grass_double_cut.png");
	TextureAsset::Register(U"break_block", U"image/block/break_block.png");
	TextureAsset::Register(U"concrete", U"image/block/concrete.png");


	TextureAsset::Register(U"move_block", U"image/block/move_block.png");

	//enemy
	TextureAsset::Register(U"maru_3", U"image/enemy/maru/3.png");
	TextureAsset::Register(U"maru_4", U"image/enemy/maru/4.png");
	TextureAsset::Register(U"don_3", U"image/enemy/don/3.png");
	TextureAsset::Register(U"huwa_3", U"image/enemy/huwa/3.png");
	TextureAsset::Register(U"huwa_0_3", U"image/enemy/huwa/0_3.png");
	TextureAsset::Register(U"huwa_1_3", U"image/enemy/huwa/1_3.png");
	TextureAsset::Register(U"huwa_0_4", U"image/enemy/huwa/0_4.png");
	TextureAsset::Register(U"huwa_1_4", U"image/enemy/huwa/1_4.png");
	TextureAsset::Register(U"maru_quick_3", U"image/enemy/maru_quick/3.png");
	TextureAsset::Register(U"maru_quick_4", U"image/enemy/maru_quick/4.png");

	//start
	TextureAsset::Register(U"start", U"image/start.png");

	//tile
	

	TextureAsset::Register(U"tree", U"image/tile/tree.png");
	TextureAsset::Register(U"plant", U"image/tile/plant.png");
	TextureAsset::Register(U"plant_2", U"image/tile/plant_2.png");
	TextureAsset::Register(U"building", U"image/tile/building.png");
	TextureAsset::Register(U"window", U"image/tile/window.png");
	TextureAsset::Register(U"base", U"image/tile/base.png");
	TextureAsset::Register(U"aerial_display", U"image/tile/aerial_display.png");

	//event
	TextureAsset::Register(U"event", U"image/event.png");
	TextureAsset::Register(U"save_server", U"image/event/save_server.png");
	TextureAsset::Register(U"life_server", U"image/event/life_server.png");

	//back
	TextureAsset::Register(U"sky", U"image/back/sky.png");
	TextureAsset::Register(U"base", U"image/back/base.png");

	//bullet
	TextureAsset::Register(U"bullet_player_green", U"image/bullet/player/green.png");

	TextureAsset::Register(U"bullet_enemy_blue", U"image/bullet/enemy/blue.png");
	TextureAsset::Register(U"bullet_enemy_drop", U"image/bullet/enemy/drop.png");
	//weapon
	TextureAsset::Register(U"shot_gun", U"image/weapon/shot_gun.png");

	//My_Effect
	TextureAsset::Register(U"bullet_end_player_green", U"image/effect/bullet_end/player/green.png");

	TextureAsset::Register(U"bullet_end_enemy_blue", U"image/effect/bullet_end/enemy/blue.png");
	TextureAsset::Register(U"bullet_end_enemy_drop", U"image/effect/bullet_end/enemy/drop.png");


	for (int i = 0; i <11; i++) {
		String name = U"enemy_smoke_" + Format(i);
		String adress = U"image/effect/enemy_smoke/" + Format(i) + U".png";

		//Print << U"name::" << name;
		//Print << U"adress::" << adress;

		TextureAsset::Register(name,adress);
	}

	for (int i = 0; i < 8; i++) {
		String name = U"block_smoke_" + Format(i);
		String adress = U"image/effect/block_smoke/" + Format(i) + U".png";

		//Print << U"name::" << name;
		//Print << U"adress::" << adress;

		TextureAsset::Register(name, adress);
	}

	//Item
	TextureAsset::Register(U"heart", U"image/item/heart.png");
	TextureAsset::Register(U"metal", U"image/item/metal.png");

	//menu
	TextureAsset::Register(U"menu_back", U"image/menu/back.png");
	TextureAsset::Register(U"menu_weapon_icon", U"image/menu/weapon_icon.png");


	//UI
	TextureAsset::Register(U"message_box", U"image/UI/message_box.png");
	TextureAsset::Register(U"weapon_box", U"image/UI/weapon_box.png");

	TextureAsset::Register(U"bar_frame", U"image/UI/bar_frame.png");
	TextureAsset::Register(U"hp_bar", U"image/UI/hp_bar.png");
	TextureAsset::Register(U"energy_bar", U"image/UI/energy_bar.png");

	TextureAsset::Register(U"black", U"image/UI/black.png");
}

void Game::set_font() {

	FontAsset::Register(U"font_45",45, U"font/NotoSansJP-Medium.otf");
	FontAsset::Register(U"font_k_30", 30, U"font/Kikakana-21-Regular.otf");

	FontAsset::Register(U"font_SDF_33", FontMethod::SDF, 33, U"font/Kikakana-21-Bold.otf");
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

void Game::set_shader() {

	psWhite = HLSL{ U"shader/white.hlsl", U"PS" };
	if (not psWhite)
	{
		throw Error{ U"Failed to load a shader file" };
	}

}

void Game::set_stage_data() {

	/*
	Stage_name・Back_name
	*/

	stage_data.push_back(Stage_Data(U"garden",U"sky"));
	//stage_data.push_back(Stage_Data(U"base", U"base"));

}


