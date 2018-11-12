#include "Idle.h"
#include "Hammering.h"
#include "Walking.h"
#include <string>

void Hammering::idle(Animation *a)
{
	std::cout << "Hammering -> Idle" << std::endl;
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Idle());
	delete this;
}

void Hammering::walking(Animation * a)
{
	std::cout << "Idle -> Walking" << std::endl;
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Walking());
	delete this;
}
