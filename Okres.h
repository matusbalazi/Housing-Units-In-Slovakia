#pragma once
#include "UzemnaJednotka.h"
#include "structures/heap_monitor.h"

class Okres : public UzemnaJednotka
{
private:
	std::string aNazov;
public:
	Okres(std::string pNazov, UzemnaJednotka* pKraj, UzemnaJednotka* pStat);
	std::string getNazov();
	~Okres();
};

inline Okres::Okres(std::string pNazov, UzemnaJednotka* pKraj, UzemnaJednotka* pStat) :
	UzemnaJednotka(pNazov, nullptr, pKraj, pStat), aNazov(pNazov)
{
	aTyp = Typ::OKRES;
}

inline std::string Okres::getNazov()
{
	if (this) {
		return aNazov;
	}
	else {
		return " ";
	}
}

inline Okres::~Okres()
{
}
