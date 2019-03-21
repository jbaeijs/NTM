#pragma once

#include "Objet.h"
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Livre:public Objet
{
public:
	Livre(string nom, unsigned int prix, float poids, string langue, string contenu, string entreeCodex);
	~Livre();

	void setlangue(string langue);
	void setcontenu(string contenu);
	void setentreeCodex(string entreeCodex);

	string getlangue();
	string getcontenu();
	string getentreeCodex();

private:

//Variables
public:

private:

	string langue;
	string contenu;
	string entreeCodex;
};

