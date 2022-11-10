﻿#pragma once

class Weapon {
public:

	Weapon(){}

	void update(double d_time) {
		cool_time -= d_time;

		if (cool_time < 0) {
			cool_time = 0;
		}

	}

	String get_name() { return name; }
	void set_name(String v) { name = v; }

	void set_cool_time(double v) {
		cool_time = v;
	}

	bool get_can_use() {
		
		if (cool_time <= 0) {
			return true;
		}
		return false;
	}
	

private:
	String name = U"shot_gun";

	double cool_time = 0;
};
