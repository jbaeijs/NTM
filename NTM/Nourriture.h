#pragma once

#include "Objet.h"
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Nourriture:public Objet
{
//Fonctions
public:
	Nourriture(string nom, unsigned int prix, float poids, unsigned int nbRations, unsigned int empoisonne);
	~Nourriture();

	void setnbRations(unsigned int nbRations);
	void setempoisonne(unsigned int empoisonne);

	unsigned int getnbRations();
	unsigned int getempoisonne();

private:

//Variables
public:

private:

	unsigned int nbRations;
	unsigned int empoisonne; //la proba est de x/x+1

};

