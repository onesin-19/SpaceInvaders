#include "LaserExtra.h"
#include <iostream>

void LaserExtra::startLaser(int x,int y)
{
	coord.setPositionX(x);
	coord.setPositionY(y);
	putLaser();
	isAlive = true;
}

void LaserExtra::moveLaser()
/*
  Tache: déplcer le laser de l'extraterrestre
*/
{
	removeLaser();
	if (coord.getPositionY() < 40)
	{
		coord.setPositionY(coord.getPositionY() + 1);
		putLaser();
	}
	else
		isAlive = false;
	UIKit::color(15);
}

void LaserExtra::putLaser() const
/*
  Tache: imprimer le laser de l'extraterrestre
*/
{
	UIKit::color(14);
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	std::cout << "O";
	
}
