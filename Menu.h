#pragma once
#include "UIKit.h"
#include "mmsystem.h" 
#include <string>
#pragma comment( lib, "winmm.lib" )
#include <conio.h>
#include "Coord.h"

class Menu {
	std::string *options;		//  tableau d'options contenant celles du menu
	int maxOptions;		//  nombre maximal d'options du tableau
	int nbOptions;		//  nombre d'options actuelles dans le tableau
	int idOptionSelectione;
	Coord coord;
public:
	Menu(int x, int y);
	void addOption(std::string newOption);
	void naviguer();
	bool validerOption();
	int play();
	void afficherMenu();
	void playMenuSound();
	void playBackgroundSound();
	~Menu();
};

