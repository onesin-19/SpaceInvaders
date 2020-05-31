#include "Jeu.h"
#include <conio.h>
#include <time.h>

Jeu::Jeu() :vaisseau(7)
{
	this->score = 0;
}

/*Jeu::~Jeu()
{
	delete extraTerrestres;
}*/

void Jeu::init(int cd, int ld, int cf, int lf, int couleur)
{
	UIKit::cadre(cd + 71, ld, cf + 48, lf, couleur);
	UIKit::cadre(cd, ld, cf, lf, couleur);

}

void Jeu::afficherStat()
{
	UIKit::color(13);
	UIKit::gotoXY(72, 3);
	std::cout << "SCORE: " << this->score;
	UIKit::color(10);
	UIKit::gotoXY(72, 6);
	std::cout << "Point de vie restant: " << this->vaisseau.getValeurVaisseau() << "/7";
	UIKit::color(6);
	UIKit::gotoXY(72, 9);
	std::cout << "APPUYER SUR P pour faire une pause";
	UIKit::color(1);
	UIKit::gotoXY(72, 12);
	std::cout << "APPUYER SUR Q pour quitter la partie";
	UIKit::color(3);
	UIKit::gotoXY(72, 15);
	std::cout << "APPUYER SUR K pour gauche et L pour droite";
	UIKit::color(14);
	UIKit::gotoXY(72, 18);
	std::cout << "temps ecoule " << this->tempsEcoule;
	UIKit::color(7);
	UIKit::gotoXY(72, 21);
	std::cout << "nombre extraterrestres " << ExtraTerrestre::getNombreExtraTerrestre() << " ";
	UIKit::color(30);
	UIKit::gotoXY(72, 24);
	Fichier fichier;
	std::string contenu[10];
	fichier.lire("score.txt", contenu);
	std::cout << "anciens scores ";
	int k = (Fichier::getNbLigne() < 10 ? Fichier::getNbLigne() : 10);
	for (int i = 0; i < k; i++)
	{
		if (i > 5) {
			UIKit::gotoXY(72, 25);
			std::cout << contenu[i]<<"  ";
		}
		else {
			std::cout << contenu[i]<<"  ";
		}
	}


	UIKit::color(15);
}

void Jeu::jouer(int vitesseJeu)
/*
  Tache: lance le jeu 
  parametres: le temps d'attente de d'affichage des ennmis
*/
{
	srand(time(0));
	init(0, 0, 70, 41, 11);
	UIKit::color(15);
	unsigned long long temps = time(0);
	bool tps = false;
	int c = 0;
	int nombreEnnemiTue = 0;
	Fichier fichier;
	int touche;
	do {
		//trouver la touche presser
		touche = -1;
		if (_kbhit()) {
			touche = _getch();
		}
		tempsEcoule = time(0) - temps;
		//si la touche est k le vaisseau va à gaucher 
		if (tolower(char(touche)) == 'k' || this->vaisseau.coord.getPositionX() == 65) {
			this->vaisseau.setDirectionVaisseau(true);
		}
		else if (tolower(char(touche)) == 'l' || vaisseau.coord.getPositionX() == 4) { //si la touche est l il va à droite
			this->vaisseau.setDirectionVaisseau(false);
		}
		else if (touche == 32) { // si la touche c'est espace le laser est tiré
			PlaySound("laser.wav", GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC);
			this->vaisseau.tirerLaser();
		}
		else if (tolower(char(touche)) == 'p') {
			do {
				touche = _getch();

			} while (tolower(char(touche)) != 'p');

		}
		if (tps) {
			this->vaisseau.modifierPosition(vaisseau.getDirectionVaisseau());
		}
		//un ennemi est creé après chaque vitesseJeu secondes jusqu'au ce qu'il y ait 15 ennemis.
		if (ExtraTerrestre::getNombreExtraTerrestre() < 15) {
			if (tempsEcoule >= (ExtraTerrestre::getNombreExtraTerrestre() + nombreEnnemiTue) * vitesseJeu) {
				this->creerEnemis();
			}
		}
		//chaque extraterrestre se déplace et tire selon s'il est venusien ou martien 
		if (c == 5)
		{
			for (int i = 0; i < ExtraTerrestre::getNombreExtraTerrestre(); i++) {
				if (tabTypeExtraterrestre[i] == 0) {
					((Venusien*)extraTerrestres[i])->deplacerVenusien();
					((Venusien*)extraTerrestres[i])->tirerLaser();
				}
				else {
					((MartienDynamique*)extraTerrestres[i])->jiggleMartien();
					((MartienDynamique*)extraTerrestres[i])->tirerLaser();
				}
			}
			c = 0;
		}
		c++;
		for (int i = 0; i < ExtraTerrestre::getNombreExtraTerrestre(); i++) {
			//chaque laser se déplce et peut faire un dégat
			if (tabTypeExtraterrestre[i] == 0) {
				for (int j = 0; j < ((Venusien*)extraTerrestres[i])->getTableauTabLaser().getNbLasers(); j++)
				{
					(*(((Venusien*)extraTerrestres[i])->getTableauTabLaser().getLasers() + j)).moveLaser();
				}
				((Venusien*)extraTerrestres[i])->faireDegats(this->vaisseau);
				((Venusien*)extraTerrestres[i])->recevoirDegats(this->vaisseau);
				if (((Venusien*)extraTerrestres[i])->getPointeDeVie() == 0) {
					((Venusien*)extraTerrestres[i])->removeExtraTerrestre();
					((Venusien*)extraTerrestres[i])->isAlive = false;
					this->retireExtraterrestre(i);
					this->score += 9;
					nombreEnnemiTue++;
				}
			}
			else {
				for (int j = 0; j < ((MartienDynamique*)extraTerrestres[i])->getTableauTabLaser().getNbLasers(); j++)
				{
					(*(((MartienDynamique*)extraTerrestres[i])->getTableauTabLaser().getLasers() + j)).moveLaser();
				}
				((MartienDynamique*)extraTerrestres[i])->faireDegats(this->vaisseau);
				((MartienDynamique*)extraTerrestres[i])->recevoirDegats(this->vaisseau);
				if (((MartienDynamique*)extraTerrestres[i])->getPointeDeVie() == 0) {
					((MartienDynamique*)extraTerrestres[i])->removeExtraTerrestre();
					((MartienDynamique*)extraTerrestres[i])->isAlive = false;
					this->retireExtraterrestre(i);
					this->score += 12;
					nombreEnnemiTue++;
				}
			}
		}
		//les lasers du vaisseau se déplacent
		this->vaisseau.getTableauDynamique().retirer();
		for (int i = 0; i < this->vaisseau.getTableauDynamique().getNbLasers(); i++)
		{
			(*(this->vaisseau.getTableauDynamique().getLasers() + i)).moveLaser();
		}
		this->afficherStat();
		tps = !tps;
		Sleep(20);
	} while (this->vaisseau.getValeurVaisseau() > 0 && (ExtraTerrestre::getNombreExtraTerrestre() < 15 && ExtraTerrestre::getNombreExtraTerrestre() > 0)&& tolower(char(touche))!='q');
	
	UIKit::gotoXY(0, 15);
	if (tolower(char(touche)) != 'q') {
		if (ExtraTerrestre::getNombreExtraTerrestre() == 0) {
			this->winGame();
		}
		else {
			this->loseGame();
		}
		fichier.ecrire("score.txt", score);
		fichier.ecrireParRemplacement("nombreScore.txt", Fichier::getNbLigne());
	}
	
}
void Jeu::creerEnemis()
/*
  Tache: creer un nouvel ennemi
*/
{
	int val = rand() % 2;
	tabTypeExtraterrestre[ExtraTerrestre::getNombreExtraTerrestre()] = val;
	if (val == 0) {
		this->extraTerrestres[ExtraTerrestre::getNombreExtraTerrestre() - 1] = new Venusien(15, 9);
	}
	else {
		this->extraTerrestres[ExtraTerrestre::getNombreExtraTerrestre() - 1] = new MartienDynamique(20, 12);
	}
}

void Jeu::retireExtraterrestre(int indice)
{
	for (int i = 0; i < ExtraTerrestre::getNombreExtraTerrestre(); i++)
	{
		if (i == indice) {
			for (int j = i; j < ExtraTerrestre::getNombreExtraTerrestre() - 1; j++)
			{
				this->extraTerrestres[j] = this->extraTerrestres[j + 1];
				this->tabTypeExtraterrestre[j] = this->tabTypeExtraterrestre[j + 1];
			}
		}

	}
	ExtraTerrestre::reduireNombreExtraTerrestre();
}

void Jeu::loseGame()
/*
  Tache: en cas de perte du jeu
*/
{
	UIKit::color(396);
	PlaySound("lose.wav", GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC);
	std::cout << "____     ___                      ___                             " << std::endl;
	std::cout << "`MM(     )M'                      `MM                             " << std::endl;
	std::cout << " `MM.    d'                        MM                             " << std::endl;
	std::cout << "  `MM.  d' _____  ___   ___        MM   _____     ____     ____   " << std::endl;
	std::cout << "   `MM d' 6MMMMMb `MM    MM        MM  6MMMMMb   6MMMMb\  6MMMMb  " << std::endl;
	std::cout << "    `MM' 6M'   `Mb MM    MM        MM 6M'   `Mb MM'    ` 6M'  `Mb " << std::endl;
	std::cout << "     MM  MM     MM MM    MM        MM MM     MM YM.      MM    MM " << std::endl;
	std::cout << "     MM  MM     MM MM    MM        MM MM     MM  YMMMMb  MMMMMMMM " << std::endl;
	std::cout << "     MM  MM     MM MM    MM        MM MM     MM      `Mb MM       " << std::endl;
	std::cout << "     MM  YM.   ,M9 YM.   MM        MM YM.   ,M9 L    ,MM YM    d9 " << std::endl;
	std::cout << "    _MM_  YMMMMM9   YMMM9MM_      _MM_ YMMMMM9  MYMMMM9   YMMMM9  " << std::endl << std::endl << std::endl;
	UIKit::color(15);
}

void Jeu::winGame()
/*
  Tache: en cas de victoire du jeu
*/
{
	UIKit::color(10);
	PlaySound("win.wav", GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC);
	std::cout << "oooooo   oooo                            oooooo   oooooo     oooo  o8o              " << std::endl;
	std::cout << " `888.   .8'                              `888.    `888.     .8'                    " << std::endl;
	std::cout << "  `888. .8'    .ooooo.  oooo  oooo         `888.   .8888.   .8'   oooo  ooo. .oo.   " << std::endl;
	std::cout << "   `888.8'    d88' `88b `888  `888          `888  .8'`888. .8'    `888  `888P'Y88b  " << std::endl;
	std::cout << "    `888'     888   888  888   888           `888.8'  `888.8'      888   888   888  " << std::endl;
	std::cout << "     888      888   888  888   888            `888'    `888'       888   888   888  " << std::endl;
	std::cout << "    o888o     `Y8bod8P'  `V88V'V8P'            `8'      `8'       o888o o888o o888o " << std::endl << std::endl << std::endl;
	UIKit::color(15);
}

