#pragma once
#include "UzemnaJednotka.h"
#include "structures/heap_monitor.h"

class Kraj : public UzemnaJednotka
{
private:
	std::string aNazov;
public:
	Kraj(std::string pNazov, UzemnaJednotka* pStat);
	std::string getNazov();
	~Kraj();
};

inline Kraj::Kraj(std::string pNazov, UzemnaJednotka* pStat) :
	UzemnaJednotka(pNazov, nullptr, nullptr, pStat), aNazov(pNazov)
{
	aTyp = Typ::KRAJ;
}

inline std::string Kraj::getNazov()
{
	if (this) {
		return aNazov;
	}
	else {
		return " ";
	}
}

inline Kraj::~Kraj()
{
}