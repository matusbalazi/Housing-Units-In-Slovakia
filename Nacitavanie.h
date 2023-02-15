#pragma once
#include "structures/table/sorted_sequence_table.h"
#include "UzemnaJednotka.h"
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <iostream>
#include <cstring>
#include <cstdio>
#include "Obec.h"
#include "Okres.h"
#include "Kraj.h"
#include "Stat.h"
#include "structures/array/array.h"
#include "structures/heap_monitor.h"

static const std::string NAZOV_STATU = "Slovensko";

class Nacitavanie
{
private:
	structures::SortedSequenceTable<std::string, UzemnaJednotka*>* aObce;
	structures::SortedSequenceTable<std::string, UzemnaJednotka*>* aOkresy;
	structures::SortedSequenceTable<std::string, UzemnaJednotka*>* aKraje;
	structures::SortedSequenceTable<std::string, UzemnaJednotka*>* aStaty;
public:
	Nacitavanie();

	void nacitajInformacie(std::string pNazovSuboru1, std::string pNazovSuboru2);

	structures::SortedSequenceTable<std::string, UzemnaJednotka*>* getObce();
	structures::SortedSequenceTable<std::string, UzemnaJednotka*>* getOkresy();
	structures::SortedSequenceTable<std::string, UzemnaJednotka*>* getKraje();
	structures::SortedSequenceTable<std::string, UzemnaJednotka*>* getStaty();

	void vypisObce();
	void vypisOkresy();
	void vypisKraje();
	void vypisStaty();

	~Nacitavanie();
};

