#ifndef IJSONPARSER_HPP
#define IJSONPARSER_HPP


#include "IHandler.hpp"
#include "IJSONHandler.hpp"
#include "rapidjson/error/en.h"
#include "rapidjson/reader.h"
#include "rapidjson/writer.h"
#include "rapidjson/document.h"

class IJSONParser {
	
public:
	IJSONParser(const char* json, IHandler* h);
};

IJSONParser::IJSONParser(const char* json, IHandler* h) {
	rapidjson::Reader read;
	rapidjson::StringStream ss(json);
	IJSONHandler oh(h);
	read.Parse(ss, oh);
}

#endif
