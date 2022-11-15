#pragma once
class Edit_Number_Button {

public:

	Edit_Number_Button(int _v, int _x, int _y) {

		v = _v;
		x = _x;
		y = _y;

		rect = Rect(x * 120 + 200, y * 120 + 500, 100, 100);
	}

	Rect get_rect() { return rect; }

	int get_x() { return x; }
	int get_y() { return y; }
	int get_v() { return v; }


	void draw(){
		rect.draw(Palette::White);
	}

private:

	Rect rect;

	int v = 0;
	int x = 0;
	int y = 0;
};
