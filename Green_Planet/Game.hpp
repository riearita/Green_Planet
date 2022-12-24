#pragma once

//object

#include"Player.hpp"
#include"Enemy.hpp"
#include"Item.hpp"
#include"Block.hpp"
#include"Player_Bullet.hpp"
#include"Enemy_Bullet.hpp"
#include"Tile.hpp"
#include"Event.hpp"
#include"Back.hpp"
#include"My_Effect.hpp"
#include"Moji_Effect.hpp"
#include"Guide.hpp"

#include"Enemy_Data.hpp"
#include"Item_Data.hpp"
#include"Block_Data.hpp"
#include"Tile_Data.hpp"
#include"Start_Point.hpp"
#include"Event_Data.hpp"

#include"Definition.hpp"

#include"Edit_Block.hpp"
#include"Edit_Enemy.hpp"
#include"Edit_Event.hpp"
#include"Edit_Tile.hpp"

#include"Weapon.hpp"

#include"Edit_Number_Button.hpp"

#include"Status.hpp"
#include"Weapon_Have.hpp"
#include"Item_Have.hpp"

#include"Stage_Data.hpp"




class Game {

public:


	//Game
	void set_up();
	void update();
	void draw();

    //Scene
	int main_scene = 0;

	//Key
	InputGroup inputLeft = KeyLeft;
	InputGroup inputRight = KeyRight;
	InputGroup inputUp = KeyUp;
	InputGroup inputDown = KeyDown;

	InputGroup inputZ = KeyZ;
	InputGroup inputShift = KeyShift;
	InputGroup inputX = KeyX;

	const Array<String> indices = Range(0, (Gamepad.MaxPlayerCount - 1)).map(Format);

	// ゲームパッドのプレイヤーインデックス
	size_t playerIndex = 0;

	bool eco_block_draw = true;


	Array<Stage_Data> stage_data;

	void update_input();

	//Play

	String stage = U"1";

	Weapon weapon;

	void update_play();
	void draw_play();

	

	void draw_object();

	void player_vs_block();

	void player_bullet_vs_block();

	void enemy_vs_block();

	void enemy_bullet_vs_block();

	void player_vs_enemy();

	void player_bullet_vs_enemy();

	void enemy_bullet_vs_player();



	void death_enemy();

	void player_vs_item();

	void control_scroll();

	void use_weapon();

	void delete_player_bullet();

	void delete_enemy_bullet();

	void delete_my_effect();

	void delete_moji_effect();

	void cliff_turn_enemy();

	void draw_UI();


	void check_event();

	void enemy_make_bullet();

	Font font_50{ 50 };

	void go_edit();

	//Event

	//event_scene
	int es = 0;
	int event_number = 0;

	bool message_lock = false;

	int stage_under_line = 0;
	int stage_right_line = 0;

	void update_event();
	void draw_event();

	void z();
	void next();
	void z_end();
	void change_map(String);
	void end();

	void ev_0();
	void ev_1();
	void ev_2();
	void ev_3();
	void ev_4();
	void ev_5();
	void ev_6();
	void ev_7();
	void ev_8();
	void ev_9();
	void ev_10();

	//Edit


	
	Array<Block_Data> block_data;
	Array<Enemy_Data> enemy_data;
	Array<Item_Data> item_data;
	Array<Tile_Data> tile_data;
	Array<Event_Data> event_data;

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

	int tile_layer = 0;

	void write_tile_edit();
	void erase_tile_edit();



	void write_event_edit();
	void erase_event_edit();

	int edit_cur_x = 0;
	int edit_cur_y = 0;

	String edit_type = U"block";

	String edit_block_name = U"soil";

	String edit_enemy_name = U"maru";

	String edit_tile_name = U"tree";
	

	String edit_event_name = U"event";

	//load
	void load_stage();

	

	//Object

	Back back;

	Player player;
	Array<Enemy> enemy;
	Array<Item> item;
	Array<Tile> tile;
	Array<Block> block;
	Array<Event> event;
	Array<Player_Bullet> player_bullet;
	Array<Enemy_Bullet> enemy_bullet;
	Array<My_Effect> my_effect;
	Array<Moji_Effect> moji_effect;
	Array<Guide> guide;

	//General
	int scroll_x = 0;
	int scroll_y = 0;

	//Set_Up
	void set_screen();
	void set_image();
	void set_music();
	void set_font();
	void set_edit();
	void set_shader();
	void set_stage_data();
	void set_debug();

	//Music
	Array<String> bgm;
	Array<String> se;

	//System
	void make_stage();

	//Edit

	int edit_scene = 0;

	void update_edit_main();
	void update_edit_sub();

	void draw_edit_main();
	void draw_edit_sub();

	void update_edit_detail();
	void draw_edit_detail();

	void draw_edit_will_tile();

	int edit_index = 0;
	String edit_input_number = U"";

	void edit_update_number_input();
	void draw_edit_number_input();



	Array<Edit_Block> edit_block;
	Array<Edit_Enemy> edit_enemy;
	Array<Edit_Event> edit_event;
	Array<Edit_Tile> edit_tile;

	Array<Rect> edit_select_block;
	Array<Rect> edit_select_enemy;
	Array<Rect> edit_select_event;
	Array<Rect> edit_select_tile;

	Array<Edit_Number_Button> edit_number_button;

	Rect edit_number_button_enter;

	bool edit_event_number = true;
	bool edit_event_start = false;

	Rect edit_event_number_rect;
	Rect edit_event_start_rect;

	Rect edit_sub_close;

	Rect edit_detail_close;

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

	Rect edit_type_sample;

	void update_edit_type_sample();
	void draw_edit_type_sample();

	void update_edit_type_select();
	void draw_edit_type_select();

	Array<Rect> edit_type_select_seek_bar_1;

	bool edit_block_seek = true;
	bool edit_tile_0_seek = true;
	bool edit_tile_1_seek = true;
	bool edit_tile_01_seek = true;
	bool edit_enemy_seek = true;
	bool edit_event_seek = true;
	bool edit_start_seek = true;

	Rect edit_go_play;
	Rect play_go_edit;

	void update_edit_go_play();
	void draw_edit_go_play();

	void update_go_edit();
	void draw_go_edit();

	//message
	double message_count = 0;

	void update_message(double);
	void draw_message();
	void set_message(String);

	String message_text = U"";

	int message_scene = 0;

	bool message_box = false;

	//Menu

	void update_menu();
	void draw_menu();

	int menu_scene = 0;

	void update_menu_main();
	void draw_menu_main();

	void update_menu_weapon();
	void draw_menu_weapon();

	void update_menu_item();
	void draw_menu_item();

	void update_menu_setting();
	void draw_menu_setting();

	int menu_main_cur_x = 0;
	int menu_main_cur_y = 0;

	//shader

	PixelShader psWhite;

	ConstantBuffer<WhiteEffectConstants> cbWhite;

	//Status
	Status status;
	Array<Weapon_Have> weapon_have;
	Array<Item_Have> item_have;


	//Draw_Outline_Text

	void draw_outline_text(String,String,int,int,Color);

	void draw_moji_effect();

	//Change_Scene

	bool change_scene_on = 0;

	void update_change_scene();
	void draw_change_scene();


	int change_scene_scene = 0;

	double change_scene_count = 0;

	double change_scene_alpha = 0;

	String change_scene_type = U"";

	void change_scene(int);
	void change_stage(String);

	int change_scene_go_scene = 0;
	String change_scene_go_stage = U"";


	void make_stage_data();
};

   
