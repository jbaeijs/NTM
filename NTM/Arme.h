#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Objet.h"
using namespace std;

class Arme : public Objet
{
	/*
	Une arme est, en plus, définie par :
	 - son niveau, qui dépend de ce qu'elle est (une dague est de niveau moindre qu'un marteau), et de ses attributs (en mithril, cassé...)
	 - son attribut (en mithril, cassé...)
	 - ses dégâts (qui dépendent aussi de son nom et ses attributs) sous forme de tableau :
			ex  : [1,3] signifie qu'on lance 1d3, [4,6] signifie qu'on lance 4d6...
	 - ses attributs spéciaux (utilisation de pouvoirs magiques tels que enflammé, maudit...)
	 - sa portée
	*/
public:
	Arme(string nom, unsigned int prix, float poids, unsigned int niveau, string attribut, string special, unsigned int nbDes, unsigned int valeurDes, unsigned int portee, unsigned int nbMains);
	~Arme();

	unsigned int getniveau();
	string getattribut();
	string getspecial();
	vector<unsigned int> getdegats();
	unsigned int getportee();
	unsigned int getnbMains();

	void setniveau(unsigned int niveau);
	void setattribut(string attribut);
	void setspecial(string special);
	void setdegats(unsigned int nbDes, unsigned int valeurDes);
	void setportee(unsigned int portee);
	void setnbMains(unsigned int nbMains);

private:

	//Variables
public:

private:
	unsigned int niveau;
	string attribut;
	string special;
	vector<unsigned int> degats;
	unsigned int portee;
	unsigned int nbMains;
};