#pragma once 
#include <SFML/Graphics.hpp>

class Menu
{
public:
	Menu(float largeur, float hauteur);
	~Menu();

	int Update(sf::RenderWindow &window);
	void Draw(sf::RenderWindow &window);

private :
	int currSlectedHovered;
	int itemSelected;
	sf::RectangleShape btnJoueur;
};

