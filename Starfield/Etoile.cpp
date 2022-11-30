#include "Etoile.h"
#include <cstdlib>
#include<random>
#include<iostream>

Etoile::Etoile() {
	this->z = std::rand() % 4000;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(-width, width);
	std::uniform_int_distribution<int> dis2(-height, height);
	this->x = dis(gen);
	this->y = dis2(gen);
	this->formeCercle.setRadius(radius);
	this->formeCercle.setPosition(this->x, this->y);
	this->formeCercle.setFillColor(sf::Color::White);
}

const sf::CircleShape Etoile::getCercle()
{
	return this->formeCercle;
}

void Etoile::update() {
	z -= 10;     
	if (z < 1) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(-width, width);
		std::uniform_int_distribution<int> dis2(-height, height);
		this->x = dis(gen);
		this->y = dis2(gen);
		z = std::rand() % 4000;
		this->formeCercle.setPosition(this->x, this->y);
	}
}

void Etoile::draw() {
	float offsetX = 3*(x / z);
	float offsetY = 3*(y / z);
	float scaleZ = 0.0001*(5000.0 - z);

	this->formeCercle.move(offsetX, offsetY);
	
	this->formeCercle.setScale(scaleZ, scaleZ);
}


