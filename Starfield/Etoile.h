#pragma once
#include <SFML/Graphics.hpp>
#include<random>

const static int width = 500;
const static int height = 500;

class Etoile
{
private:
	double x;
	double y;
	double z;
	double radius = 1.5f;
	sf::CircleShape formeCercle;
public:
	Etoile();
	void draw();
	void update();
	const sf::CircleShape getCercle();
};

