#pragma once

class Edit_Block {

public:

	Edit_Block(String _name) {
		name = _name;
	}

	String get_name() { return name; }


private:

	String name;

};

