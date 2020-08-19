#pragma once
#ifndef ADVANCED_INTERFACE_H
#define ADVENCED_INTERFACE_H

#include "CommandInterface.h"
#include "Cut.h"
#include "Paste.h"

class AdvancedInterface : public CommandInterface {
public:
	AdvancedInterface(std::string& text) : CommandInterface(text) {}

	virtual std::vector<Command> initCommands() {
		std::vector<Command> commands = CommandInterface::initCommands();

		auto cutPtr = std::make_shared<Cut>();
		auto pastePtr = std::make_shared<Paste>(cutPtr);

		commands.push_back(Command("cut", cutPtr));
		commands.push_back(Command("paste", pastePtr));

		return commands;
	}

};
#endif // !ADVANCED_INTERFACE_H
