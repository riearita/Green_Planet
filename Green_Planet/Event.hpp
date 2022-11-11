#pragma once
class Event {
public:

	Event(String _name,int _number,int _start,int _x, int _y, int _size) {
		name = _name;
		number = _number;
		start = _start;
		rect = Rect(_x, _y, _size, _size);
	}

	void update();
	void draw(double, double);
	

	RectF get_rect() { return rect; }
	int get_number() { return number; }
	int get_start() { return start; }

private:

	RectF rect;

	String name;

	int number = 0;

	int start = 0;
};


