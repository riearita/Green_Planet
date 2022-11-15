#pragma once

class Player {
public:

	Player(){
		pos.x = 1920 / 2;
		pos.y = 500;
	}

	void update(double);
	void draw(double,double);

	

	void walk();
	void air_move();
	
	void jump();

	void add_gravity();

	Rect get_hit_rect() { return Rect(pos.x, pos.y, size, size); }
	Rect get_rect() { return Rect(pos.x, pos.y, size, size); }
	Rect get_old_rect() { return Rect(old_pos.x, old_pos.y, size, size); }

	void set_ground(bool v) { ground = v; }
	bool get_ground() { return ground; }

	//ブロックとのあたり判定用
	void set_old_pos() { old_pos = pos; }
	void set_pos_x(int v) { pos.x = v; }
	void set_pos_y(int v) { pos.y = v; }


	int get_size() { return size; }

	void zero_speed_y() { speed.y = 0; }

	void set_coyote_time(double v) { coyote_time = v; }

	void zero_inertia() { inertia = 0; }

	Vec2 get_pos() { return pos; }

	void damage(int);

	void full_hp() { hp = max_hp; }

	int get_hp() { return hp; }
	int get_max_hp() { return max_hp; }

	void controll_fade();

	int get_direction() { return direction; }

	void move_x(double v) { pos.x += v; }
	void move_y(double v) { pos.y += v; }

private:

	Vec2 old_pos;
	Vec2 pos;
	int size = 70;

	Vec2 speed = { 0,0 };


	double gravity = 65;

	bool ground = false;

	//ジャンプ初速
	double jump_v0 = -32;


	//コヨーテタイム
	double coyote_time = 0;

	//慣性
	double inertia = 0;

	//無敵タイム
	double muteki_count = 0;

	//向き
	int direction = 1;

	//ｈｐ
	int hp = 100;
	int max_hp = 100;

	//Fade
	int fade_on = 0;
	double fade_count = 0;

	double d_time;
	


};


