#pragma once

class Edit_Tile {

public:

	Edit_Tile(String _name) {
		name = _name;
	}

	String get_name() { return name; }

private:

	String name;
};
