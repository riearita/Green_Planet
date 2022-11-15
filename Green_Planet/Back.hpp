#pragma once

class Back {

public:

	Back(){}




	void draw() {
		Rect rect(0, 0, 1920, 1080);
		rect.draw(color);
	
	}

private:

	ColorF color = Palette::Lightskyblue;
};
