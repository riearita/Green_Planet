#pragma once

class Edit_Event {

public:

	Edit_Event(String _name) {
		name = _name;
	}

	String get_name() { return name; }


private:

	String name;

};
