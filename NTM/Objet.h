#pragma once

#include <iostream>
using namespace std;
/*
Un objet est TOUJOURS défini par :
 - son nom
 - son prix
 - son poids (en kilos)
*/

class Objet
{
public:
	Objet(string nom, unsigned int prix, float poids);
	~Objet();

	string getnom();
	unsigned int getprix();
	float getpoids();

	void setnom(string nom);
	void setprix(unsigned int prix);
	void setpoids(float poids);

private:

	//Variables
protected:

	string nom;
	unsigned int prix;
	float poids;
};
