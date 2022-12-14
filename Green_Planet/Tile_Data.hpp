#pragma once
#include"Definition.hpp"

class Tile_Data {
public:

	Tile_Data() {

		x = 0;
		y = 0;
	}

	Tile_Data(String _name,int _layer, int _x, int _y) {
		name = _name;
		layer = _layer;
		x = _x;
		y = _y;
	}

	String get_name() { return name; }
	int get_x() { return x; }
	int get_y() { return y; }

	int get_layer() { return layer; }

	void set_name(String v) { name = v; }

	void draw(double _x, double _y) {
		TextureAsset(name).draw(x * Definition::block_size - _x, y * Definition::block_size - _y);
	}


	template <class Archive>
	void SIV3D_SERIALIZE(Archive& archive)
	{
		archive(name,layer, x, y);
	}

private:

	String name;
	int x = 0;
	int y = 0;

	int layer = 0;

};
