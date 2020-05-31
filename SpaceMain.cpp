#include "Jeu.h"

int main()
{
	
	char caractere;
	int idOptionSelectionne;
	do {
		Menu menu(45, 22);
		menu.addOption("Commencer Partie");
		menu.addOption("Regles du jeu");
		menu.addOption("Quitter");
		Menu menu2(45, 19);
		menu2.addOption("Facile");
		menu2.addOption("Normale");
		menu2.addOption("Difficile");
		menu.afficherMenu();
		idOptionSelectionne = menu.play();
		int id;
		Jeu jeu;
		switch (idOptionSelectionne) {
		case 0:
			system("cls");
			id = menu2.play();
			switch (id)
			{
			case 0:
				jeu.jouer(8);
				break;
			case 1:
				jeu.jouer(5);
				break;
			case 2:
				jeu.jouer(2);
				break;
			}
			cout << "nouvelle partie?(o/n) ";
			do
			{
				caractere = toupper(_getch());
			} while ((caractere != 'O') && (caractere != 'N'));
			if (tolower(caractere) == 'o') {
				system("cls");
			}
			break;
		case 1:
			afficherRegles();
			cout << "retour au menu ?(o/n) ";
			do
			{
				caractere = toupper(_getch());
			} while ((caractere != 'O') && (caractere != 'N'));
			if (tolower(caractere) == 'o') {
				system("cls");
			}
			break;
		case 2:
			system("cls");
			break;
		}

	} while (idOptionSelectionne != 2 && tolower(caractere) == 'o');
	system("pause");
	return 0;
}