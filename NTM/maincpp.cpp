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
	// Réinitialiser le seed de la map
	srand(time(NULL));

	// Initialisation classe map
	Map grille(0.40f, 4, 3, 3, 900);

	// Tableau des cellules
	int map[grille.largeurGrille][grille.hauteurGrille] = { {0} };

	// Générer et récupérer la map
	grille.genererMap();
	grille.getMap(map);

	// Taille d'affichage des pixels
	float lPix = 10;
	float hPix = 10;

	for (int x = 0; x < grille.getLargeurGrille(); x++) {
		for (int y = 0; y < grille.getHauteurGrille(); y++) {
			cout << map[x][y];
		}
		cout << endl;
	}

	//Création et position des rectangle
	vector<sf::RectangleShape> vRect;
	for (int x = 0; x < grille.getLargeurGrille(); x++) {
		for (int y = 0; y < grille.getHauteurGrille(); y++) {
			if (map[x][y] != 1) {
				sf::RectangleShape r;
				r.setSize(sf::Vector2f(lPix, hPix));
				r.setPosition((20 * y) + hPix, (20 * x) + lPix);
				if (map[x][y] == 2) {
					r.setFillColor(sf::Color::Red);
				}
				else if (map[x][y] == 3) {
					r.setFillColor(sf::Color::Blue);
				}
				else if (map[x][y] == 4) {
					r.setFillColor(sf::Color::Yellow);
				}
				else if (map[x][y] == 5) {
					r.setFillColor(sf::Color::White);
				}
				else if (map[x][y] == 6) {
					r.setFillColor(sf::Color(128, 128, 128));
				}
				vRect.push_back(r);
			}
		}
	}

	// Initialisation de la fenêtre
	sf::RenderWindow window(sf::VideoMode(Largeur, Hauteur), "Deutschlandais fou", sf::Style::Fullscreen);

	// View handlers
	sf::View view(sf::Vector2f(grille.getPosJoueurX(), grille.getPosJoueurY()), sf::Vector2f(Largeur, Hauteur));
	view.zoom(0.20f);
	sf::View viewMinimap(sf::FloatRect(0, 0, Largeur, Hauteur));

	viewMinimap.setViewport(sf::FloatRect(0, 0, 0.3f, 0.3f));
	view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
	sf::RectangleShape minimapBG;
	// TODO : a affiner
	minimapBG.setSize(sf::Vector2f(Largeur / 1.75, Hauteur));
	minimapBG.setFillColor(sf::Color::Black);


	// Texture du joueur
	sf::Texture textureJoueur;
	if (!textureJoueur.loadFromFile("assets/spritesheet.png"))
		return EXIT_FAILURE;
	Joueur joueur(&textureJoueur, sf::Vector2u(9, 4), 0.1f, 150.0f);

	// Temps avant changement de sprites (animation)
	/*float deltaTime = 0.0f;
	sf::Clock horloge;*/

	while (window.isOpen()) {

		//deltaTime = horloge.restart().asSeconds();

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

		window.clear();

		view.setCenter((grille.getPosJoueurY() * 20) + lPix, (grille.getPosJoueurX() * 20) + lPix);
		window.setView(view);

		// Affichage map
		for (auto &j : vRect) {
			window.draw(j);
		}

		window.setView(viewMinimap);
		window.draw(minimapBG);
		for (auto &i: vRect) {
			if (i.getFillColor() == sf::Color::Red) {
				i.setFillColor(sf::Color::Green);
			}
			window.draw(i);
			if (i.getFillColor() == sf::Color::Green) {
				i.setFillColor(sf::Color::Red);
			}
		}

		//joueur.Update(deltaTime);
		//joueur.Draw(window);

		window.display();
	}

	return EXIT_SUCCESS;
}

