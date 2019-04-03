#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Animation.h"
#include "Joueur.h"
#include "Map.h"
#include "Objet.h"
#include "GameState.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

// Largeur et Hauteur de l'écran
unsigned int const Largeur = sf::VideoMode::getDesktopMode().width;
unsigned int const Hauteur = sf::VideoMode::getDesktopMode().height;

int main() {
	// Réinitialiser le seed de la map
	srand(time(NULL));

	GameState game(Largeur, Hauteur);

	// Initialisation de la fenêtre
	sf::RenderWindow window(sf::VideoMode(Largeur, Hauteur), "Deutschlandais fou", sf::Style::Fullscreen);

	float deltaTime = 0.0f;
	sf::Clock horloge;

	while (window.isOpen()) {

		deltaTime = horloge.restart().asSeconds();

		// Récupérer position de la souris
		sf::Vector2i posSouris = sf::Mouse::getPosition(window);
		sf::Vector2f posSourisF(static_cast<float>(posSouris.x), static_cast<float>(posSouris.y));

		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			}

		}

		game.Draw(window, deltaTime);
	}

	return EXIT_SUCCESS;
}

