#ifndef LASER_H
#define LASER_H

#include "Coord.h"

class Laser
{
public:
	bool isAlive;
	Coord coord;

	virtual void startLaser(int);
	virtual void removeLaser() const;
	virtual void putLaser() const;
	virtual void moveLaser();
	virtual void killLaser();
};

#endif