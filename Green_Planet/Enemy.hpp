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

	Rect get_rect() { return Rect(pos.x, pos.y, size_w, size_h); }


private:


	String name=U"";

	Vec2 pos={};

	int size_w = 0;
	int size_h = 0;
	int size_r = 0;


};



