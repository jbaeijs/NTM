#include "Objet.h"

Objet::Objet(string nom, unsigned int prix, float poids)
{
	setnom(nom);
	setprix(prix);
	setpoids(poids);
}

Objet::~Objet()
{
}

string Objet::getnom()
{
	return this->nom;
}

unsigned int Objet::getprix()
{
	return this->prix;
}

float Objet::getpoids()
{
	return this->poids;
}

void Objet::setnom(string nom)
{
	this->nom = nom;
}

void Objet::setprix(unsigned int prix)
{
	this->prix = prix;
}

void Objet::setpoids(float poids)
{
	this->poids = poids;
}
