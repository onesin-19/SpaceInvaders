#pragma once
#include "Vaisseau.h"
#include "TableauDynamique.h"
#include "ExtraTerrestre.h"

class VaisseauSpacial: public Vaisseau {
	int valeurVaisseau;
	bool directionVaisseau;
	TableauDynamique tableauLaser;
public:
	VaisseauSpacial(int valeurVaisseau);
	TableauDynamique& getTableauDynamique();
	void removeVaisseau() const;
	void putVaisseau()const;
	void setDirectionVaisseau(bool directionVaisseau);
	bool getDirectionVaisseau();
	void modifierPosition(bool directionVaisseau);
	void tirerLaser();
	void setValeurVaisseau(int valeurVaisseau);
	int getValeurVaisseau();
	//void recevoireDegats(ExtraTerrestre* cible[], int pointsVie);
};