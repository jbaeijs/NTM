#pragma once
#include <stdlib.h>

class Map
{
// Fonctions
public:
	Map(float chanceVieInit, unsigned int limiteMort, unsigned int limiteNaissance, unsigned int nbSimulations);
	~Map();

	// Getters
	float getChanceVieInit();
	unsigned int const getLargeurGrille();
	unsigned int const getHauteurGrille();
	unsigned int getLimiteMort();
	unsigned int getLimiteNaissance();
	unsigned int getNbSimulations();

	// Setters
	void setChanceVieInit(float chanceVieInit);
	void setLimiteMort(unsigned int limiteMort);
	void setLimiteNaissance(unsigned int limiteNaissance);
	void setNbSimulations(unsigned int nbSimulations);

	unsigned int const static largeurGrille = 50;
	unsigned int const static hauteurGrille = 50;

	void mapInit(int map[largeurGrille][hauteurGrille]);
	int nbVoisinsVivants(int map[largeurGrille][hauteurGrille], int x, int y);
	void etapeSimulation(int mapOld[largeurGrille][hauteurGrille], int mapNew[largeurGrille][hauteurGrille]);
	void genererMap(int map[largeurGrille][hauteurGrille]);

private:

// Variables
public:

private:

	float chanceVieInit;

	unsigned int limiteMort;
	unsigned int limiteNaissance;

	unsigned int nbSimulations;

};

