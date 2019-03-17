#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
// Fonctions
public:
	Animation(sf::Texture* texture, sf::Vector2u nbImages, float tpsSwitch);
	~Animation();

	void Update(int colonne, float deltaTime);

private:

// Variables
public:
	sf::IntRect rect;

private:
	sf::Vector2u nbImages;
	sf::Vector2u imageCourante;

	float tpsTotal;
	float tpsSwitch;
};

