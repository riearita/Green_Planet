#pragma once

class Edit_Enemy {

public:

	Edit_Enemy(String _name) {
		name = _name;
	}

	String get_name() { return name; }


private:

	String name;

};
