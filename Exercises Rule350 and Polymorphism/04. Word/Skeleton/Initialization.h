#pragma once
#ifndef INIT_H
#define INIT_H

#include <iostream>
#include "CommandInterface.h"

class Cut : public TextTransform {
public:
	std::string accumulator;

	virtual void invokeOn(std::string& text, int startIndex, int endIndex) override {
		std::string lastCut;
		accumulator = std::string(text.begin() + startIndex, text.begin() + endIndex);

		text.erase(text.begin() + startIndex, text.begin() + endIndex);
	}
};

class Paste : public TextTransform {
	std::shared_ptr<Cut> fromCutPtr;
public:
	Paste(std::shared_ptr<Cut> cutPtr) : fromCutPtr(cutPtr) {}

	virtual void invokeOn(std::string& text, int startIndex, int endIndex) override {
		std::string toPaste = fromCutPtr->accumulator;

		text.replace(text.begin() + startIndex, text.begin() + endIndex, toPaste);
	}

};

class Common : public CommandInterface {
	std::string& text;
public:
	Common(std::string& text) : CommandInterface(text), text(text) {}

	virtual std::vector<Command> initCommands() {
		std::vector<Command> commands;

		std::shared_ptr<Cut> cutPtr = std::make_shared<Cut>();
		std::shared_ptr<TextTransform> pastePtr = std::make_shared<Paste>(cutPtr);

		commands = CommandInterface::initCommands();
		commands.push_back(Command("cut", cutPtr));
		commands.push_back(Command("paste", pastePtr));

		return commands;
	}

};

std::shared_ptr<CommandInterface> buildCommandInterface(std::string& text) {
	std::shared_ptr<CommandInterface> interface = std::make_shared<Common>(text);
	interface->init();

	return interface;
}
#endif // !INIT_H
