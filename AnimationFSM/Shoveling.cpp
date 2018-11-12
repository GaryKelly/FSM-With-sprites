#include "Idle.h"
#include "Shoveling.h"
#include "Walking.h"
#include <string>

void Shoveling::idle(Animation *a)
{
	std::cout << "Shoveling -> Idle" << std::endl;
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Idle());
	delete this;
}

void Shoveling::walking(Animation * a)
{
	std::cout << "Idle -> Walking" << std::endl;
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Walking());
	delete this;
}
