#include "Livre.h"

Livre::Livre(string nom, unsigned int prix, float poids, string langue, string contenu, string entreeCodex)
	: Objet(nom, prix, poids)
{
	setlangue(langue);
	setcontenu(contenu);
	setentreeCodex(entreeCodex);
}

Livre::~Livre()
{
}

void Livre::setlangue(string langue)
{
	this->langue = langue;
}

void Livre::setcontenu(string contenu)
{
	this->contenu = contenu;
}

void Livre::setentreeCodex(string entreeCodex)
{
	this->entreeCodex = entreeCodex;
}

string Livre::getlangue()
{
	return this->langue;
}

string Livre::getcontenu()
{
	return this->contenu;
}

string Livre::getentreeCodex()
{
	return this->entreeCodex;
}
