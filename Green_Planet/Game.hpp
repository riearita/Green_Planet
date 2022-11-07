#pragma once

//object

#include"Player.hpp"
#include"Enemy.hpp"
#include"Item.hpp"
#include"Block.hpp"


class Game {

public:


	void update();
	void draw();


	//Play
	void update_play();
	void draw_play();

	//Edit
	void update_edit();
	void draw_edit();


	//Object

	Player player;
	Array<Enemy> enemy;
	Array<Item> item;
	Array<Block> block;


	

};
