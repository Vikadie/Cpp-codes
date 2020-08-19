#pragma once
#ifndef EXTRACTOR_INITIALIZATION_H
#define EXTRACTOR_INITIALIZATION_H

#include "BufferedExtractor.h"

class Digit : public Extractor {
public:
	Digit(std::istream& stream): Extractor(stream){}

	bool process(char symbol, std::string& output) override {
		if (isdigit(symbol)) {
			output = symbol;
			return true;
		}
		return false;
	}

};

class Number : public BufferedExtractor {
public:
	Number(std::istream& stream) : BufferedExtractor(stream) {}

	virtual bool shouldBuffer(char symbol) override {
		if (isdigit(symbol))
			return true;
		return false;
	}

};

class Quotes : public BufferedExtractor {
	bool flag;
public:
	Quotes(std::istream& stream) : BufferedExtractor(stream), flag(false) {}

	virtual bool shouldBuffer(char symbol) override {
		if (!flag) {
			if (symbol == '"')
				flag = true;
			return false;
		}
		else {
			if (symbol != '"')
				return true;
			else
				flag = false;
		}
		return false;
	}

};

std::shared_ptr<Extractor> getExtractor(std::string& extractType, std::istringstream& lineIn) {
	std::shared_ptr<Extractor> s = nullptr;
	if (extractType == "digits")
		s = std::make_shared<Digit>(lineIn);
	if (extractType == "numbers")
		s = std::make_shared<Number>(lineIn);
	if (extractType == "quotes")
		s = std::make_shared<Quotes>(lineIn);
	return s;
}
#endif // !EXTRACTOR_INITIALIZATION_H
