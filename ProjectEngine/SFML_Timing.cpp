#include "SFML_Timing.h"


SFML_Timing::SFML_Timing()
{
}


SFML_Timing::~SFML_Timing()
{
}

float SFML_Timing::getElapsedTotalTime()
{
	time = clock.getElapsedTime();
	return(time.asMilliseconds());
}
