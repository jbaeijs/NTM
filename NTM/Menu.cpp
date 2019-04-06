#include "Menu.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Menu::Menu(float largeur, float hauteur)
{

}


Menu::~Menu()
{
}

int Menu::Update(sf::RenderWindow &window)
{
	sf::Vector2i posSouris = sf::Mouse::getPosition(window);
	sf::Vector2f posSourisF(static_cast<float>(posSouris.x), static_cast<float>(posSouris.y));

	cout << posSourisF.x << " " << posSourisF.y << endl;

	return 0;
}

void Menu::Draw(sf::RenderWindow & window)
{

}
