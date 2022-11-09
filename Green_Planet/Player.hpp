#pragma once

class Player {
public:

	Player(){
		pos.x = 1920 / 2;
		pos.y = 500;
	}

	void update(double);
	void draw();

	void move();

	void walk();
	void add_gravity();

	Rect get_rect() { return Rect(pos.x, pos.y, size, size); }
	Rect get_old_rect() { return Rect(old_pos.x, old_pos.y, size, size); }

	void set_ground(bool v) { ground = v; }

	//ブロックとのあたり判定用
	void set_old_pos() { old_pos = pos; }
	void set_pos_x(int v) { pos.x = v; }
	void set_pos_y(int v) { pos.y = v; }


	int get_size() { return size; }

private:

	Vec2 old_pos;
	Vec2 pos;
	int size = 100;

	double gravity = 5;

	bool ground = false;


	


};


