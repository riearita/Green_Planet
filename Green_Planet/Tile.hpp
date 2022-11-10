#pragma once

class Tile {
public:

	Tile(String _name,int x,int y){
		name = _name;
		pos = { x,y };

	}


	void update();
	void draw(double,double);

	int get_layer() { return layer; }

private:

	String name;

	Vec2 pos = {0,0};

	int layer = 0;

};
