#pragma once

class Weapon {
public:

	Weapon(){}

	void update(double d_time) {

		if (cool_time == 0) {

			if (energy < 100) {
				energy += 50 * d_time;
			}

			if (energy > 100) {
				energy = 100;
			}

		}



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

	double get_energy() { return energy; }
	int get_max_energy() { return max_energy; }

	void use_energy(int v) {
		energy -= v;
		if (energy < 0) {
			energy = 0;
		}
	}

	void full_energy() { energy = max_energy; }


private:
	String name = U"shot_gun";

	double cool_time = 0;

	double energy = 100;

	int max_energy = 100;
};
