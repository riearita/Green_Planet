#pragma once

class Guide {

public:

	Guide(String _name,int _x,int _y) {
		name = _name;
		pos.x = _x;
		pos.y = _y;
	}

	void update(double d_time) {

	}

	void draw(double _x, double _y) {


		TextureAsset(name).draw(pos.x - _x, pos.y - _y);
	}

private:

	String name;

	Vec2 pos;



};
