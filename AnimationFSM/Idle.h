#ifndef IDLE_H
#define IDLE_H

#include <State.h>

class Idle : public State
{
public:
	Idle() {};
	~Idle() {};
	void handleInput();
	void update();
	void jumping(Animation* a);
	void climbing(Animation* a);
	void hammering(Animation *a);
	void swordsmanship(Animation *a);
	void shoveling(Animation *a);
	void walking(Animation *a);
};

#endif // !IDLE_H