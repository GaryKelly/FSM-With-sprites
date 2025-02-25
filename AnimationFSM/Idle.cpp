#include <Idle.h>
#include <Jumping.h>
#include <Climbing.h>
#include <Jumping.h>
#include <Hammering.h>
#include <Swordsmanship.h>
#include <Shoveling.h>
#include <Walking.h>

#include <string>

void Idle::handleInput() {}
void Idle::update() {}

void Idle::jumping(Animation* a)
{
	std::cout << "Idle -> Jumping" << std::endl;
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Jumping());
	delete this;
}
void Idle::climbing(Animation* a)
{
	std::cout << "Idle -> Climbing" << std::endl;
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Climbing());
	delete this;
}

void Idle::hammering(Animation * a)
{
	std::cout << "Idle -> Hammering" << std::endl;
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Hammering());
	delete this;
}

void Idle::swordsmanship(Animation * a)
{
	std::cout << "Idle -> Swordsmanship" << std::endl;
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Swordsmanship());
	delete this;
}

void Idle::shoveling(Animation * a)
{
	std::cout << "Idle -> Shoveling" << std::endl;
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Shoveling());
	delete this;
}

void Idle::walking(Animation * a)
{
	std::cout << "Idle -> Walking" << std::endl;
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Walking());
	delete this;
}
