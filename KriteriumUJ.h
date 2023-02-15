#pragma once
#include "Kriterium.h"
#include "Obec.h"
#include "UzemnaJednotka.h"
#include "structures/heap_monitor.h"

template <typename T>
class KriteriumUJ : public Kriterium<T, UzemnaJednotka*>
{
public:
	virtual T ohodnot(UzemnaJednotka* pUzemnaJednotka) = 0;
};


class KriteriumUJNazov : public KriteriumUJ<std::string>
{
public:
	std::string ohodnot(UzemnaJednotka* pUzemnaJednotka) override;
};

inline std::string KriteriumUJNazov::ohodnot(UzemnaJednotka* pUzemnaJednotka)
{
	return pUzemnaJednotka->getNazov();
}


class KriteriumUJTyp : public KriteriumUJ<Typ>
{
public:
	Typ ohodnot(UzemnaJednotka* pUzemnaJednotka) override;
};

inline Typ KriteriumUJTyp::ohodnot(UzemnaJednotka* pUzemnaJednotka)
{
	return pUzemnaJednotka->getTyp();
}


class KriteriumUJPrislusnost : public KriteriumUJ<bool>
{
private:
	UzemnaJednotka* aVyssiUzemnyCelok;
public:
	KriteriumUJPrislusnost(UzemnaJednotka* pVyssiUzemnyCelok);
	void setVyssiUzemnyCelok(UzemnaJednotka* pVyssiUzemnyCelok);
	bool ohodnot(UzemnaJednotka* pUzemnaJednotka) override;
};

inline KriteriumUJPrislusnost::KriteriumUJPrislusnost(UzemnaJednotka* pVyssiUzemnyCelok)
{
	aVyssiUzemnyCelok = pVyssiUzemnyCelok;
}

inline void KriteriumUJPrislusnost::setVyssiUzemnyCelok(UzemnaJednotka* pVyssiUzemnyCelok)
{
	aVyssiUzemnyCelok = pVyssiUzemnyCelok;
}

inline bool KriteriumUJPrislusnost::ohodnot(UzemnaJednotka* pUzemnaJednotka)
{
	return pUzemnaJednotka->patriDoVyssiehoCelku(aVyssiUzemnyCelok);
}


class KriteriumUJPocetPreproduktivnychObyvatelov : public KriteriumUJ<int>
{
public:
	int ohodnot(UzemnaJednotka* pUzemnaJednotka) override;
};

inline int KriteriumUJPocetPreproduktivnychObyvatelov::ohodnot(UzemnaJednotka* pUzemnaJednotka)
{
	return pUzemnaJednotka->getPocetPredprodObyv();
}


class KriteriumUJPocetProduktivnychObyvatelov : public KriteriumUJ<int>
{
public:
	int ohodnot(UzemnaJednotka* pUzemnaJednotka) override;
};

inline int KriteriumUJPocetProduktivnychObyvatelov::ohodnot(UzemnaJednotka* pUzemnaJednotka)
{
	return pUzemnaJednotka->getPocetProdObyv();
}


class KriteriumUJPocetPoproduktivnychObyvatelov : public KriteriumUJ<int>
{
public:
	int ohodnot(UzemnaJednotka* pUzemnaJednotka) override;
};

inline int KriteriumUJPocetPoproduktivnychObyvatelov::ohodnot(UzemnaJednotka* pUzemnaJednotka)
{
	return pUzemnaJednotka->getPocetPoprodObyv();
}


class KriteriumUJPocetObyvatelov : public KriteriumUJ<int>
{
public:
	int ohodnot(UzemnaJednotka* pUzemnaJednotka) override;
};

inline int KriteriumUJPocetObyvatelov::ohodnot(UzemnaJednotka* pUzemnaJednotka)
{
	return pUzemnaJednotka->getPocetObyv();
}


class KriteriumUJCelkovaVymera : public KriteriumUJ<double>
{
public:
	double ohodnot(UzemnaJednotka* pUzemnaJednotka) override;
};

inline double KriteriumUJCelkovaVymera::ohodnot(UzemnaJednotka* pUzemnaJednotka)
{
	return (double)pUzemnaJednotka->getVymera();
}


class KriteriumUJZastavanaPlocha : public KriteriumUJ<double>
{
public:
	double ohodnot(UzemnaJednotka* pUzemnaJednotka) override;
};

inline double KriteriumUJZastavanaPlocha::ohodnot(UzemnaJednotka* pUzemnaJednotka)
{
	return (double)pUzemnaJednotka->getZastavanaPlocha();
}


class KriteriumUJZastavanost : public KriteriumUJ<double>
{
public:
	double ohodnot(UzemnaJednotka* pUzemnaJednotka) override;
};

inline double KriteriumUJZastavanost::ohodnot(UzemnaJednotka* pUzemnaJednotka)
{
	return (100 * ((double)pUzemnaJednotka->getZastavanaPlocha() / (double)pUzemnaJednotka->getVymera()));
}


