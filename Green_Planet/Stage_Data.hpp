#pragma once

class Stage_Data {

public:

	Stage_Data(String _name,String _back_name) {
		name = _name;
		back_name = _back_name;
	}

	String get_name() { return name; }
	String get_back_name() { return back_name; }

private:

	String name;

	String back_name;

};
