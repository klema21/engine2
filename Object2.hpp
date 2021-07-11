#ifndef OBJECT2_HPP
#define OBJECT2_HPP

#include "ObjectBase.hpp"

class Object2 : public ObjectBase {
	std::string project;
	bool active;
public:
	~Object2();
	void setValue(std::string name, std::string value);
	void setValue(std::string name, bool b);
};

Object2::~Object2() {
	puts("-------OBJ2-------");
	std::cout << "project: " << project << std::endl;
	std::cout << "active: " << active << std::endl;
}

void Object2::setValue(std::string name, std::string value) {
	if (name == "project") {
		project = value;
	}
}

void Object2::setValue(std::string name, bool b) {
	if (name == "active")
		active = b;
}

#endif
