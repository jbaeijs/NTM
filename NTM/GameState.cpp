#include "GameState.h"
#include <stdlib.h>
#include <iostream>

using namespace std;


GameState::GameState(float largeur, float hauteur):
	grille(0.40f, 4, 3, 3, 900),
	viewJeu(sf::Vector2f(0, 0), sf::Vector2f(largeur, hauteur)),
	viewMinimap(sf::FloatRect(0, 0, largeur, hauteur)),
	joueur(grille, 10, 10)
{
	this->largeur = largeur;
	this->hauteur = hauteur;
	this->gameState = 1;
	this->gameLoaded = false;

	viewJeu.zoom(0.20f);
	viewJeu.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
	viewMinimap.setViewport(sf::FloatRect(0, 0, 0.3f, 0.3f));
	
	minimapBG.setSize(sf::Vector2f(largeur / 1.75, hauteur));
	minimapBG.setFillColor(sf::Color::Black);

}


GameState::~GameState()
{
}

void GameState::Update()
{
}

void GameState::Draw(sf::RenderWindow & window, float deltaTime)
{
	switch (this->gameState)
	{
	case 0 : 
		cout << "Menu" << endl;
		break;
	
	case 1 : 
		if (!gameLoaded) {
			unsigned int const largeurGrille = grille.largeurGrille;
			unsigned int const hauteurGrille = grille.hauteurGrille;
			int map[largeurGrille][hauteurGrille] = { {0} };
			grille.genererMap();
			grille.getMap(map);

			joueur.setPosX(grille.getPosJoueurX());
			joueur.setPosY(grille.getPosJoueurY());

			for (int x = 0; x < grille.getLargeurGrille(); x++) {
				for (int y = 0; y < grille.getHauteurGrille(); y++) {
					if (map[x][y] != 1) {
						sf::RectangleShape r;
						r.setSize(sf::Vector2f(10, 10));
						r.setPosition((20 * y) + 10, (20 * x) + 10);
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

			gameState++;
			gameLoaded = true;
		}
		break;

	case 2 :
		window.clear();
		viewJeu.setCenter((grille.getPosJoueurY() * 20) + 10, (grille.getPosJoueurX() * 20) + 10);
		window.setView(viewJeu);
		// Affichage map
		for (auto &j : vRect) {
			window.draw(j);
		}
		joueur.Update(grille, deltaTime);
		joueur.Draw(window);

		window.setView(viewMinimap);
		window.draw(minimapBG);
		for (auto &i : vRect) {
			if (i.getFillColor() == sf::Color::Red) {
				i.setFillColor(sf::Color::Green);
			}
			window.draw(i);
			if (i.getFillColor() == sf::Color::Green) {
				i.setFillColor(sf::Color::Red);
			}
		}
		joueur.Draw(window);


		window.display();
		break;
	}
}
