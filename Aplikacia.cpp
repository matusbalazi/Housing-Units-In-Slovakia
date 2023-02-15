#include "Aplikacia.h"

Aplikacia::Aplikacia()
{
	aNacitavac = new Nacitavanie();
	//aTabulka = new structures::SortedSequenceTable<std::string, UzemnaJednotka*>();
}

void Aplikacia::run()
{
	int uroven = 0;
	bool koniec = false;
	aNacitavac->nacitajInformacie("2 Územné èlenenie SR.csv", "1 Obce SR.csv");

	/*while (!koniec) {
		std::cout << "\t---------------------" << std::endl;
		std::cout << "\t|    HLAVNE MENU    |" << std::endl;
		std::cout << "\t---------------------" << std::endl;
		std::cout << "\n\t[1] Vypisanie informacii o obciach" << std::endl;
		std::cout << "\t[2] Zoradenie obci" << std::endl;
		std::cout << "\t[3] Vypisanie informacii o uzemnych jednotka" << std::endl;
		std::cout << "\t[4] Zoradenie uzemnych jednotiek splnajucich dany filter" << std::endl;
		std::cout << "\n\t[0] Ukoncit" << std::endl;
		std::cout << "\n\tZvolte uroven: ";
		std::cin >> uroven;
		system("CLS");
	}*/

	aNacitavac->vypisObce();

	std::cout << std::endl;
	std::cout << std::endl;

	aNacitavac->vypisOkresy();

	std::cout << std::endl;
	std::cout << std::endl;

	aNacitavac->vypisKraje();

	std::cout << std::endl;
	std::cout << std::endl;

	aNacitavac->vypisStaty();
}

Aplikacia::~Aplikacia()
{
	delete aNacitavac;
	aNacitavac = nullptr;

	/*for (auto item : *aTabulka) {
		delete item->accessData();
	}

	delete aTabulka;
	aTabulka = nullptr;*/
}
