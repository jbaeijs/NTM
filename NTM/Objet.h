#pragma once

#include <iostream>
using namespace std;
/*
Un objet est TOUJOURS d�fini par :
 - son nom
 - son type
 - son prix
 - son poids (en kilos)
*/

class Objet
{
public:
	Objet(string nom, string type, unsigned int prix, float poids);
	~Objet();

	string getnom();
	string gettype();
	unsigned int getprix();
	float getpoids();

	void setnom(string nom);
	void settype(string type);
	void setprix(unsigned int prix);
	void setpoids(float poids);

private:

	//Variables
public:

protected:
	string nom;
	string type;
	unsigned int prix;
	float poids;
};

class Arme :public Objet
{
	/*
	Une arme est, en plus, d�finie par :
	 - son niveau, qui d�pend de ce qu'elle est (une dague est de niveau moindre qu'un marteau), et de ses attributs (en mithril, cass�...)
	 - son attribut (en mithril, cass�...)
	 - ses d�g�ts (qui d�pendent aussi de son nom et ses attributs) sous forme de tableau :
			ex  : [1,3] signifie qu'on lance 1d3, [4,6] signifie qu'on lance 4d6...
	 - ses attributs sp�ciaux (utilisation de pouvoirs magiques tels que enflamm�, maudit...)

	*/
public:
	Arme(string nom, string type, unsigned int prix, float poids, unsigned int niveau, string attribut, string special, unsigned int degats[2]) :Objet(nom, type, prix, poids) {};
	~Arme();

	unsigned int getniveau();
	string getattribut();
	string getspecial();
	unsigned int getdegats();

	void setniveau(unsigned int niveau);
	void setattribut(string attribut);
	void setspecial(string special);
	void setdegats(unsigned int degats[2]);

private:

//Variables
public:

private:
	unsigned int niveau;
	string attribut;
	string special;
	unsigned int degats[2];
};