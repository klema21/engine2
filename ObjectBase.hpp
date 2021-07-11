#ifndef OBJECTBASE_HPP
#define OBJECTBASE_HPP

#include <iostream>
#include <string>

class ObjectBase {

public:
	virtual void setValue(std::string name, std::string value){}
	virtual void setValue(std::string name, bool b) {}
	virtual void setValue(std::string name, int i){}
	virtual void setValue(std::string name, double d) {}
	virtual ~ObjectBase(){}
};

#endif
