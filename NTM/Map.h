#pragma once
#include <stdlib.h>
#include <iostream>

using namespace std;

class Map
{
// Fonctions
public:
	Map(float chanceVieInit, unsigned int limiteMort, unsigned int limiteNaissance, unsigned int nbSimulations, unsigned int tailleMin);
	~Map();

	unsigned int const static largeurGrille = 50;
	unsigned int const static hauteurGrille = 50;

	// Getters
	float getChanceVieInit();
	unsigned int const getLargeurGrille();
	unsigned int const getHauteurGrille();
	unsigned int getLimiteMort();
	unsigned int getLimiteNaissance();
	unsigned int getNbSimulations();
	void getMap(int map[largeurGrille][hauteurGrille]);

	// Setters
	void setChanceVieInit(float chanceVieInit);
	void setLimiteMort(unsigned int limiteMort);
	void setLimiteNaissance(unsigned int limiteNaissance);
	void setNbSimulations(unsigned int nbSimulations);

	void mapInit();
	int nbVoisinsVivants(int x, int y);
	void etapeSimulation(int mapNew[largeurGrille][hauteurGrille]);
	
	void floodFill(int x, int y);

	void verifMap();

	void genererMap();

private:

// Variables
public:

private:
	int map[largeurGrille][hauteurGrille];

	float chanceVieInit;

	unsigned int limiteMort;
	unsigned int limiteNaissance;

	unsigned int nbSimulations;

	unsigned int tailleMin;
};

