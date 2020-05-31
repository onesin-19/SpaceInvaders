#pragma once
#include "Laser.h"
#include "UIKit.h"

class LaserForme: public Laser{
	
public:
	void moveLaser();
	void removeLaser() const;
	void putLaser() const;
};