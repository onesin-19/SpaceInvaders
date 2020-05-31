#pragma once
#include <fstream>
#include <string>

class Fichier {
	std::ifstream f_in;
	std::ofstream f_out;
	static int nbLigne;
public:
	Fichier();
	void lire(std::string chemin, std::string contenuFichier[]);
	void lire(std::string chemin, int &valeur);
	void ecrire(std::string chemin, int valeur);
	void ecrireParRemplacement(std::string chemin, int valeur);
	static int getNbLigne();

};