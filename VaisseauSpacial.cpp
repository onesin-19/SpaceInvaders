#include "VaisseauSpacial.h"
#include "Venusien.h"
#include "LaserForme.h"
#include <iostream>

VaisseauSpacial::VaisseauSpacial(int valeurVaisseau):Vaisseau()
{
	this->valeurVaisseau = valeurVaisseau;
}

TableauDynamique& VaisseauSpacial::getTableauDynamique()
{
	return (this->tableauLaser);
}

void VaisseauSpacial::removeVaisseau() const
{
	for (int i = 3; i >= 0; i--)
	{
		coord.gotoXY(coord.getPositionX() + i, coord.getPositionY());
		std::cout << " ";
		coord.gotoXY(coord.getPositionX() - i, coord.getPositionY());
		std::cout << " ";

	}
	
}

void VaisseauSpacial::putVaisseau() const
{
	coord.gotoXY(coord.getPositionX()-3, coord.getPositionY());
	std::cout << "<(.l.)>";
}

void VaisseauSpacial::setDirectionVaisseau(bool directionVaisseau)
{
	this->directionVaisseau = directionVaisseau;
}

bool VaisseauSpacial::getDirectionVaisseau()
{
	return this->directionVaisseau;
}

void VaisseauSpacial::modifierPosition(bool directionVaiseau)
/*
  Tache: change en mémoire la position du vaisseaux
  parametre: la direction du vaisseau
*/
{
	removeVaisseau();
	(directionVaiseau) ? coord.setPositionX(coord.getPositionX() - 1) : coord.setPositionX(coord.getPositionX() + 1);
	putVaisseau();
}

void VaisseauSpacial::tirerLaser()
{
	LaserForme laser;
	laser.startLaser(this->coord.getPositionX());
	laser.moveLaser();
	this->tableauLaser.ajouter(laser);
}

void VaisseauSpacial::setValeurVaisseau(int valeurVaisseau)
{
	this->valeurVaisseau = valeurVaisseau;
}

int VaisseauSpacial::getValeurVaisseau()
{
	return this->valeurVaisseau;
}
