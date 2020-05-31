#pragma once
#include "UIKit.h"
#include "VaisseauSpacial.h"
#include "Laser.h"
#include "Venusien.h"
#include "MartienDynamique.h"
#include "Fichier.h"
#include "MMSystem.h" 
#pragma comment( lib, "winmm.lib" ) 
#include "Menu.h"
#include "Regles.h"


class Jeu {
	ExtraTerrestre* extraTerrestres[15];
	VaisseauSpacial vaisseau;
	int tabTypeExtraterrestre[15];
	int score;
	int tempsEcoule;
	void init(int cd, int ld, int cf, int lf, int couleur);
	void afficherStat();
public:
	Jeu();
	//~Jeu();
	void jouer(int vitesseJeu);
	void creerEnemis();
	void retireExtraterrestre(int indice);
	void loseGame();
	void winGame();
};