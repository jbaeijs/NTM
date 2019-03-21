#include "Nourriture.h"



Nourriture::Nourriture(string nom, unsigned int prix, float poids, unsigned int nbRations, unsigned int empoisonne)
	: Objet(nom, prix, poids)
{
	setnbRations(nbRations);
	setempoisonne(empoisonne);
}


Nourriture::~Nourriture()
{
}

void Nourriture::setnbRations(unsigned int nbRations)
{
	this->nbRations = nbRations;
}

void Nourriture::setempoisonne(unsigned int empoisonne)
{
	this->empoisonne = empoisonne;
}

unsigned int Nourriture::getnbRations()
{
	return this->nbRations;
}

unsigned int Nourriture::getempoisonne()
{
	return this->nbRations;
}
