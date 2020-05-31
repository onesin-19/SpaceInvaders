#pragma once
#include "LaserForme.h"

class TableauDynamique {
	unsigned int nbMax;
	unsigned int nbLasers;
	LaserForme* lasers;
public:
	TableauDynamique();
	unsigned int getNbLasers() const;
	void setNbLasers(unsigned int nbLasers);
	LaserForme* getLasers()const;
	void ajouter(LaserForme Laser);
	void retirer();
};
