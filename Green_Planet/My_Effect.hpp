#pragma once

class My_Effect {

public:

	My_Effect(String _name,double x,double y) {

		name = _name;
		pos.x = x;
		pos.y = y;

		first();
	}

	void update(double);

	void draw(double,double);

	void first();

	bool get_delete();

private:

	String name;


	Vec2 pos;

	double count = 0;

	double delete_count = 0;

	double wide = 0;
	double height = 0;

	double adjust_x=0;
	double adjust_y=0;

	double fade_v=0;
	double fade_delete=0;
	double fade_plus = 0;

	double size=0;
	double size_up=0;//一秒あたりの増加量
	double size_down=0;
};
