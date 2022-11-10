﻿#pragma once

//object

#include"Player.hpp"
#include"Enemy.hpp"
#include"Item.hpp"
#include"Block.hpp"
#include"Player_Bullet.hpp"
#include"Enemy_Bullet.hpp"
#include"Tile.hpp"



#include"Enemy_Data.hpp"
#include"Item_Data.hpp"
#include"Block_Data.hpp"
#include"Tile_Data.hpp"
#include"Start_Point.hpp"

#include"Definition.hpp"

#include"Weapon.hpp"

class Game {

public:

	//Game
	void set_up();
	void update();
	void draw();

    //Scene
	int main_scene = 0;

	


	//Play

	String stage = U"test";

	Weapon weapon;

	void update_play();
	void draw_play();

	void draw_object();

	void player_vs_block();

	void player_bullet_vs_block();

	void enemy_vs_block();

	void player_vs_enemy();

	void player_bullet_vs_enemy();

	void death_enemy();

	void player_vs_item();

	void control_scroll();

	void use_weapon();

	void delete_player_bullet();

	void delete_enemy_bullet();

	void draw_UI();

	Font font_50{ 50 };

	void go_edit();


	//Edit


	
	Array<Block_Data> block_data;
	Array<Enemy_Data> enemy_data;
	Array<Item_Data> item_data;
	Array<Tile_Data> tile_data;

	Array<Start_Point> start_point;

	void update_edit();
	void draw_edit();

	void save_edit();

	void write_edit();
	void erase_edit();

	void write_block_edit();
	void erase_block_edit();

	void write_enemy_edit();
	void erase_enemy_edit();

	void write_start_edit();
	void erase_start_edit();

	void write_tile_edit();
	void erase_tile_edit();

	int edit_cur_x = 0;
	int edit_cur_y = 0;

	String edit_type = U"block";

	String edit_block_name = U"soil";

	String edit_enemy_name = U"puni";

	String edit_tile_name = U"sky";



	//load
	void load_stage();

	

	//Object

	Player player;
	Array<Enemy> enemy;
	Array<Item> item;
	Array<Tile> tile;
	Array<Block> block;
	Array<Player_Bullet> player_bullet;
	Array<Enemy_Bullet> enemy_bullet;

	//General
	int scroll_x = 0;
	int scroll_y = 0;

	//Set_Up
	void set_screen();
	void set_image();
	void set_music();
	void set_font();
	void set_edit();
	void set_debug();

	//Music
	Array<String> bgm;
	Array<String> se;

	//System
	void make_stage();

	//Edit

	bool edit_lock = false;

	bool edit_lock_press = false;

	void draw_edit_object();

	void draw_edit_line();

	Array<Rect> scroll_contorller;
	void update_edit_scroll_controller();
	void draw_edit_scroll_controller();

	Rect edit_type_select_bar;
	int edit_type_select_scene;

	Array<Rect> edit_type_select_bar_1;



	void update_edit_type_select();
	void draw_edit_type_select();

	Array<Rect> edit_type_select_seek_bar_1;

	bool edit_block_seek = true;
	bool edit_tile_seek = true;
	bool edit_enemy_seek = true;
	bool edit_start_seek = true;

	Rect edit_go_play;
	Rect play_go_edit;

	void update_edit_go_play();
	void draw_edit_go_play();

	void update_go_edit();
	void draw_go_edit();
};
