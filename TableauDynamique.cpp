#include "TableauDynamique.h"
#include<iostream>

TableauDynamique::TableauDynamique()
{
	TableauDynamique::nbMax = 1;
	TableauDynamique::nbLasers = 0;
	TableauDynamique::lasers = new LaserForme[TableauDynamique::nbMax];
}

unsigned int TableauDynamique::getNbLasers()const
{
	return this->nbLasers;
}

void TableauDynamique::setNbLasers(unsigned int nbLasers)
{
	this->nbLasers = nbLasers;
}

LaserForme*  TableauDynamique::getLasers()const
{
	return this->lasers;
}

void TableauDynamique::ajouter(LaserForme laser)
{
	if (TableauDynamique::nbMax == this->nbLasers) {
		LaserForme* newTab = new LaserForme[this->nbMax * 2];
		for (int i = 0; i < this->nbLasers; i++) {
			newTab[i] = this->lasers[i];
		}
		delete[] this->lasers;
		this->lasers = newTab;
		this->nbMax *= 2;
	}
	lasers[this->nbLasers] = laser;
	this->nbLasers++;
}

void TableauDynamique::retirer()
{
	
	for (int i = 0; i < this->nbLasers ; i++) {
		if (!(*(this->lasers + i)).isAlive) {
			for (unsigned int j = i; j < (this->nbLasers - 1); j++)
			{
				*(this->lasers + j) = *(lasers + j + 1);
			}
 			this->nbLasers--;
		}
		
	} 
}
