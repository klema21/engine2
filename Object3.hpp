#ifndef OBJECT3_HPP
#define OBJECT3_HPP

#include "ObjectBase.hpp"
#include <vector>

class Object3 : public ObjectBase {
	std::string hello;
	bool t;
	bool f;
	int i_;
	double pi;
	std::vector<int> a;
public:
	~Object3();
	void setValue(std::string name, std::string value);
	void setValue(std::string name, bool b);
	void setValue(std::string name, int i);
	void setValue(std::string name, double d);
};

Object3::~Object3() {
	puts("-------OBJ3-------");
	std::cout << "hello :" << hello << std::endl;
	std::cout << "t :" << t << std::endl;
	std::cout << "f :" << f << std::endl;
	std::cout << "i_ :" << i_ << std::endl;
	std::cout << "pi :";
	for (auto o : a) std::cout << o << " ";
	std::cout << std::endl;
}

void Object3::setValue(std::string name, std::string value) {
	if (name == "hello") {
		hello = value;
	}
}

void Object3::setValue(std::string name, bool b) {
	if (name == "t")
		t = b;
	if (name == "f")
		f = b;
}

void Object3::setValue(std::string name, int i) {
	if (name == "i")
		i_ = i;
	if (name == "a") {
		a.push_back(i);
	}
}

void Object3::setValue(std::string name, double d) {
	if (name == "pi")
		pi = d;
}





#endif
