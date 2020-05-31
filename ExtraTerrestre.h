#ifndef EXTRATERRESTRE_H
#define EXTRATERRESTRE_H

#include "Coord.h"

class ExtraTerrestre
{
protected:
	static int nombreExtraTerrestre;
	int typeExtraTerrestre;
	int valeurExtraTerrestre;

public:
	Coord coord;
	bool isAlive;

	ExtraTerrestre(int,int);
	static void reduireNombreExtraTerrestre();
	static int getNombreExtraTerrestre();
	static void resetNombreExtraTerrestre();
	virtual void removeExtraTerrestre() const;
	virtual void putExtraTerrestre() const;
	virtual int ajouterPoints() const;
	virtual void resetExtraTerrestre();
};

#endif




