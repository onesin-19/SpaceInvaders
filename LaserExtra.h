#pragma once
#include "Laser.h"
#include "UIKit.h"
class LaserExtra: public Laser {

public:
	void startLaser(int x, int y);
	void moveLaser();
	void putLaser() const;
};
