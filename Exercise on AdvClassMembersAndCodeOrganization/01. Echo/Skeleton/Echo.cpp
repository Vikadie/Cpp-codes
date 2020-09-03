#include "Echo.h"

bool echoOn = true;

void echo(std::string s)
{
	if (echoOn)
	std::cout << s << std::endl;
}
