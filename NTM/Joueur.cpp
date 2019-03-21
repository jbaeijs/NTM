#include "Joueur.h"

Joueur::Joueur(sf::Texture* texture, sf::Vector2u nbImages, float tpsSwitch, float vitesse, unsigned int po) :
	animation(texture, nbImages, tpsSwitch)
{
	this->vitesse = vitesse;
	colonne = 0;
	droite = true;

	corps.setSize(sf::Vector2f(75.0f, 100.0f));
	corps.setTexture(texture);
	corps.setPosition(200.0f, 200.0f);

	setpo(po);
}


Joueur::~Joueur()
{
}

void Joueur::Update(float deltaTime)
{
	sf::Vector2f mouvement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		mouvement.x += vitesse * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		mouvement.x -= vitesse * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		mouvement.y -= vitesse * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		mouvement.y += vitesse * deltaTime;

	if ((mouvement.x == 0.0f) && (mouvement.y == 0.0f)) {
		colonne = 2;
	}
	else {

		if (mouvement.y < 0.0f) {
			colonne = 0;
		}
		else if (mouvement.y > 0.0f) {
			colonne = 2;
		}
		else if (mouvement.x < 0.0f) {
			colonne = 1;
		}
		else {
			colonne = 3;
		}

	}
	animation.Update(colonne, deltaTime);
	corps.setTextureRect(animation.rect);
	corps.move(mouvement);
}

void Joueur::Draw(sf::RenderWindow& window)
{
	window.draw(corps);
}

void Joueur::setpo(unsigned int po)
{
	this->po = po;
}

unsigned int Joueur::getpo()
{
	return this->po;
}
