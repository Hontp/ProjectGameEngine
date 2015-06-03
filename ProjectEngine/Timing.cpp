#include "Timing.h"


Timing::Timing()
{
}


Timing::~Timing()
{
}

float Timing::getElapsedTime()
{
	return timer.getElapsedTotalTime();
}