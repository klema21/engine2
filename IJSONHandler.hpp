#ifndef IJSONHANDLER_HPP
#define IJSONHANDLER_HPP


#include "IHandler.hpp"
#include "rapidjson/error/en.h"
#include "rapidjson/reader.h"
#include "rapidjson/writer.h"
#include "rapidjson/document.h"

class IJSONHandler
	: public rapidjson::BaseReaderHandler<rapidjson::UTF8<>, IJSONHandler> {
	IHandler *h;
public:
	IJSONHandler(IHandler* p) : h(p){
		state_ = kExpectedKey;
	}
	bool StartObject() {
		return true;
	}
	bool String(const char* str, rapidjson::SizeType length, bool) {
		switch (state_) {
		case kExpectedKey:
			name_ = str;
			state_ = kExpectedValue;
			return true;
		case kExpectedValue:
			h->pushValue(name_, static_cast<std::string>(str));
			state_ = kExpectedKey;
			return true;
		};
		return true;
	}

	bool Int(int i) {
		switch (state_) {
		case kExpectedValue:
			h->pushValue(name_, i);
			state_ = kExpectedKey;
			return true;
		case kArrayStarted:
			h->pushValue(name_, i);
			return true;
		}
		return true;
	}

	bool Uint(unsigned u) {
		switch (state_) {
		case kExpectedValue:
			h->pushValue(name_, static_cast<int>(u));
			state_ = kExpectedKey;
			return true;
		case kArrayStarted:
			h->pushValue(name_, static_cast<int>(u));
			return true;
		}
		return true;
	}

	bool Double(double d) {
		switch (state_) {
		case kExpectedValue:
			h->pushValue(name_, d);
			state_ = kExpectedKey;
			return true;
		}
		return true;
	}
	bool Bool(bool b) {
		switch (state_) {
		case kExpectedValue:
			h->pushValue(name_, b);
			state_ = kExpectedKey;
			return true;
		}
		return true;
	}
	bool StartArray() {
		state_ = kArrayStarted;
		return true;
	}

	bool EndArray(rapidjson::SizeType) {
		state_ = kExpectedKey;
		return true;
	}
	bool EndObject(rapidjson::SizeType) {
		return true;
	}
	bool Default() {
		return false;
	}
	enum State {
		kExpectedKey,
		kExpectedValue,
		kArrayStarted
	} state_;
	std::string name_;
};

#endif
