#pragma once

class Enemy {
public:

	Enemy(String _name,int x,int y) {
		name = _name;
		pos = {x,y};
		first();
	}

	void first();

	void update(double);
	void draw(double,double);

	

	void add_gravity();

	void set_ground(bool v) { ground = v; }

	Rect get_rect() { return Rect(pos.x, pos.y, size_w, size_h); }
	Rect get_old_rect() { return Rect(old_pos.x, old_pos.y, size_w, size_h); }
	Rect get_hit_rect(){ return Rect(pos.x, pos.y, size_w, size_h); }
	int get_size_w() { return size_w; }
	int get_size_h() { return size_h; }

	void set_old_pos() { old_pos = pos; }
	void set_pos_x(int v) { pos.x = v; }
	void set_pos_y(int v) { pos.y = v; }

	void zero_speed_y() { speed.y = 0; }

	int get_hit_damage() { return hit_damage; }

	int get_hp() { return hp; }

	void damage(int);

private:


	String name=U"";

	Vec2 old_pos = {};
	Vec2 pos={};

	int size_w = 0;
	int size_h = 0;
	int size_r = 0;

	int fly = 0;

	double gravity = 100;

	bool ground = false;

	Vec2 speed = { 0,0 };

	int hit_damage = 1;

	int hp = 1;

	double d_time = 0;

};



