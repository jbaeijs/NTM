#include "Joueur.h"
#include <windows.h>

using namespace std;

Joueur::Joueur(Map &grille, unsigned int lPix, unsigned int hPix)
{
	this->corps.setSize(sf::Vector2f(lPix, hPix));
	this->corps.setFillColor(sf::Color::Magenta);
	this->corps.setPosition((20 * grille.getPosJoueurY()) + hPix, (20 * grille.getPosJoueurX()) + lPix);
	this->tpsTotal = 0.0f;
	this->tpsSwitch = 0.20;
}

Joueur::~Joueur()
{
}


/* TODO : Revoir*/
void Joueur::Update(Map &grille, float deltaTime)
{
	this->corps.setPosition((20 * grille.getPosJoueurY()) + 10, (20 * grille.getPosJoueurX()) + 10);
	tpsTotal += deltaTime;

	int map[grille.largeurGrille][grille.hauteurGrille] = { {0} };
	grille.getMap(map);

	float posX = grille.getPosJoueurX();
	float posY = grille.getPosJoueurY();

	if (tpsTotal >= tpsSwitch) {
		tpsTotal -= tpsSwitch;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (map[int(posX) - 1][int(posY)] != 1) {
				corps.move(0, -20);
				grille.setPosJoueurX(grille.getPosJoueurX() - 1);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if (map[int(posX) + 1][int(posY)] != 1) {
				corps.move(0, 20);
				grille.setPosJoueurX(grille.getPosJoueurX() + 1);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			if (map[int(posX)][int(posY) - 1] != 1) {
				corps.move(-20, 0);
				grille.setPosJoueurY(grille.getPosJoueurY() - 1);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			if (map[int(posX)][int(posY) + 1] != 1) {
				corps.move(20, 0);
				grille.setPosJoueurY(grille.getPosJoueurY() + 1);
			}
		}
	}
}

void Joueur::Draw(sf::RenderWindow & window)
{
	window.draw(corps);
}


