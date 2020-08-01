#include "Word.h"

Word::Word(std::string wordStr_): wordStr(wordStr_)
{
	wordMap[wordStr]++;
}

bool Word::operator<(const Word& w1) const
{
	return this->getWord() < w1.getWord();
}

std::string Word::getWord() const
{
	return this->wordStr;
}

int Word::getCount() const
{
	std::map<std::string, int>::iterator itr = wordMap.find(this->wordStr);
	int to_return = itr->second;
	wordMap.erase(itr);
	return to_return;
}
