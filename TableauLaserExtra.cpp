#include "TableauLaserExtra.h"
#include<iostream>

TableauLaserExtra::TableauLaserExtra()
{
	TableauLaserExtra::nbMax = 1;
	TableauLaserExtra::nbLasers = 0;
	TableauLaserExtra::lasers = new LaserExtra[TableauLaserExtra::nbMax];
}

/*TableauDynamique::~TableauDynamique()
{
	delete[] lasers;
}*/

unsigned int TableauLaserExtra::getNbLasers()const
{
	return this->nbLasers;
}

void TableauLaserExtra::setNbLasers(unsigned int nbLasers)
{
	this->nbLasers = nbLasers;
}

LaserExtra*  TableauLaserExtra::getLasers()const
{
	return this->lasers;
}

void TableauLaserExtra::ajouter(LaserExtra laser)
{
	if (TableauLaserExtra::nbMax == this->nbLasers) {
		LaserExtra* newTab = new LaserExtra[this->nbMax * 2];
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

void TableauLaserExtra::retirer()
{

	for (int i = 0; i < this->nbLasers; i++) {
		if (!(*(lasers + i)).isAlive) {
			/*LaserExtra* newTab;
			if (this->nbLasers != this->nbMax) {
				newTab = new LaserExtra[this->nbMax / 2];
			}
			else {
				newTab = new LaserExtra[this->nbMax];
			}*/
			for (unsigned int j = i; j < (this->nbLasers - 1); j++)
			{
				*(lasers + j) = *(lasers + j + 1);
			}
			/*for (int i = 0; i < this->nbLasers - 1; i++) {
				newTab[i] = this->lasers[i];
			}
			delete[] this->lasers;
			this->lasers = newTab;
			if (this->nbLasers != this->nbMax) {
				this->nbMax /= 2;
			}*/
			this->nbLasers--;
			//(*(lasers + i)).removeLaser();
		}
		
	}
	
}
