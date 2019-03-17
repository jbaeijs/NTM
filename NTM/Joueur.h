#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Joueur
{
public:
	Joueur(sf::Texture* texture, sf::Vector2u nbImages, float tpsSwitch, float vitesse);
	~Joueur();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

public: 
	sf::RectangleShape corps;
	Animation animation;
	unsigned int colonne;
	float vitesse;
	bool droite;
};

