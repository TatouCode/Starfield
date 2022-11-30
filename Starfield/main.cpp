#include <SFML/Graphics.hpp>
#include <ctime>
#include"Etoile.h"
#include"Starfield.h"
#include<vector>
#include<iostream>
#include<random>


int main()
{
    Starfield starfield = Starfield();
    starfield.run();

    return 0;
}

