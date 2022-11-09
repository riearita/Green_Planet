#pragma once

class Player_Bullet {
public:

	Player_Bullet(String _name,int x,int y){
		pos = { x,y };
		first();
	}

	void first();

	void update(double);
	void draw(double, double);

	String get_name() { return name; }

	Circle get_circle() { return Circle(pos.x,pos.y,r); }

	int get_damage() { return damage; }

private:


	String name;

	Vec2 pos = { 0,0 };

	int r = 0;

	int damage = 0;
};
