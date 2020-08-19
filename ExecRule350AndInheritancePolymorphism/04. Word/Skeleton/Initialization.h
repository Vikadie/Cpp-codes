#pragma once
#ifndef INITIALIZATION_H
#define INITIALIZATION_H

#include "AdvancedInterface.h"

std::shared_ptr<CommandInterface> buildCommandInterface(std::string& text) {

	std::shared_ptr<CommandInterface> interface = std::make_shared<AdvancedInterface>(text);
	interface->init();

	return interface;
}
#endif // !INITIALIZATION_H
