#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Arme.h"

class Joueur
{
public:
	Joueur(sf::Texture* texture, sf::Vector2u nbImages, float tpsSwitch, float vitesse, unsigned int po);
	~Joueur();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	void setpo(unsigned int po);

	unsigned int getpo();

public: 
	sf::RectangleShape corps;
	Animation animation;
	unsigned int colonne;
	float vitesse;
	bool droite;

	vector<Arme>inventaire;
	unsigned int po;
};

