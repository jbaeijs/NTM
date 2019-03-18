#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Animation.h"
#include "Joueur.h"
#include "Map.h"
#include "Objet.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

// Largeur et Hauteur de l'écran
unsigned int const Largeur = sf::VideoMode::getDesktopMode().width;
unsigned int const Hauteur = sf::VideoMode::getDesktopMode().height;

int main() {
	srand(time(NULL));
	// Tableau des cellules

	Map grille(0.40f, 4, 3, 3);

	int map[grille.largeurGrille][grille.hauteurGrille] = { {0} };


	grille.genererMap(map);

	float lPix = sf::VideoMode::getDesktopMode().width / grille.getLargeurGrille();
	float hPix = sf::VideoMode::getDesktopMode().height / grille.getHauteurGrille();

	vector<sf::RectangleShape> vRect;

	for (int x = 0; x < grille.getLargeurGrille(); x++) {
		for (int y = 0; y < grille.getHauteurGrille(); y++) {
			if (!map[x][y]) {
				sf::RectangleShape r;
				r.setSize(sf::Vector2f(lPix, hPix));
				r.setPosition((20 * y) + hPix,(20 * x) + lPix);
				r.setFillColor(sf::Color::White);
				vRect.push_back(r);
			}
		}
	}

	//Création et position des rectangle

	// Initialisation de la fenêtre
	sf::RenderWindow window(sf::VideoMode(Largeur, Hauteur), "Deutschlandais fou", sf::Style::Fullscreen);

	// Texture et sprite du bouton quitter
	sf::Texture quitter;
	if (!quitter.loadFromFile("assets/quitter.png"))
		return EXIT_FAILURE;
	sf::Sprite sQuitter(quitter);
	sQuitter.setPosition((float)Largeur - 200, 0.0f);

	// Texture du joueur
	sf::Texture textureJoueur;
	if (!textureJoueur.loadFromFile("assets/spritesheet.png"))
		return EXIT_FAILURE;
	Joueur joueur(&textureJoueur, sf::Vector2u(9, 4), 0.1f, 150.0f);

	unsigned int const nbObjets = 10;

	//liste des différents objets

	Objet *tabObjets[nbObjets];
	for (int i = 0; i < nbObjets; i++)
	{
		
	}

	// Temps avant changement de sprites (animation)
	float deltaTime = 0.0f;
	sf::Clock horloge;

	while (window.isOpen()) {

		//deltaTime = horloge.restart().asSeconds();

		sf::Vector2i posSouris = sf::Mouse::getPosition(window);
		sf::Vector2f posSourisF(static_cast<float>(posSouris.x), static_cast<float>(posSouris.y));

		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::MouseMoved:
				
				if (sQuitter.getGlobalBounds().contains(posSourisF)) {
					sQuitter.setColor(sf::Color(255, 20, 20));
				}
				else {
					sQuitter.setColor(sf::Color(255, 255, 255));
				}
				break;

			case sf::Event::MouseButtonPressed:
				if (sQuitter.getGlobalBounds().contains(posSourisF)) {
					window.close();
				}
				break;
			}

		}

		window.clear();

		window.draw(sQuitter);

		for (auto j = vRect.begin(); j != vRect.end(); j++) {
			window.draw(*j);
		}

		//joueur.Update(deltaTime);
		//joueur.Draw(window);
		window.draw(angband);
		window.draw(angband2);

		window.display();
	}

	return EXIT_SUCCESS;
}

