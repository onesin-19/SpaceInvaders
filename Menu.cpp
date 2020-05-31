#include "Menu.h"

Menu::Menu(int x, int y)
{
	this->maxOptions = 1;
	this->nbOptions = 0;
	this->idOptionSelectione = 0;
	this->options = new std::string[this->maxOptions];
	this->coord.setPositionX(x);
	this->coord.setPositionY(y);
}

void Menu::afficherMenu()
{
	UIKit::color(11);
	playMenuSound();
	std::cout << "			  oooooooo8 " << std::endl;
	std::cout << "			 888        ooooooooo     ooooooo    ooooooo    ooooooooo8 " << std::endl;
	std::cout << "			  888oooooo  888    888   ooooo888 888     888 888oooooo8  " << std::endl;
	std::cout << "			         888 888    888 888    888 888         888         " << std::endl;
	std::cout << "			 o88oooo888  888ooo88    88ooo88 8o  88ooo888    88oooo888 " << std::endl;
	std::cout << "			            o888                                           " << std::endl << std::endl << std::endl;
	std::cout << "			 ooooo                                       oooo" << std::endl ;
	std::cout << "			  888  oo oooooo oooo   oooo ooooooo    ooooo888  ooooooooo8 oo oooooo     oooooooo8" << std::endl;
	std::cout << "			  888   888   888 888   888  ooooo888 888    888 888oooooo8   888    888  888ooooooo" << std::endl;
	std::cout << "			  888   888   888  888 888 888    888 888    888 888          888                 888" << std::endl;
	std::cout << "			 o888o o888o o888o   888    88ooo88 8o  88ooo888o  88oooo888 o888o        88oooooo88" << std::endl << std::endl << std::endl;
                                                                        
	std::cout << "							 ooooo ooooo " << std::endl;
	std::cout << "							  888   888  " << std::endl;
	std::cout << "							  888   888  " << std::endl;
	std::cout << "							  888   888  " << std::endl;
	std::cout << "							 o888o o888o " << std::endl;
}

void Menu::playMenuSound() {
	PlaySound("spaceInvaders.wav", GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC);
}

void Menu::playBackgroundSound() {
	PlaySound("background.wav", GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC);
}

void Menu::addOption(std::string newOption)
{

	if (this->maxOptions == this->nbOptions) {
		std::string* newTab = new string[this->maxOptions * 2];
		for (int i = 0; i < this->nbOptions; i++) {
			newTab[i] = this->options[i];
		}
		delete[] this->options;
		this->options = newTab;
		this->maxOptions *= 2;
	}
	options[this->nbOptions] = newOption;
	this->nbOptions++;
}

void Menu::naviguer()
/*
  Tache: naviguer entre les options du menu
*/
{
	while (!this->validerOption()) {
		if (this->nbOptions > 0) {
			if (GetAsyncKeyState(VK_UP)) {
				cout << "\b\b   ";
				if (this->idOptionSelectione > 0) {
					this->idOptionSelectione--;
					UIKit::gotoXY(this->coord.getPositionX(), this->coord.getPositionY()+ (this->idOptionSelectione) + 2);
				}
				else {
					this->idOptionSelectione = this->nbOptions - 1;
					UIKit::gotoXY(this->coord.getPositionX(), this->coord.getPositionY()+this->idOptionSelectione + 2);
				}
				cout << (char)205;
				cout << ">";
			}
			else if (GetAsyncKeyState(VK_DOWN)) {
				cout << "\b\b   ";
				this->idOptionSelectione = (++this->idOptionSelectione) % this->nbOptions;
				UIKit::gotoXY(this->coord.getPositionX(), this->coord.getPositionY()+((this->idOptionSelectione) % this->nbOptions) + 2);
				cout << (char)205;
				cout << ">";
			}
		}

		Sleep(160);
	}
}

bool Menu::validerOption()
{
	int touche = -1;
	if (_kbhit()) {
		touche = _getch();
	}
	if (touche == 32 || touche == 13) {
		system("cls");
		return true;
	}
	else {
		return false;
	}
}

int Menu::play()
{
	UIKit::setDimensionFenetre(0, 0, 120, 41);
	UIKit::curseurVisible(false);
	//playBackgroundSound();
	//playMenuSound();
	UIKit::cadre(this->coord.getPositionX()-2, this->coord.getPositionY(), this->coord.getPositionX()+27, this->coord.getPositionY()+this->nbOptions+3, 10);
	UIKit::color(11);
	for (int i = 0; i < this->nbOptions; i++)
	{
		UIKit::gotoXY(this->coord.getPositionX(), this->coord.getPositionY() + 2+i);
		std::cout << "     " << this->options[i] << endl;
	}
	if (this->nbOptions > 0) {
		UIKit::gotoXY(this->coord.getPositionX(), this->coord.getPositionY()+2);
		cout << (char)205;
		cout << ">";
	}
	else {
		cout << "menu vide";
	}
	this->naviguer();
	return this->idOptionSelectione;
}


Menu::~Menu()
{
	delete[] options;
}
