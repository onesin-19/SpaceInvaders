#ifndef VAISSEAU_H
#define VAISSEAU_H

#include "Coord.h"

class Vaisseau
{
protected:
	virtual void removeVaisseau() const;
	virtual void putVaisseau() const;

public:
	Coord coord;
	Vaisseau();		
	virtual void modifierPosition(char);
};

#endif