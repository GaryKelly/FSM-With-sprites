#include "Idle.h"
#include "Swordsmanship.h"
#include "Walking.h"
#include <string>

void Swordsmanship::idle(Animation *a)
{
	std::cout << "Swordsmanship -> Idle" << std::endl;
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Idle());
	delete this;
}

void Swordsmanship::walking(Animation * a)
{
	std::cout << "Swordmanship -> Walking" << std::endl;
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Walking());
	delete this;
}
