﻿#pragma once

#include"Definition.hpp"

class Event_Data {
public:

	Event_Data() {

		x = 0;
		y = 0;
	}

	Event_Data(String _name, int _x, int _y) {
		name = _name;
		x = _x;
		y = _y;

		if (name == U"life_server") {
			number = 0;
		}
		else if (name == U"save_server") {
			number = 1;
		}
	}


	String get_name() { return name; }
	int get_x() { return x; }
	int get_y() { return y; }
	int get_number() { return number; }
	int get_start() { return start; }

	void set_name(String v) { name = v; }

	void set_number(int v) { number = v; }
	void set_start(int v) { start = v; }

	void draw(double _x, double _y) {
		TextureAsset(name).draw(x * Definition::block_size - _x, y * Definition::block_size - _y);
	}



	void draw_edit(double _x, double _y) {
		TextureAsset(name).draw(x * Definition::block_size - _x, y * Definition::block_size - _y);
	}


	template <class Archive>
	void SIV3D_SERIALIZE(Archive& archive)
	{
		archive(name, x, y,number,start);
	}

private:

	String name;
	int x, y;

	int number = 0;

	int start = 0;

};
