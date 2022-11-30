#pragma once
#include <SFML/Graphics.hpp>
#include "Etoile.h"


class Starfield
{
private:
	std::vector<Etoile> etoiles;

public:
	Starfield();
	void run();
};

