#pragma once

class Start_Point {
public:

	Start_Point(){

		x = 0;
		y = 0;
	}

	Start_Point(String _name, int _x, int _y) {
		name = _name;
		x = _x;
		y = _y;
	}

	int get_x() { return x; }
	int get_y() { return y; }

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
	int x;
	int	y;

};
