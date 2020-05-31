#include "MartienDynamique.h"
#include <iostream>

MartienDynamique::MartienDynamique(int type, int valeur):Martien(type,valeur)
{
	this->resetExtraTerrestre();
}

TableauLaserExtra& MartienDynamique::getTableauTabLaser()
{
	return this->tabLasers;
}

void MartienDynamique::removeExtraTerrestre() const
/*
  Tache:effacer le martien
*/
{
	coord.gotoXY(coord.getPositionX() - 3, coord.getPositionY() - 1);
	std::cout << "      " << std::endl;
	coord.gotoXY(coord.getPositionX() - 3, coord.getPositionY());
	std::cout << "       " << std::endl;
	coord.gotoXY(coord.getPositionX() - 3, coord.getPositionY() + 1);
	std::cout << "      ";
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
}

void MartienDynamique::putExtraTerrestre() const
/*
  Tache:imprimer le martien
*/
{
	coord.gotoXY(coord.getPositionX() - 3, coord.getPositionY() - 1);
	std::cout << " _( )_" << std::endl;
	coord.gotoXY(coord.getPositionX() - 3, coord.getPositionY());
	std::cout << "[ ]M[ ]" << std::endl;
	coord.gotoXY(coord.getPositionX() - 3, coord.getPositionY() + 1);
	std::cout << "  \ / ";
}

int MartienDynamique::getPointeDeVie() const
{
	return this->valeurExtraTerrestre;
}

void MartienDynamique::reduirePointDevie()
{
	this->valeurExtraTerrestre -= 3;
}

void MartienDynamique::tirerLaser()
/*
  Tache: tire le laser
*/
{
	int intervalleTir = rand() % 30 + 1;
	if (intervalleTir > 9 && intervalleTir < 12 && this->isAlive) {
		LaserExtra laser;
		laser.startLaser(this->coord.getPositionX(), this->coord.getPositionY() + 1);
		laser.moveLaser();
		this->tabLasers.ajouter(laser);
	}
}

void MartienDynamique::recevoirDegats(VaisseauSpacial &vaisseau)
/*
  Tache: verifier la collision entre le martien et le laser du vaisseau pour lui appliquer des dégats
  parametres: le vaisseau
*/
{
	for (int i = 0; i < vaisseau.getTableauDynamique().getNbLasers(); i++) {
		if ((((vaisseau.getTableauDynamique().getLasers()) + i)->coord.getPositionX() >= this->coord.getPositionX() - 3
			&& ((vaisseau.getTableauDynamique().getLasers()) + i)->coord.getPositionX() <= this->coord.getPositionX() + 3
			&& ((vaisseau.getTableauDynamique().getLasers()) + i)->coord.getPositionY() == this->coord.getPositionY())
			|| (((vaisseau.getTableauDynamique().getLasers()) + i)->coord.getPositionY() - 2 == this->coord.getPositionY()
				&& ((vaisseau.getTableauDynamique().getLasers()) + i)->coord.getPositionX() == this->coord.getPositionX()))
		{
			this->reduirePointDevie();
			((vaisseau.getTableauDynamique().getLasers()) + i)->killLaser();
			(vaisseau.getTableauDynamique()).retirer();
			if (this->valeurExtraTerrestre == 0) {
				for (int j = 0; j < this->tabLasers.getNbLasers(); j++)
				{
					(this->tabLasers.getLasers() + j)->killLaser();
					this->tabLasers.retirer();
				}
			}
		}
	}
}

void MartienDynamique::faireDegats(VaisseauSpacial &vaisseau)
/*
  Tache: verifier la collision entre le laser du martien et le vaisseau pour lui appliquer des dégats
  parametres: le vaisseau
*/
{
	for (int i = 0; i < this->tabLasers.getNbLasers(); i++) {
		if (((this->tabLasers.getLasers() + i)->coord.getPositionX() >= vaisseau.coord.getPositionX() - 3
			&& ((this->tabLasers.getLasers()) + i)->coord.getPositionX() <= vaisseau.coord.getPositionX() + 3
			&& ((this->tabLasers.getLasers()) + i)->coord.getPositionY() == vaisseau.coord.getPositionY()))
		{
			vaisseau.setValeurVaisseau(vaisseau.getValeurVaisseau() - 1);
			((this->tabLasers.getLasers()) + i)->killLaser();
			this->tabLasers.retirer();
		}
		else if ((((this->tabLasers.getLasers() + i)->coord.getPositionX() < vaisseau.coord.getPositionX() - 3
			|| ((this->tabLasers.getLasers()) + i)->coord.getPositionX() > vaisseau.coord.getPositionX() + 3)
			&& ((this->tabLasers.getLasers()) + i)->coord.getPositionY() == vaisseau.coord.getPositionY())) {
			((this->tabLasers.getLasers()) + i)->killLaser();
			this->tabLasers.retirer();
		}

	}
}

void MartienDynamique::resetExtraTerrestre()
/*
  Tache: trouver aléatoirement la position du martien
*/
{
	coord.setPositionX(rand() % 61 + 5);
	coord.setPositionY(rand() % 31 + 2);
	isAlive = true;
	nombreExtraTerrestre++;
}
