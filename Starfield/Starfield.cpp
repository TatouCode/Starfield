#include "Starfield.h"
#include<random>

Starfield::Starfield() {
    std::random_device rd;
    std::mt19937 gen(rd());
	for (auto i = 0; i < 400; i++) {
		etoiles.push_back(Etoile());
	}
}

void Starfield::run() {
    sf::RenderWindow window(sf::VideoMode(width, height), "Starfield");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        
        
        for (auto& etoile : etoiles) {
            sf::Transform t;
            t.translate(width / 2, height / 2);
            window.draw(etoile.getCercle(), t);
            etoile.draw();
            etoile.update();

        }
        

        window.display();
    }
}
