#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "IJSONParser.hpp"
#include "IHandler.hpp"

class Engine {

public:
	void Parse(const char* json, ObjectBase* p);
};

void Engine::Parse(const char* json, ObjectBase* p){
	IHandler* h = new IHandler(p);
	IJSONParser(json, h);
	delete h;
}

#endif
