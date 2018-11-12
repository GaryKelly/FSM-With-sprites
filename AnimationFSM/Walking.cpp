#include "Walking.h"
#include "Idle.h"
#include "Climbing.h"
#include "Hammering.h"
#include "Shoveling.h"
#include "Jumping.h"
#include "Swordsmanship.h"

void Walking::idle(Animation * a)
{
	std::cout << "Walking -> Idling\n";
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Idle());
	delete this;
}

void Walking::jumping(Animation * a)
{
	std::cout << "Walking -> Jumping\n";
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Jumping());
	delete this;
}

void Walking::climbing(Animation * a)
{
	std::cout << "Walking -> Climbing\n";
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Climbing());
	delete this;
}

void Walking::hammering(Animation * a)
{
	std::cout << "Walking -> Hammering\n";
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Hammering());
	delete this;
}

void Walking::swordsmanship(Animation * a)
{
	std::cout << "Walking -> Swordsmanship\n";
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Swordsmanship());
	delete this;
}

void Walking::shoveling(Animation * a)
{
	std::cout << "Walking -> Shoveling\n";
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Shoveling());
	delete this;
}
