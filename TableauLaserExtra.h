#pragma once
#include "LaserExtra.h"

class TableauLaserExtra {
	unsigned int nbMax;
	unsigned int nbLasers;
	LaserExtra* lasers;
public:
	TableauLaserExtra();
	//~TableauDynamique();
	unsigned int getNbLasers() const;
	void setNbLasers(unsigned int nbLasers);
	LaserExtra* getLasers()const;
	void ajouter(LaserExtra Laser);
	void retirer();
};
