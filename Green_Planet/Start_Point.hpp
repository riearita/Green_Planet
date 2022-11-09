#pragma once

class Start_Point {
public:

	template <class Archive>
	void SIV3D_SERIALIZE(Archive& archive)
	{
		archive(name, x, y);
	}

private:

	String name;
	int x, y;

};
