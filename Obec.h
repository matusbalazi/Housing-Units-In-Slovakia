#pragma once
#include "UzemnaJednotka.h"
#include "structures/heap_monitor.h"

class Obec : public UzemnaJednotka
{
private:
	std::string aNazov;
public:
	Obec(std::string pNazov, UzemnaJednotka* pOkres, 
		UzemnaJednotka* pKraj, UzemnaJednotka* pStat);
	std::string getNazov();

	void addPocetPredprodObyv(int pPocetPredprodObyv) override;
	void addPocetProdObyv(int pPocetProdObyv) override;
	void addPocetPoprodObyv(int pPocetPoprodObyv) override;
	void addVymera(double pVymera) override;
	void addZastavanaPlocha(double pZastavanaPlocha) override;

	~Obec();
};

inline Obec::Obec(std::string pNazov, UzemnaJednotka* pOkres, 
	UzemnaJednotka* pKraj, UzemnaJednotka* pStat) :
	UzemnaJednotka(pNazov, pOkres, pKraj, pStat), aNazov(pNazov)
{
	aTyp = Typ::OBEC;
}

inline std::string Obec::getNazov()
{
	return aNazov;
}

inline void Obec::addPocetPredprodObyv(int pPocetPredprodObyv)
{
	UzemnaJednotka::addPocetPredprodObyv(pPocetPredprodObyv);
	getJeVKraji()->addPocetPredprodObyv(pPocetPredprodObyv);
	getJeVOkrese()->addPocetPredprodObyv(pPocetPredprodObyv);
	getJeVState()->addPocetPredprodObyv(pPocetPredprodObyv);
}

inline void Obec::addPocetProdObyv(int pPocetProdObyv)
{
	UzemnaJednotka::addPocetProdObyv(pPocetProdObyv);
	getJeVKraji()->addPocetProdObyv(pPocetProdObyv);
	getJeVOkrese()->addPocetProdObyv(pPocetProdObyv);
	getJeVState()->addPocetProdObyv(pPocetProdObyv);
}

inline void Obec::addPocetPoprodObyv(int pPocetPoprodObyv)
{
	UzemnaJednotka::addPocetPoprodObyv(pPocetPoprodObyv);
	getJeVKraji()->addPocetPoprodObyv(pPocetPoprodObyv);
	getJeVOkrese()->addPocetPoprodObyv(pPocetPoprodObyv);
	getJeVState()->addPocetPoprodObyv(pPocetPoprodObyv);
}

inline void Obec::addVymera(double pVymera)
{
	UzemnaJednotka::addVymera(pVymera);
	getJeVKraji()->addVymera(pVymera);
	getJeVOkrese()->addVymera(pVymera);
	getJeVState()->addVymera(pVymera);
}

inline void Obec::addZastavanaPlocha(double pZastavanaPlocha)
{
	UzemnaJednotka::addZastavanaPlocha(pZastavanaPlocha);
	getJeVKraji()->addZastavanaPlocha(pZastavanaPlocha);
	getJeVOkrese()->addZastavanaPlocha(pZastavanaPlocha);
	getJeVState()->addZastavanaPlocha(pZastavanaPlocha);
}

inline Obec::~Obec()
{
}

