#pragma once
#ifndef INIT_H
#define INIT_H

#include "Extractor.h"

class Digits : public Extractor {
public:
	Digits(std::istream& lineIn) : Extractor(lineIn) {}

	bool process(char symbol, std::string& output) override {
		if (isdigit(symbol)) {
			output = symbol;
			return true;
		}
		return false;
	}
};

class Numbers : public Extractor {
	bool start;
	std::string temp;
public:
	Numbers(std::istream& lineIn): Extractor(lineIn), start(false){}

	bool process(char symbol, std::string& output) override {
		if (isdigit(symbol)) {
			start = true;
		}
		if (start)
			if (isdigit(symbol))
				temp += symbol;
			else {
				if (temp.empty())
					return false;
				output = temp;
				temp = "";
				start = false;
				return true;
			}
		return false;
	}
};

class Quotes : public Extractor {
	bool start;
	std::string temp;
public:
	Quotes(std::istream& lineIn): Extractor(lineIn), start(false) {}

	bool process(char symbol, std::string& output) override {
		if (symbol == '"') {
			start = true;
		}
		if (start)
			if (symbol != '"')
				temp += symbol;
			else {
				if (temp.empty())
					return false;
				output = temp;
				temp = "";
				start = false;
				return true;
			}
		return false;
	}
};

std::shared_ptr<Extractor> getExtractor(const std::string& extractType, std::istringstream& lineIn) {
	std::shared_ptr<Extractor> s = nullptr;
	if (extractType == "digits")
		s = std::make_shared<Digits>(lineIn);
	else if (extractType == "numbers")
		s = std::make_shared<Numbers>(lineIn);
	else if (extractType == "quotes")
		s = std::make_shared<Quotes>(lineIn);

	return s;
}

#endif // !INIT_H
