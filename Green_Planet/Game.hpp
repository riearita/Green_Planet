#pragma once

//object

#include"Player.hpp"
#include"Enemy.hpp"
#include"Item.hpp"
#include"Block.hpp"

#include"Enemy_Data.hpp"
#include"Item_Data.hpp"
#include"Block_Data.hpp"

#include"Definition.hpp"

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

	void update_play();
	void draw_play();

	void draw_object();

	void player_vs_block();

	void control_scroll();

	void use_weapon();

	void go_edit();


	//Edit


	
	Array<Block_Data> block_data;
	Array<Enemy_Data> enemy_data;
	Array<Item_Data> item_data;

	void update_edit();
	void draw_edit();

	void save_edit();

	void write_edit();
	void erase_edit();

	void write_block_edit();
	void erase_block_edit();

	int edit_cur_x = 0;
	int edit_cur_y = 0;

	String edit_type = U"block";

	String edit_block_name = U"soil";

	void go_play();



	//load
	void load_stage();

	

	//Object

	Player player;
	Array<Enemy> enemy;
	Array<Item> item;
	Array<Block> block;

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


};
