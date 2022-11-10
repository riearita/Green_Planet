#pragma once

class Item {
public:

	Item(String _name,int x,int y) {

		name = _name;
		pos = { x,y };
		first();
	}

	void update();
	void draw(double,double);

	Rect get_hit_rect() { return Rect(pos.x, pos.y, size, size); }
	Rect get_rect() { return Rect(pos.x, pos.y, size, size); }

	void first();


private:

	String name;

	Vec2 pos = { 0,0 };

	int size = 0;
};


