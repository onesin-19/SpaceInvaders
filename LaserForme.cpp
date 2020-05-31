#include "LaserForme.h"
#include <iostream>

void LaserForme::moveLaser()
/*
  Tache: déplacer le laser du vaisseau
*/
{
	removeLaser();
	if (coord.getPositionY() > 2)
	{
		coord.setPositionY(coord.getPositionY() - 1);
		putLaser();
	}
	else
		isAlive = false;
	UIKit::color(15);
}
void LaserForme::removeLaser() const
{
	coord.gotoXY(coord.getPositionX(), coord.getPositionY()-1);
	std::cout << " ";
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	std::cout << " ";
}

void LaserForme::putLaser() const
/*
  Tache: imprimer le laser du vasseau
*/
{
	UIKit::color(10);
	coord.gotoXY(coord.getPositionX(), coord.getPositionY()-1);
	std::cout << "^";
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	std::cout << (char)186;
}
