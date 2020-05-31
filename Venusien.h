#pragma once
#include "ExtraTerrestre.h"
#include "LaserExtra.h"
#include "TableauLaserExtra.h"
#include "VaisseauSpacial.h"

class Venusien: public ExtraTerrestre {
	int direction;
	TableauLaserExtra tabLasers;
public:
	Venusien(int type, int valeur);
	TableauLaserExtra& getTableauTabLaser();
	void removeExtraTerrestre() const;
	void putExtraTerrestre() const;
	void deplacerVenusien();
	void genereDirection();
	int getPointeDeVie() const;
	void reduirePointDevie();
	void tirerLaser();
	//int getTypeExtraterrestre() const;
	void recevoirDegats(VaisseauSpacial &vaisseau);
	void faireDegats(VaisseauSpacial &vaisseau);
	void resetExtraTerrestre();
};