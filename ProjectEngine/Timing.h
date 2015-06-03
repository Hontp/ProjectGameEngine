#pragma once

#include "SFML_Timing.h"


class Timing
{
public:
	Timing();
	~Timing();

	float getElapsedTime();

private:
	SFML_Timing timer;
};

