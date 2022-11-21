#pragma once

class Back {

public:

	Back(){}

	void set_name(String v) { name = v; }


	void draw(double x,double y) {
		
		//TextureAsset(name).draw(0 - x, 0 - y);

		TextureAsset(name).draw(0, 0 - y);

		
	}

private:


	String name;
};
