#pragma once


class Moji_Effect {

public:

	Moji_Effect(String _word,int _x,int _y,ColorF _color) {
		word = _word;
		x = _x;
		y = _y;
		color = _color;

		delete_count = 1;
	}

	void update(double);

	void draw(double,double);

	bool get_delete() {

		if (count >= delete_count) {
			return true;
		}
		return false;
	}

	String get_text() { return word; }
	int get_x() { return x; }
	int get_y() { return y; }
	Color get_color() { return color; }



private:


	String word;

	int x = 0;
	int y = 0;

	double count = 0;
	double delete_count = 0;

	Color color;
};
