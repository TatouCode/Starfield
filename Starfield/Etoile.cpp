#include "Etoile.h"
#include <cstdlib>
#include<random>
#include<iostream>

Etoile::Etoile() {
	this->z = std::rand() % height;
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
	z -= 2;     
	if (z < 1) {
		z = std::rand() % height;
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(-width, width);
		std::uniform_int_distribution<int> dis2(-height, height);
		this->x = dis(gen);
		this->y = dis2(gen);
		this->formeCercle.setPosition(this->x, this->y);
	}
}

void Etoile::draw() {
	float offsetX = (x / z);
	float offsetY = (y / z);
	float scaleZ = 0.001*(2000.0 - z);

	this->formeCercle.move(offsetX, offsetY);
	
	this->formeCercle.setScale(scaleZ, scaleZ);
}


