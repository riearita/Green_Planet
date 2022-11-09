#pragma once

class Block {
public:

	Block(String _name, int _x, int _y,int _size) {
		name = _name;
		rect = Rect(_x, _y, _size, _size);
	}

	void update();
	void draw();

	RectF get_rect() { return rect; }

	RectF rect;

	String name;
};


