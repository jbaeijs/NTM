#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Animation.h"
#include "Joueur.h"
#include "Map.h"
#include "Objet.h"
#include "Arme.h"
#include "Nourriture.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

// Largeur et Hauteur de l'écran
unsigned int const Largeur = sf::VideoMode::getDesktopMode().width;
unsigned int const Hauteur = sf::VideoMode::getDesktopMode().height;

int main() {
	srand(time(NULL));
	// Tableau des cellules
/*
	Map grille(0.40f, 4, 3, 3);

	bool map[grille.largeurGrille][grille.hauteurGrille] = { {false} };


	grille.genererMap(map);

	float lPix = sf::VideoMode::getDesktopMode().width / grille.getLargeurGrille();
	float hPix = sf::VideoMode::getDesktopMode().height / grille.getHauteurGrille();

	vector<sf::RectangleShape> vRect;

	for (int x = 0; x < grille.getLargeurGrille(); x++) {
		for (int y = 0; y < grille.getHauteurGrille(); y++) {
			if (!map[x][y]) {
				sf::RectangleShape r;
				r.setSize(sf::Vector2f(lPix, hPix));
				r.setPosition((20 * y) + hPix,(20 * x) + lPix);
				r.setFillColor(sf::Color::White);
				vRect.push_back(r);
			}
		}
	}

	//Création et position des rectangle

	// Initialisation de la fenêtre
	sf::RenderWindow window(sf::VideoMode(Largeur, Hauteur), "Deutschlandais fou", sf::Style::Fullscreen);

	// Texture et sprite du bouton quitter
	sf::Texture quitter;
	if (!quitter.loadFromFile("assets/quitter.png"))
		return EXIT_FAILURE;
	sf::Sprite sQuitter(quitter);
	sQuitter.setPosition((float)Largeur - 200, 0.0f);

	// Texture du joueur
	sf::Texture textureJoueur;
	if (!textureJoueur.loadFromFile("assets/spritesheet.png"))
		return EXIT_FAILURE;
	Joueur joueur(&textureJoueur, sf::Vector2u(9, 4), 0.1f, 150.0f);
	*/

	vector <string> nomArmes = { "dague", "épée courte","épée large", "épée longue", "épée bâtarde", "épée à deux mains",
		"arc court", "arc", "arc long", "arc composite", "arbalète", "arbalète lourde", "arbalète de siège",
		"flèche", "flèche lourde", "flèche en acier", "carreau", "carreau lourd", "lance-pierres", "marteau", "grand marteau", "grand marteau de guerre",
		"hache", "hache à deux mains", "hache de jet", "hache double", "hallebarde", "épieu", "lance", "lance de cavalerie", "faux", "bâton",
		"cimeterre", "cimeterre à deux mains", "massue", "masse d'armes" };
	vector <unsigned int> prixArmes = {2, 8, 10, 15, 25, 30, 
									   15, 40, 60, 100, 20, 45, 80,
									   1, 2, 4, 2, 3, 3, 30, 55, 75,
									   20, 35, 15, 40, 50, 20, 45, 50, 10, 7,
									   50, 65, 6, 150};
	vector <unsigned int> niveauArmes = { 1, 4, 7, 8, 16, 18,
										 6, 9, 15, 21, 14, 20, 24,
										 3, 8, 13, 9, 16, 1, 16, 18, 20,
										 14, 18, 7, 19, 22, 6, 11, 12, 5, 3,
										 12, 14, 3, 35};
	vector <float> poidsArmes = { 0.5f, 1.75f, 3.75f, 3.0f, 5.0f, 12.5f, 
								  2.25f, 2.75f, 3.5f, 5.25f, 4.25f, 5.75f, 7.0f,
								  0.1f, 0.2f, 0.5f, 0.4f, 0.8f, 0.25f, 7.25f, 8.5f, 9.75f,
								  3.25f, 5.0f, 2.5f, 6.5f, 8.5f, 3.0f, 2.5f, 4.5f, 2.25f, 2.5f,
								  2.0f, 3.0f, 2.5f, 10.0f};
	vector <vector<unsigned int>> degatsArmes = { {1,2 }, { 1,5 }, {1,8},{2,4},{2,8},{2,9},
												  {1,7},  {1,10}, {1,16}, {1,22}, {2,7}, {2,10}, {2,12},
												  {1,4}, {1,9}, {1,14}, {1,10}, {2,8}, {1,2}, {3,5}, {4,4}, {2,10},
												  {4,3}, {2,9}, {1,8}, {3,6}, {4,5}, {1,7}, {1,12}, {2,6}, {1,6}, {1,4},
												  {2,6}, {2,7}, {1,4}, {4,7} };
	vector <unsigned int> porteeArmes = { 1, 1, 1, 1, 1, 1,
										  10,10,10,10,10,10,10,
										  0,0,0,0,0,10,1,1,1,
										  1,1,10,1,2,2,2,2,2,2,
										  1,1,1,2 };
	vector <unsigned int> nbMainsArmes = { 1,1,1,1,1,2,
										   2,2,2,2,2,2,2,
										   0,0,0,0,0,2,1,2,2,
										   1,2,1,2,2,1,2,2,2,1,
										   1,1,1,1 };
	vector <string> attributArmes = { "rouillé","cassé", "ébréché", "tordu", "aiguisé", "en mithril" };
	vector <string> specialArmes = { "elfique","maudit","corrompu" };

	vector<Arme>listeArmes;
	unsigned int nbObjets = 200; //Mettre idéalement un multiple de 50, le niveau de l'arme créée est un modulo de cette variable
	int objetsDansLaListe = nomArmes.size(), tempPos, tempAttribut, tempSpecial, tempNiveau, modif, modifNiveau;
	string attributAjouter, specialAjouter;
	Arme Ajouter("",1,1.0f,1,"","",1,1,1,1);

	for (int i = 0; i < nbObjets; i++)
	{
		tempPos = rand() % objetsDansLaListe;
		tempAttribut = rand() % objetsDansLaListe;
		tempSpecial = rand() % objetsDansLaListe;
		tempNiveau = niveauArmes[tempPos];
		modif = 100;
		modifNiveau = 0;
		//pondération
		if (tempAttribut <= 4)
		{
			attributAjouter = "rouillé"; //moyenne 3
			modifNiveau -= (rand()%3)+2;
			modif -= (modifNiveau * 10);
		}
		else if (tempAttribut <= 6)
		{
			attributAjouter = "cassé"; //moyenne 7
			modifNiveau -= (rand() % 3) + 6;
			modif -= (modifNiveau * 10);
		}
		else if (tempAttribut <= 9)
		{
			attributAjouter = "ébréché"; //moyenne 6
			modifNiveau -= (rand() %3) + 5;
			modif -= (modifNiveau * 10);
		}
		else if (tempAttribut <= 13)
		{
			attributAjouter = "tordu"; //moyenne 4
			modifNiveau -= (rand() % 3) + 3;
			modif -= (modifNiveau * 10);
		}
		else if (tempAttribut <= 18)
		{
			attributAjouter = "aiguisé"; //moyenne 3
			modifNiveau += (rand() % 3) + 2;
			modif += (modifNiveau * 10);
		}
		else if (tempAttribut <= 19)
		{
			attributAjouter = "en mithril";
			modifNiveau += (rand() % 3) + 7; //moyenne 8
			modif += (modifNiveau * 10);
		}
		else
			attributAjouter = "";
			
		if (tempSpecial == 0)
		{
			specialAjouter = "elfique"; //moyenne 12
			modifNiveau += (rand() % 3) + 11;
			modif += (modifNiveau * 10);
		}
		else if (tempSpecial <= 4)
		{
			specialAjouter = "maudit"; //moyenne 5
			modifNiveau -= (rand() % 3) + 4;
			modif -= (modifNiveau * 10);
		}
		else if (tempSpecial <= 9)
		{
			specialAjouter = "corrompu";
			tempNiveau -= 10;
			modif *= 2;
		}
		else
		{
			specialAjouter = "";
			modif *= 2;
		}
		modif /= 2;
		
		tempNiveau += modifNiveau;

		if (tempNiveau > 0 && tempNiveau <= 50 && prixArmes[tempPos] * modif / 100 <= 1000 && prixArmes[tempPos] * modif / 100 > 0)
		{
			if ((i%50 > 2 &&tempNiveau >= (i%50 - 5) && tempNiveau <= (i%50 + 5)) || (i%50<=5 && tempNiveau == i%50+1))
			{
				//cout << nomArmes[tempPos] << " " << attributAjouter << " " << specialAjouter << " " << modifNiveau << endl;
				Ajouter.setnom(nomArmes[tempPos]);
				Ajouter.setattribut(attributAjouter);
				Ajouter.setdegats(degatsArmes[tempPos][0], degatsArmes[tempPos][1]);
				Ajouter.setnbMains(nbMainsArmes[tempPos]);
				Ajouter.setniveau(tempNiveau);
				Ajouter.setpoids(poidsArmes[tempPos]);
				Ajouter.setportee(porteeArmes[tempPos]);
				Ajouter.setprix(prixArmes[tempPos] * modif / 100);
				Ajouter.setspecial(specialAjouter);
				listeArmes.push_back(Ajouter);
			}
			else
				i--;
		}
		else
			i--;
	}

	for (int i = 0; i < nbObjets; i++)
		cout << listeArmes[i].getnom() << " "<<listeArmes[i].getattribut() << " " << listeArmes[i].getspecial() << "\t" <<listeArmes[i].getniveau() << endl;

	//NOURRITURE
	vector<string> nomNourritures = {"outre d'eau", "bouteille de vin", "morceau de pain", "pain rassi",
									 "viande", "liqueur orque", "fromage", "part de gâteau", "chair humaine", "rations",
									 "lembas"};
	vector<unsigned int> nbRationsNourritures = {1,1,2,1,3,1,2,2,2,1,4};
	vector<unsigned int> empoisonneNourritures = {0,0,0,1,0,1,0,0,9,0,0};
	vector<unsigned int> prixNourritures = {1,2,1,0,2,0,2,1,0,1,0};

	vector<Nourriture> listeNourritures;
	Nourriture N("", 1, 1.0f, 1, 0);
	for (int i = 0; i < nomNourritures.size(); i++)
	{
		N.setempoisonne(empoisonneNourritures[i]);
		N.setnbRations(nbRationsNourritures[i]);
		N.setnom(nomNourritures[i]);
		N.setpoids(0.25f);
		N.setprix(prixNourritures[i]);
		listeNourritures.push_back(N);
	}

	
	/*
	// Temps avant changement de sprites (animation)
	float deltaTime = 0.0f;
	sf::Clock horloge;

	while (window.isOpen()) {

		//deltaTime = horloge.restart().asSeconds();

		sf::Vector2i posSouris = sf::Mouse::getPosition(window);
		sf::Vector2f posSourisF(static_cast<float>(posSouris.x), static_cast<float>(posSouris.y));

		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::MouseMoved:
				
				if (sQuitter.getGlobalBounds().contains(posSourisF)) {
					sQuitter.setColor(sf::Color(255, 20, 20));
				}
				else {
					sQuitter.setColor(sf::Color(255, 255, 255));
				}
				break;

			case sf::Event::MouseButtonPressed:
				if (sQuitter.getGlobalBounds().contains(posSourisF)) {
					window.close();
				}
				break;
			}

		}

		window.clear();

		window.draw(sQuitter);

		for (auto j = vRect.begin(); j != vRect.end(); j++) {
			window.draw(*j);
		}

		//joueur.Update(deltaTime);
		//joueur.Draw(window);


		window.display();
	}
	*/
	return EXIT_SUCCESS;
}

