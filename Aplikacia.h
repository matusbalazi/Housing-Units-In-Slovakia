#pragma once
#include "structures/heap_monitor.h"
#include <iostream>
#include "Nacitavanie.h"


#include "Kriterium.h"
#include "KriteriumUJ.h"

#include "UniverzalnyFilter.h"
#include "Filter.h"
#include "FilterPodlaHodnoty.h"
#include "FilterPodlaIntervalu.h"
#include "ZlozenyFilter.h"
#include "Filtrovac.h"

#include "structures/table/sorting/quick_sort.h"

class Aplikacia
{
private:
	Nacitavanie* aNacitavac;
	//UniverzalnyFilter<UzemnaJednotka*>* aFilter;
	//structures::SortedSequenceTable<std::string, UzemnaJednotka*>* aTabulka;
public:
	Aplikacia();
	void run();
	~Aplikacia();
};

