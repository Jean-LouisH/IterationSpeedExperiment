#include "ExecutionTimer.hpp"

double ExecutionTimer::getDeltaTime_s()
{
	return this->deltaTime_s;
}

void ExecutionTimer::setStart()
{
    this->start = clock();
}

void ExecutionTimer::setEnd()
{
	this->end = clock();
	this->deltaTime_s = ((double) (this->end - this->start) / CLOCKS_PER_SEC);
}
