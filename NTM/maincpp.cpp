#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Animation.h"
#include "Joueur.h"
#include <iostream>
#include <stdlib.h>
//La vie
using namespace std;

// Largeur et Hauteur de l'écran
unsigned int const Largeur = sf::VideoMode::getDesktopMode().width;
unsigned int const Hauteur = sf::VideoMode::getDesktopMode().height;

// Largeur et Hauteur de la génération de caves
unsigned int const largeurCell = 50;
unsigned int const hauteurCell = 50;

// Cahnce Initaile de vie d'une cellule
float const chanceInitVie = 0.40;

// Controle de la destruction/création de cellules voisines
unsigned int const limiteMort = 4;
unsigned int const limiteNaissance = 3;

// Nombre de répétitions
unsigned int const nbSimulations = 3;

// Taille pixels
float lPix = sf::VideoMode::getDesktopMode().width / largeurCell;
float hPix = sf::VideoMode::getDesktopMode().height / hauteurCell;

// Position de départ
unsigned int depX = 20;
unsigned int depY = 20;

// Initialisation
void mapInit(bool map[largeurCell][hauteurCell]) {
	float nbAlea;
	for (int x = 0; x < largeurCell; x++) {
		for (int y = 0; y < hauteurCell; y++) {
			nbAlea  = float(rand() % 100);
			if ((nbAlea / 100 ) < chanceInitVie) {
				map[x][y] = true;
			}
			else {
				map[x][y] = false;
			}
		}
	}
}

int nbVoisinsVivants(bool map[largeurCell][hauteurCell], int x, int y) {
	int nb = 0;
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			int voisin_x = x + i;
			int voisin_y = y + j;

			if (i == 0 && j == 0) {}
			else if (voisin_x < 0 || voisin_y < 0 || voisin_x >= largeurCell || voisin_y >= hauteurCell) {
				nb = nb + 1;
			}
			else if (map[voisin_x][voisin_y]) {
				nb = nb + 1;
			}
		}
	}
	return nb;
}


// Nombre d'itérations de lissage
void etapeSimulation(bool mapOld[largeurCell][hauteurCell], bool mapNew[largeurCell][hauteurCell]) {
	for (int x = 0; x < largeurCell; x++) {
		for (int y = 0; y < hauteurCell; y++) {
			int nbVoisins = nbVoisinsVivants(mapOld, x, y);
			if (mapOld[x][y]) {
				if (nbVoisins < limiteMort) {
					mapNew[x][y] = false;
				}
				else {
					mapNew[x][y] = true;
				}
			}
			else {
				if (nbVoisins > limiteNaissance) {
					mapNew[x][y] = true;
				}
				else {
					mapNew[x][y] = false;
				}
			}
		}
	}
}


// Regroupe toutes les fonctions au dessus
void genererMap(bool map[largeurCell][hauteurCell]) {
	mapInit(map);	
	bool mapNew[largeurCell][hauteurCell] = { {false} };
	for (int i = 0; i < nbSimulations; i++) {
		etapeSimulation(map, mapNew);
		for (int x = 0; x < largeurCell; x++) {
			for (int y = 0; y < hauteurCell; y++) {
				map[x][y] = mapNew[x][y];
			}
		}
	}
}

int main() {
	srand(time(NULL));
	// Tableau des cellules
	bool map[largeurCell][hauteurCell] = { {false} };

	genererMap(map);


	/*for (int x = 0; x < largeurCell; x++) {
		for (int y = 0; y < hauteurCell; y++) {
			cout << map[x][y];
		}
		cout << endl;
	}
	cout << endl << endl << endl;*/
	

	

	vector<sf::RectangleShape> vRect;

	for (int x = 0; x < largeurCell; x++) {
		for (int y = 0; y < hauteurCell; y++) {
			if (!map[x][y]) {
				sf::RectangleShape r;
				r.setSize(sf::Vector2f(lPix, hPix));
				r.setPosition((depY * y) + hPix,(depX * x) + lPix);
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

		

		window.display();
	}

	return EXIT_SUCCESS;
}

