#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "ObjectBase.hpp"

class Object : public ObjectBase {
	std::string project;
public:
	~Object();
	void setValue(std::string name, std::string value);
};

Object::~Object() {
	puts("-------OBJ1-------");
	std::cout << "project: " << project << std::endl;
}

void Object::setValue(std::string name, std::string value) {
	if (name == "project") {
		project = value;
	}
}

#endif
