#pragma once
#ifndef CUT_H
#define CUT_H

class Cut : public TextTransform {
	std::string accumulator;
public:
    virtual void invokeOn(std::string& text, int startIndex, int endIndex) override {
        this->accumulator = text.substr(startIndex, endIndex - startIndex);
        text.erase(text.begin() + startIndex, text.begin() + endIndex);
    }

    std::string getAccumulator() {
        return this->accumulator;
    }
};
#endif // !CUT_H

