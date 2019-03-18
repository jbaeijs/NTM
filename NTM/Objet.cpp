#include "Objet.h"

Objet::Objet(string nom, string type, unsigned int prix, float poids)
{
	void setnom(string nom);
	void settype(string type);
	void setprix(unsigned int prix);
	void setpoids(float poids);
}


Objet::~Objet()
{
}

string Objet::getnom()
{
	return this->nom;
}

string Objet::gettype()
{
	return this->type;
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

void Objet::settype(string type)
{
	this->type = type;
}

void Objet::setprix(unsigned int prix)
{
	this->prix = prix;
}

void Objet::setpoids(float poids)
{
	this->poids = poids;
}

Arme::Arme(string nom, string type, unsigned int prix, float poids, unsigned int niveau, string attribut, string special, unsigned int degats[2]) : Objet(nom, type, prix, poids)
{
	void setniveau(unsigned int niveau);
	void setattribut(string attribut);
	void setspecial(string special);
	void setdegats(unsigned int degats);
}

Arme::~Arme()
{}

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

unsigned int Arme::getdegats()
{
	return this->degats[2];
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

void Arme::setdegats(unsigned int degats[2])
{
	this->degats[0] = degats[0];
	this->degats[1] = degats[1];
}
