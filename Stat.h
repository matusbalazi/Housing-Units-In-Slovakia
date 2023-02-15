#pragma once
#include "UzemnaJednotka.h"
#include "structures/heap_monitor.h"

class Stat : public UzemnaJednotka
{
private:
	std::string aNazov;
public:
	Stat(std::string pNazov);
	std::string getNazov();
	~Stat();
};

inline Stat::Stat(std::string pNazov) :
	UzemnaJednotka(pNazov, nullptr, nullptr, nullptr), aNazov(pNazov)
{
	aTyp = Typ::STAT;
}

inline std::string Stat::getNazov()
{
	if (this) {
		return aNazov;
	}
	else {
		return " ";
	}
}

inline Stat::~Stat()
{
}

