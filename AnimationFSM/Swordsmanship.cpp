#include "Idle.h"
#include "Swordsmanship.h"

#include <string>

void Swordsmanship::idle(Animation *a)
{
	std::cout << "Swordsmanship -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}