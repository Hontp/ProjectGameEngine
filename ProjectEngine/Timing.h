#pragma once
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>

class Timing
{

public:
	Timing();
	~Timing();

	float getElapsedTime();
private:
	sf::Clock clock;
	sf::Time time;
};

