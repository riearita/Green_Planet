#pragma once

class Block {
public:

	Block(String _name, int _x, int _y,int _size) {
		name = _name;
		rect = Rect(_x, _y, _size, _size);

		first();
	}

	void first();

	void update(double);
	void draw(double,double);

    RectF get_rect() { return rect; }
	RectF get_old_rect() { return old_rect; }
	

	String get_name() { return name; }

	String get_type() { return type; }

	void move();
	

	double get_moved_x() { return moved_x; }
	double get_moved_y() { return moved_y; }

	

private:


	
	RectF old_rect;
	RectF rect;

	String name;

	String type = U"";


	double d_time = 0;

	double count = 0;

	int direction = 3;

	double moved_x = 0;
	double moved_y = 0;
};


