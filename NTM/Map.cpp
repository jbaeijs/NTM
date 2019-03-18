#include "Map.h"
#include <stdlib.h>
#include <SFML/Window.hpp>

Map::Map(float chanceVieInit, unsigned int limiteMort, unsigned int limiteNaissance, unsigned int nbSimulations, unsigned int tailleMin)
{
	setChanceVieInit(chanceVieInit);
	setLimiteMort(limiteMort);
	setLimiteNaissance(limiteNaissance);
	setNbSimulations(nbSimulations);
	this->tailleMin = tailleMin;
}

Map::~Map()
{
}

// Guetters
float Map::getChanceVieInit()
{
	return this->chanceVieInit;
}

unsigned int const Map::getLargeurGrille()
{
	return this->largeurGrille;
}

unsigned int const Map::getHauteurGrille()
{
	return this->hauteurGrille;
}

unsigned int Map::getLimiteMort()
{
	return this->limiteMort;
}

unsigned int Map::getLimiteNaissance()
{
	return this->limiteNaissance;
}

unsigned int Map::getNbSimulations()
{
	return this->nbSimulations;
}

void Map::getMap(int map[largeurGrille][hauteurGrille])
{
	for (int x = 0; x < largeurGrille; x++) {
		for (int y = 0; y < hauteurGrille; y++) {
			map[x][y] = this->map[x][y];
		}
	}
}

//Setters
void Map::setChanceVieInit(float chanceVieInit)
{
	this->chanceVieInit = chanceVieInit;
}

void Map::setLimiteMort(unsigned int limiteMort)
{
	this->limiteMort = limiteMort;
}

void Map::setLimiteNaissance(unsigned int limiteNaissance)
{
	this->limiteNaissance = limiteNaissance;
}

void Map::setNbSimulations(unsigned int nbSimulations)
{
	this->nbSimulations = nbSimulations;
}

/*
Initialisation  de la map
*/
void Map::mapInit()
{
	float nbAlea;
	for (int x = 0; x < this->largeurGrille; x++) {
		for (int y = 0; y < this->hauteurGrille; y++) {
			nbAlea = float(rand() % 100);
			if ((nbAlea / 100) < this->chanceVieInit) {
				map[x][y] = 1;
			}
			else {
				map[x][y] = 0;
			}
		}
	}
}

/*
Calcul du nombre de voisins vivants de la celulle à la position x et y de la map[][]
*/
int Map::nbVoisinsVivants(int x, int y)
{
	int nb = 0;
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			int voisin_x = x + i;
			int voisin_y = y + j;

			if (i == 0 && j == 0) {}
			else if (voisin_x < 0 || voisin_y < 0 || voisin_x >= this->largeurGrille || voisin_y >= this->hauteurGrille) {
				nb = nb + 1;
			}
			else if (map[voisin_x][voisin_y]) {
				nb = nb + 1;
			}
		}
	}
	return nb; 
}

/*
Affinage des voisins de chaque cellule
Répété nbSimulations fois
*/
void Map::etapeSimulation(int mapNew[largeurGrille][hauteurGrille])
{
	for (int x = 0; x < this->largeurGrille; x++) {
		for (int y = 0; y < this->hauteurGrille; y++) {
			int nbVoisins = nbVoisinsVivants(x, y);
			if (map[x][y]) {
				if (nbVoisins < limiteMort) {
					mapNew[x][y] = 0;
				}
				else {
					mapNew[x][y] = 1;
				}
			}
			else {
				if (nbVoisins > limiteNaissance) {
					mapNew[x][y] = 1;
				}
				else {
					mapNew[x][y] = 0;
				}
			}
		}
	}
}

/*
Flood fill à partir de la première celulle vivante
*/
void Map::floodFill(int x, int y)
{
	if (map[x][y] == 0) {
		map[x][y] = 2;

		floodFill(x + 1, y);
		floodFill(x - 1, y);
		floodFill(x, y + 1);
		floodFill(x, y - 1);
	}
}

/*
Vérification de la taille de la map après le flood fill
Map générée à nouveau si pas assez grande
*/
void Map::verifMap()
{
	int nb = 0;
	for (int x = 0; x < largeurGrille; x++) {
		for (int y = 0; y < hauteurGrille; y++) {
			if (map[x][y] == 2) {
				nb ++;
			}
		}
	}
	if (nb < tailleMin) {
		for (int x = 0; x < largeurGrille; x++) {
			for (int y = 0; y < hauteurGrille; y++) {
				map[x][y] = 0;
			}
		}
		genererMap();
	}
	else {
		for (int x = 0; x < largeurGrille; x++) {
			for (int y = 0; y < hauteurGrille; y++) {
				if (map[x][y] == 0) {
					map[x][y] = 1;
				}
			}
		}
	}
}

void Map::placementPorte()
{
	for (int x = 0; x < largeurGrille; x++) {
		for (int y = 0; y < hauteurGrille; y++) {
			if (map[x][y] == 2) {
				if (((map[x - 1][y] == 2) && (map[x + 1][y] == 2)) && (map[x][y - 1] == 1) && (map[x][y + 1] == 1)) {
					if (((map[x - 2][y] != 3) && (map[x + 2][y] != 3)) && (map[x][y - 1] == 1) && (map[x][y + 1] == 1)) {
						map[x][y] = 3;
					}
				}
				else if (((map[x - 1][y] == 1) && (map[x + 1][y] == 1)) && (map[x][y - 1] == 2) && (map[x][y + 1] == 2)) {
					if (((map[x - 1][y] != 3) && (map[x + 1][y] != 3)) && (map[x][y - 2] == 3) && (map[x][y + 2] == 3)) {
						map[x][y] = 3;
					}
				}
			}
		}
	}
}

void Map::placementTresor()
{
	srand(time(NULL));
	unsigned int nbTresorsMaxExt = 10;
	unsigned int nbTresorCourExt = 0;
	unsigned int nbTresorsMaxInt = 5;
	unsigned int nbTresorsCourInt = 0;

	for (int x = 0; x < largeurGrille; x += 2) {
		for (int y = 0; y < hauteurGrille; y += 2) {
			float alea = float(rand() % 100);
			alea = alea / 100;
			if ((map[x - 1][y] == 2) && (map[x + 1][y] == 1) && (map[x][y - 1] == 1) && (map[x][y + 1] == 1)) {
				cout << alea << endl;
				if ((alea < 0.1) && (nbTresorCourExt < nbTresorsMaxExt)) {
					map[x][y] = 4;
					nbTresorCourExt++;
				}
			}
			else if ((map[x - 1][y] == 1) && (map[x + 1][y] == 2) && (map[x][y - 1] == 1) && (map[x][y + 1] == 1)) {
				if ((alea < 0.1) && (nbTresorCourExt < nbTresorsMaxExt)) {
					cout << alea << endl;
					map[x][y] = 4;
					nbTresorCourExt++;
				}
			} 
			else if ((map[x - 1][y] == 1) && (map[x + 1][y] == 1) && (map[x][y - 1] == 2) && (map[x][y + 1] == 1)) {
				if ((alea < 0.1) && (nbTresorCourExt < nbTresorsMaxExt)) {
					cout << alea / 100 << endl;
					map[x][y] = 4;
				}
			}
			else if ((map[x - 1][y] == 1) && (map[x + 1][y] == 1) && (map[x][y - 1] == 1) && (map[x][y + 1] == 2)) {
				if ((alea < 0.1) && (nbTresorCourExt < nbTresorsMaxExt)) {
					cout << alea / 100 << endl;
					map[x][y] = 4;
					nbTresorCourExt++;
				}
			}
			else {
				if ((alea <= 0.01) && (nbTresorsCourInt < nbTresorsMaxInt) && (map[x][y] == 2)) {
					map[x][y] = 4;
					nbTresorsCourInt++;
				}
			}
		}
	}
}



/*
Appelé dans main.cpp
Appel des autres fonctions de générations et de vérifications
*/
void Map::genererMap()
{
	mapInit();
	int mapNew[this->largeurGrille][this->hauteurGrille] = { {false} };
	for (int i = 0; i < nbSimulations; i++) {
		etapeSimulation(mapNew);
		for (int x = 0; x < this->largeurGrille; x++) {
			for (int y = 0; y < this->hauteurGrille; y++) {
				map[x][y] = mapNew[x][y];
			}
		}
	}
	int x = 0;
	int y = 0;
	while (map[x][y] != 0) {
		x++;
		y++;
	}
	floodFill(x, y);
	verifMap();
	placementPorte();
	placementTresor();
}
