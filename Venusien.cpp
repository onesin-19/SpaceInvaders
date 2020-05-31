#include "Venusien.h"
#include <iostream>

Venusien::Venusien(int type, int valeur):ExtraTerrestre(type,valeur)
{
	this->resetExtraTerrestre();
}

TableauLaserExtra& Venusien::getTableauTabLaser()
{
	return this->tabLasers;
}

void Venusien::removeExtraTerrestre() const
/*
  Tache:effacer le venusien
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

void Venusien::putExtraTerrestre() const
/*
  Tache:imprimer le venusien
*/
{
	coord.gotoXY(coord.getPositionX()-3, coord.getPositionY()-1);
	std::cout << "  [ ] " << std::endl;
	coord.gotoXY(coord.getPositionX() - 3, coord.getPositionY());
	std::cout << "[ ]V[ ]" << std::endl;
	coord.gotoXY(coord.getPositionX() - 3, coord.getPositionY()+1);
	std::cout << "  [ ] ";
}
void Venusien::deplacerVenusien()
/*
  Tache:deplcer aléatoirement le venusien
*/
{
	this->genereDirection();
	removeExtraTerrestre();

	switch (direction)
	{
	case 1:	
		coord.setPositionX(coord.getPositionX() - 1);
		break;
	case 2:	
		coord.setPositionX(coord.getPositionX() + 1);
		break;
	case 3:
		coord.setPositionY(coord.getPositionY() + 1);
		break;
	case 4:
		coord.setPositionY(coord.getPositionY() - 1);
		break;
	}
	putExtraTerrestre();
}

void Venusien::genereDirection()
/*
  Tache:trouver la direction du venusien
*/
{
	
	direction = rand() % 4 + 1;
	if (this->coord.getPositionX() == 65) {
		direction = 1;
	}
	else if (this->coord.getPositionX() == 4) {
		direction = 2;
	}
	else if (this->coord.getPositionY() == 33) {
		direction = 4;
	}
	else if(this->coord.getPositionY() == 2){
		direction = 3;
	}

}

void Venusien::recevoirDegats(VaisseauSpacial &vaisseau)
/*
  Tache: verifier la collision entre le venusien et le laser du vaisseau pour lui appliquer des dégats
  parametres: le vaisseau
*/
{
	for (int i = 0; i < vaisseau.getTableauDynamique().getNbLasers(); i++) {
		if ((((vaisseau.getTableauDynamique().getLasers()) + i)->coord.getPositionX() >= this->coord.getPositionX() - 3
			&& ((vaisseau.getTableauDynamique().getLasers()) + i)->coord.getPositionX() <= this->coord.getPositionX() + 3
			&& ((vaisseau.getTableauDynamique().getLasers()) + i)->coord.getPositionY()-2 == this->coord.getPositionY())
			|| (((vaisseau.getTableauDynamique().getLasers()) + i)->coord.getPositionY() - 2 == this->coord.getPositionY()
				&& ((vaisseau.getTableauDynamique().getLasers()) + i)->coord.getPositionX() == this->coord.getPositionX()))
		{
			this->reduirePointDevie();
 			((vaisseau.getTableauDynamique().getLasers()) + i)->killLaser();
			vaisseau.getTableauDynamique().retirer();
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

void Venusien::faireDegats(VaisseauSpacial &vaisseau)
/*
  Tache: verifier la collision entre le laser du venusien et le vaisseau pour lui appliquer des dégats
  parametres: le vaisseau
*/
{
	for (int i = 0; i < this->tabLasers.getNbLasers(); i++) {
		if (((this->tabLasers.getLasers() + i)->coord.getPositionX() >= vaisseau.coord.getPositionX()-3
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

void Venusien::resetExtraTerrestre()
/*
  Tache: trouver aléatoirement la position du venusien
*/
{
	coord.setPositionX(rand() % 62 + 4);
	coord.setPositionY(rand() % 31 + 2);
	isAlive = true;
	nombreExtraTerrestre++;
}

int Venusien::getPointeDeVie() const
{
	return this->valeurExtraTerrestre;
}

void Venusien::reduirePointDevie()
{
	this->valeurExtraTerrestre -= 3;
}

void Venusien::tirerLaser()
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


