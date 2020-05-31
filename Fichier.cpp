#include "Fichier.h"
#include <iostream>

int Fichier::nbLigne = 0;
Fichier::Fichier()
{
	this->lire("nombreScore.txt", nbLigne);
}

void Fichier::lire(std::string chemin, std::string contenuFichier[])
/*
  Tache:lire le contenu du fichier
  parametres: chemin du fichier à lire et le nombre de ligne à lire
*/
{
	this->f_in.open(chemin, std::ios::in);
	
	if (f_in)  
	{
		int i = 0;
		if (Fichier::nbLigne <= 10) {
			while (std::getline(f_in, contenuFichier[i])) {
				i++;
			}
		}
		else {
			this->f_in.seekg(-36, std::ios::end);
			while (std::getline(f_in, contenuFichier[i]))
			{
				i++;
			}
		}
		this->f_in.close(); 
	}
	else {
		std::cerr << "Impossible de lire le fichier !" << std::endl;
	}
}

void Fichier::lire(std::string chemin, int &valeur)
/*
  Tache:lire une valeur dans un fichier
  parametres: chemin du fichier à lire et la valeur lue
*/
{
	this->f_in.open(chemin, std::ios::in);
	if (f_in)
	{
		f_in >> valeur;
		this->f_in.close();
	}
	else {
		std::cerr << "Impossible de lire le fichier !" << std::endl;
	}
}

void Fichier::ecrire(std::string chemin, int valeur)
/*
  Tache:écrire dans le fichier
  parametres: chemin du fichier et la valeur à ecrire
*/
{
	this->f_out.open(chemin, std::ios::app);
	if (this->f_out)
	{
		if (nbLigne > 0) {
			f_out << std::endl;
		}
		f_out << valeur;
		this->nbLigne++;
		this->f_out.close();
	}
	else
		std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
}

void Fichier::ecrireParRemplacement(std::string chemin, int valeur)
/*
  Tache:écrire dans le fichier en remplaçant son ancien contenu
  parametres: chemin du fichier et la valeur à ecrire
*/
{
	this->f_out.open(chemin, std::ios::out);
	if (this->f_out)
	{
		f_out << valeur;
		this->nbLigne++;
		this->f_out.close();
	}
	else
		std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
}

int Fichier::getNbLigne()
{
	return nbLigne;
}
