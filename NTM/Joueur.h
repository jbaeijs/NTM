#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include <windows.h>

class Joueur
{
public:
	Joueur(Map &grille, unsigned int lPix, unsigned int hPix);
	~Joueur();

	void Update(Map & grille, float deltaTime);

	void Draw(sf::RenderWindow &window);

	void setPosX(float posX) { this->posX = posX; };
	void setPosY(float posY) { this->posY = posY; };

public: 
	float posX;
	float posY;

	float tpsTotal;
	float tpsSwitch;

	sf::RectangleShape corps;
};

