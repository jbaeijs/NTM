#include "Arme.h"

Arme::Arme(string nom, unsigned int prix, float poids, unsigned int niveau, string attribut, string special, unsigned int nbDes, unsigned int valeurDes, unsigned int portee, unsigned int nbMains)
	: Objet(nom, prix, poids)
{
	setniveau(niveau);
	setattribut(attribut);
	setspecial(special);
	setdegats(nbDes, valeurDes);
	setportee(portee);
	setnbMains(nbMains);
}

Arme::~Arme()
{
}

unsigned int Arme::getniveau()
{
	return this->niveau;
}

string Arme::getattribut()
{
	return this->attribut;
}

string Arme::getspecial()
{
	return this->special;
}

vector<unsigned int> Arme::getdegats()
{
	return this->degats;
}

unsigned int Arme::getportee()
{
	return this->portee;
}

unsigned int Arme::getnbMains()
{
	return this->nbMains;
}

void Arme::setniveau(unsigned int niveau)
{
	this->niveau = niveau;
}

void Arme::setattribut(string attribut)
{
	this->attribut = attribut;
}

void Arme::setspecial(string special)
{
	this->special = special;
}

void Arme::setdegats(unsigned int nbDes, unsigned int valeurDes)
{
	this->degats.push_back(nbDes);
	this->degats.push_back(valeurDes);
}

void Arme::setportee(unsigned int portee)
{
	this->portee = portee;
}

void Arme::setnbMains(unsigned int nbMains)
{
	this->nbMains = nbMains;
}