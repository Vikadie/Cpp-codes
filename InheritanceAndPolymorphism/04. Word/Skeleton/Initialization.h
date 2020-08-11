#pragma once
#ifndef INITIALIZATION_H
#define INITIALIZATION_H

#include<algorithm>
#include "CommandInterface.h"

static std::string accumulator;

class extendCommandInterface: public CommandInterface{
public:
    extendCommandInterface(std::string& text_): CommandInterface(text_) { }

    virtual std::vector<Command> initCommands() override {
        std::vector<Command> commands = CommandInterface::initCommands();

        commands.push_back(Command("cut", std::make_shared<toCut>()));
        commands.push_back(Command("paste", std::make_shared<toPaste>()));

        return commands;
    }
    
    class toCut : public TextTransform {
    public:
        
        virtual void invokeOn(std::string& text, int startIndex, int endIndex) override {
            accumulator = "";
            if (startIndex == endIndex)
                accumulator.clear();
            else
                accumulator = text.substr(startIndex, endIndex - startIndex);
            std::string::iterator itr = text.begin();
            text.erase(itr + startIndex, itr + endIndex);
        }
    };

    class toPaste : public TextTransform {

        virtual void invokeOn(std::string& text, int startIndex, int endIndex) override {
            toCut cut;
            text = text.replace(startIndex, endIndex - startIndex, accumulator);
        }
    };

    ~extendCommandInterface() = default;
};

std::shared_ptr<CommandInterface> buildCommandInterface(std::string& text)
{
    std::shared_ptr<CommandInterface> inter = std::make_shared<extendCommandInterface>(text);
    inter->init();

    return inter;
}

#endif // !INITIALIZATION_H
