#pragma once

class Status {

public:

	void  plus_metal(int v) {

		metal += v;

		if (metal > metal_max) {
			metal = metal_max;
		}
	}

	int get_metal() { return metal; }

private:

	int metal = 0;
	int metal_max = 999;
};
