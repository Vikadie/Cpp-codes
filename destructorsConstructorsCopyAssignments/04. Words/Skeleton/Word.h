#pragma once
#ifndef WORD_H
#define WORD_H

#include <map>
#include <string>

static std::map<std::string, int> wordMap;

class Word {
private:
	std::string wordStr;
public:
	Word() {	}
	Word(std::string wordStr_);

	bool operator<(const Word& w1) const;

	std::string getWord() const;

	int getCount() const;
};
#endif // !WORD_H

