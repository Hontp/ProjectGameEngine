#include "SFML_Timing.h"


SFML_Timing::SFML_Timing()
{
}


SFML_Timing::~SFML_Timing()
{
}

float SFML_Timing::getElapsedTime()
{
	time = clock.restart();
	return(time.asMicroseconds());
}
