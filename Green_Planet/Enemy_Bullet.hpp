#pragma once

class Enemy_Bullet {
public:

	Enemy_Bullet(String _name, int x, int y, double _speed, double _angle, int _power) {

		name = _name;
		pos = { x,y };
		speed = _speed;
		angle = ToRadians(_angle);
		power = _power;

		first();
	}

	void first();

	void update(double);
	void draw(double, double);

	String get_name() { return name; }

	Circle get_circle() { return Circle(pos.x, pos.y, r); }

	int get_power() { return power; }

	bool get_delete();

private:


	String name;

	Vec2 pos = { 0,0 };

	int r = 0;

	double count = 0;

	double delete_count = 0;

	double angle = 0;

	double speed = 0;

	int power = 0;

	int adjust_x = 0;
	int adjust_y = 0;
};
