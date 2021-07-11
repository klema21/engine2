#ifndef IHANDLER_HPP
#define IHANDLER_HPP

#include "ObjectBase.hpp"

class IHandler{
	ObjectBase *n;
public:
	IHandler(ObjectBase *p) : n(p){}

	template <typename T>
	void pushValue(std::string name, T value){
		n->setValue(name, value);
	}
};

#endif
