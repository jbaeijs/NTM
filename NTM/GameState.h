#pragma once

#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Joueur.h"

class GameState
{
public:
	GameState(float largeur, float hauteur);
	~GameState();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow &window);

private:

	/*
	0 -> Menu
	1 -> Ecran de chargement (texte + musique)
	2 -> Jeu
	*/
	unsigned int gameState;

	bool gameLoaded;

	float largeur;
	float hauteur;

	vector<sf::RectangleShape> vRect;

	sf::RectangleShape minimapBG;
	sf::View viewJeu, viewMinimap;

	Map grille;

	Joueur joueur;
};

