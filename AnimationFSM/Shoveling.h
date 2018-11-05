#ifndef SHOVELING_H
#define SHOVELIING_H

#include <State.h>

class Shoveling : public State
{
public:
	Shoveling() {};
	~Shoveling() {};
	void idle(Animation *a);

};
#endif // !SHOVELING_H
