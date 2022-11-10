#pragma once
#include"Definition.hpp"

class Tile_Data {
public:

	Tile_Data() {}

	Tile_Data(String _name, int _x, int _y) {
		name = _name;
		x = _x;
		y = _y;
	}

	String get_name() { return name; }
	int get_x() { return x; }
	int get_y() { return y; }

	void set_name(String v) { name = v; }

	void draw(double _x, double _y) {
		TextureAsset(name).draw(x * Definition::block_size - _x, y * Definition::block_size - _y);
	}


	template <class Archive>
	void SIV3D_SERIALIZE(Archive& archive)
	{
		archive(name, x, y);
	}

private:

	String name;
	int x, y;

};
