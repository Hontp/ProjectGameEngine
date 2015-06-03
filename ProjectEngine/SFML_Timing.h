#pragma once
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>

class SFML_Timing
{

public:
	SFML_Timing();
	~SFML_Timing();

	float getElapsedTotalTime();
private:
	sf::Clock clock;
	sf::Time time;
};

