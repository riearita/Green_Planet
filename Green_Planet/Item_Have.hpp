#pragma once

class Item_Have {

public:

	Item_Have(String _name,int _x,int _y) {
		name = _name;
		x = _x;
		y = _y;
	}

	void draw();

private:

	String name;
	int x, y;

};
