#pragma once
#include"Definition.hpp"

class Item_Data {
public:

	Item_Data(){}

	Item_Data(String _name, int _x, int _y) {
		name = _name;
		x = _x;
		y = _y;
	}

	String get_name() { return name; }
	int get_x() { return x; }
	int get_y() { return y; }

	void set_name(String v) { name = v; }

	void draw() {
		TextureAsset(name).draw(x * Definition::block_size, y * Definition::block_size);
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
