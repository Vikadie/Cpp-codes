#pragma once
#ifndef PASTE_H
#define PASTE_H

class Paste : public TextTransform {
    std::shared_ptr<Cut> c;
public:  
    Paste(std::shared_ptr<Cut> c): c(c) {}
    virtual void invokeOn(std::string& text, int startIndex, int endIndex) override {
        
        std::string accumulator = c->getAccumulator();
        text.replace(text.begin() + startIndex, text.begin() + endIndex, accumulator);
    }
};
#endif // !PASTE_H
