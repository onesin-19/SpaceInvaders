#pragma once
#include "Martien.h"
#include "LaserExtra.h"
#include "TableauLaserExtra.h"
#include "VaisseauSpacial.h"

class MartienDynamique: public Martien
{
	TableauLaserExtra tabLasers;
public:
	MartienDynamique(int,int);
	TableauLaserExtra& getTableauTabLaser();
	void removeExtraTerrestre() const;
	void putExtraTerrestre() const;
	int getPointeDeVie() const;
	void reduirePointDevie();
	void tirerLaser();
	//int getTypeExtraterrestre() const;
	void recevoirDegats(VaisseauSpacial &vaisseau);
	void faireDegats(VaisseauSpacial &vaisseau);
	void resetExtraTerrestre();
	
};

