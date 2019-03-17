#include "Map.h"


Map::Map(float chanceVieInit, unsigned int limiteMort, unsigned int limiteNaissance, unsigned int nbSimulations)
{
	setChanceVieInit(chanceVieInit);
	setLimiteMort(limiteMort);
	setLimiteNaissance(limiteNaissance);
	setNbSimulations(nbSimulations);
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

//Initialisation map
void Map::mapInit(bool map[largeurGrille][hauteurGrille])
{
	float nbAlea;
	for (int x = 0; x < this->largeurGrille; x++) {
		for (int y = 0; y < this->hauteurGrille; y++) {
			nbAlea = float(rand() % 100);
			if ((nbAlea / 100) < this->chanceVieInit) {
				map[x][y] = true;
			}
			else {
				map[x][y] = false;
			}
		}
	}
}

int Map::nbVoisinsVivants(bool map[largeurGrille][hauteurGrille], int x, int y)
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

void Map::etapeSimulation(bool mapOld[largeurGrille][hauteurGrille], bool mapNew[largeurGrille][hauteurGrille])
{
	for (int x = 0; x < this->largeurGrille; x++) {
		for (int y = 0; y < this->hauteurGrille; y++) {
			int nbVoisins = nbVoisinsVivants(mapOld, x, y);
			if (mapOld[x][y]) {
				if (nbVoisins < limiteMort) {
					mapNew[x][y] = false;
				}
				else {
					mapNew[x][y] = true;
				}
			}
			else {
				if (nbVoisins > limiteNaissance) {
					mapNew[x][y] = true;
				}
				else {
					mapNew[x][y] = false;
				}
			}
		}
	}
}

void Map::genererMap(bool map[largeurGrille][hauteurGrille])
{
	mapInit(map);
	bool mapNew[this->largeurGrille][this->hauteurGrille] = { {false} };
	for (int i = 0; i < nbSimulations; i++) {
		etapeSimulation(map, mapNew);
		for (int x = 0; x < this->largeurGrille; x++) {
			for (int y = 0; y < this->hauteurGrille; y++) {
				map[x][y] = mapNew[x][y];
			}
		}
	}
}
