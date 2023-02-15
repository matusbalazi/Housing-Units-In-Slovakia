#pragma once
#include <iostream>
#include <cstring>
#include "Typ.h"
#include "structures/heap_monitor.h"

class UzemnaJednotka
{
protected:
	std::string aNazov;
	Typ aTyp;

	int aPocetPredprodObyv = 0;
	int aPocetProdObyv = 0;
	int aPocetPoprodObyv = 0;
	double aVymera = 0.0;
	double aZastavanaPlocha = 0.0;

	UzemnaJednotka* aJeVOkrese;
	UzemnaJednotka* aJeVKraji;
	UzemnaJednotka* aJeVState;

public:
	UzemnaJednotka(std::string pNazov,UzemnaJednotka* pJeVOkrese = nullptr, 
		UzemnaJednotka* pJeVKraji = nullptr, UzemnaJednotka* pJeVState = nullptr);

	std::string getNazov();
	Typ getTyp();
	
	UzemnaJednotka* getJeVOkrese();
	UzemnaJednotka* getJeVKraji();
	UzemnaJednotka* getJeVState();

	int getPocetPredprodObyv();
	int getPocetProdObyv();
	int getPocetPoprodObyv();
	long long getVymera();
	long long getZastavanaPlocha();

	int getPocetObyv();
	double getZastavanost();

	virtual void addPocetPredprodObyv(int pPocetPredprodObyv);
	virtual void addPocetProdObyv(int pPocetProdObyv);
	virtual void addPocetPoprodObyv(int pPocetPoprodObyv);
	virtual void addVymera(double pVymera);
	virtual void addZastavanaPlocha(double pZastavanaPlocha);

	bool patriDoVyssiehoCelku(UzemnaJednotka* pVyssiCelok);

	virtual ~UzemnaJednotka() = default;
};

