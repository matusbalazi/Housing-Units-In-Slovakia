#include "Nacitavanie.h"

Nacitavanie::Nacitavanie()
{
	aObce = new structures::SortedSequenceTable<std::string, UzemnaJednotka*>();
	aOkresy = new structures::SortedSequenceTable<std::string, UzemnaJednotka*>();
	aKraje = new structures::SortedSequenceTable<std::string, UzemnaJednotka*>();
	aStaty = new structures::SortedSequenceTable<std::string, UzemnaJednotka*>();
}

void Nacitavanie::nacitajInformacie(std::string pNazovSuboru1, std::string pNazovSuboru2)
{

	std::string nazovStatu = NAZOV_STATU;
	Stat* auxStat = new Stat(nazovStatu);
	aStaty->insert(nazovStatu, auxStat);

	std::ifstream subor1(pNazovSuboru1);
	std::ifstream subor2(pNazovSuboru2);

	if (subor1.is_open() && subor2.is_open()) {

		std::string str;
		std::string nazovObce, nazovOkresu, nazovKraja;

		int pocetPredProdObyv;
		int pocetProdObyv;
		int pocetPoProdObyv;
		double vymera;
		double zastavanaPlocha;

		getline(subor1, str);
		getline(subor2, str);

		while (subor1.good() && subor2.good()) {
			getline(subor1, nazovObce, ';');
			getline(subor1, str, ' ');
			getline(subor1, nazovOkresu, ';');
			getline(subor1, nazovKraja);

			Kraj* auxKraj = new Kraj(nazovKraja, auxStat);

			if (!aKraje->containsKey(nazovKraja)) {
				aKraje->insert(nazovKraja, auxKraj);
			}
			else {
				delete auxKraj;
				for (auto item : *aKraje) {
					if (item->accessData()->getNazov() == nazovKraja) {
						auxKraj = reinterpret_cast<Kraj*>(item->accessData());
					}
				}
			}

			Okres* auxOkres = new Okres(nazovOkresu, auxKraj, auxStat);

			if (!aOkresy->containsKey(nazovOkresu)) {
				aOkresy->insert(nazovOkresu, auxOkres);
			}
			else {
				delete auxOkres;
				for (auto item : *aOkresy) {
					if (item->accessData()->getNazov() == nazovOkresu) {
						auxOkres = reinterpret_cast<Okres*>(item->accessData());
					}
				}
			}

			Obec* auxObec = nullptr;

			if (!aObce->containsKey(nazovObce)) {
				auxObec = new Obec(nazovObce, auxOkres, auxKraj, auxStat);

			}
			else {
				nazovObce = nazovObce + ", okres " + nazovOkresu;
				auxObec = new Obec(nazovObce, auxOkres, auxKraj, auxStat);
			}

			aObce->insert(nazovObce, auxObec);

			getline(subor2, str, ';');
			UzemnaJednotka* obec = (*aObce)[nazovObce];
			getline(subor2, str, ';');
			pocetPredProdObyv = std::stoi(str);
			getline(subor2, str, ';');
			pocetProdObyv = std::stoi(str);
			getline(subor2, str, ';');
			pocetPoProdObyv = std::stoi(str);
			getline(subor2, str, ';');
			vymera = std::stod(str);
			getline(subor2, str);
			zastavanaPlocha = std::stod(str);

			obec->addPocetPredprodObyv(pocetPredProdObyv);
			obec->addPocetProdObyv(pocetProdObyv);
			obec->addPocetPoprodObyv(pocetPoProdObyv);
			obec->addVymera(vymera);
			obec->addZastavanaPlocha(zastavanaPlocha);
		}
		subor1.close();
		subor2.close();
	}
	else
	{
		std::cout << "Nepodarilo sa otvorit subor!" << std::endl;
	}
}

structures::SortedSequenceTable<std::string, UzemnaJednotka*>* Nacitavanie::getObce()
{
	return aObce;
}

structures::SortedSequenceTable<std::string, UzemnaJednotka*>* Nacitavanie::getOkresy()
{
	return aOkresy;
}

structures::SortedSequenceTable<std::string, UzemnaJednotka*>* Nacitavanie::getKraje()
{
	return aKraje;
}

structures::SortedSequenceTable<std::string, UzemnaJednotka*>* Nacitavanie::getStaty()
{
	return aStaty;
}

void Nacitavanie::vypisObce()
{
	for (auto item : *aObce) {
		std::cout << "Obec: " << item->accessData()->getNazov() << ", ";
		std::cout << "Okres: " << item->accessData()->getJeVOkrese()->getNazov() << ", ";
		std::cout << "Kraj: " << item->accessData()->getJeVKraji()->getNazov() << ", ";
		std::cout << "Stat: " << item->accessData()->getJeVState()->getNazov() << ", ";
		std::cout << item->accessData()->getPocetPredprodObyv() << ", ";
		std::cout << item->accessData()->getPocetProdObyv() << ", ";
		std::cout << item->accessData()->getPocetPoprodObyv() << ", ";
		std::cout << item->accessData()->getVymera() << ", ";
		std::cout << item->accessData()->getZastavanaPlocha() << std::endl;
	}
}

void Nacitavanie::vypisOkresy()
{
	for (auto item : *aOkresy) {
		std::cout << "Okres: " << item->accessData()->getNazov() << ", ";
		std::cout << "Kraj: " << item->accessData()->getJeVKraji()->getNazov() << ", ";
		std::cout << "Stat: " << item->accessData()->getJeVState()->getNazov() << ", ";
		std::cout << item->accessData()->getPocetPredprodObyv() << ", ";
		std::cout << item->accessData()->getPocetProdObyv() << ", ";
		std::cout << item->accessData()->getPocetPoprodObyv() << ", ";
		std::cout << item->accessData()->getVymera() << ", ";
		std::cout << item->accessData()->getZastavanaPlocha() << std::endl;
	}
}

void Nacitavanie::vypisKraje()
{
	for (auto item : *aKraje) {
		std::cout << "Kraj: " << item->accessData()->getNazov() << ", ";
		std::cout << "Stat: " << item->accessData()->getJeVState()->getNazov() << ", ";
		std::cout << item->accessData()->getPocetPredprodObyv() << ", ";
		std::cout << item->accessData()->getPocetProdObyv() << ", ";
		std::cout << item->accessData()->getPocetPoprodObyv() << ", ";
		std::cout << item->accessData()->getVymera() << ", ";
		std::cout << item->accessData()->getZastavanaPlocha() << std::endl;
	}
}

void Nacitavanie::vypisStaty()
{
	for (auto item : *aStaty) {
		std::cout << "Stat: " << item->accessData()->getNazov() << ", ";
		std::cout << item->accessData()->getPocetPredprodObyv() << ", ";
		std::cout << item->accessData()->getPocetProdObyv() << ", ";
		std::cout << item->accessData()->getPocetPoprodObyv() << ", ";
		std::cout << item->accessData()->getVymera() << ", ";
		std::cout << item->accessData()->getZastavanaPlocha() << std::endl;
	}
}

Nacitavanie::~Nacitavanie()
{
	for (auto item : *aObce) {
		delete item->accessData();
	}

	for (auto item : *aOkresy) {
		delete item->accessData();
	}

	for (auto item : *aKraje) {
		delete item->accessData();
	}

	for (auto item : *aStaty) {
		delete item->accessData();
	}

	delete aObce;
	aObce = nullptr;
	delete aOkresy;
	aOkresy = nullptr;
	delete aKraje;
	aKraje = nullptr;
	delete aStaty;
	aStaty = nullptr;
}
