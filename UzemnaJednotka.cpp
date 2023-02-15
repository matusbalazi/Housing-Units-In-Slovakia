#include "UzemnaJednotka.h"

UzemnaJednotka::UzemnaJednotka(std::string pNazov, UzemnaJednotka* pJeVOkrese, 
    UzemnaJednotka* pJeVKraji, UzemnaJednotka* pJeVState)
    : aNazov(pNazov), aJeVOkrese(pJeVOkrese), aJeVKraji(pJeVKraji), aJeVState(pJeVState)
{
}

std::string UzemnaJednotka::getNazov()
{
    if (this) {
        return aNazov;
    }
    else {
        return " ";
    }  
}

Typ UzemnaJednotka::getTyp()
{
    return aTyp;
}

UzemnaJednotka* UzemnaJednotka::getJeVOkrese()
{
    return aJeVOkrese;
}

UzemnaJednotka* UzemnaJednotka::getJeVKraji()
{
    return aJeVKraji;
}

UzemnaJednotka* UzemnaJednotka::getJeVState()
{
    return aJeVState;
}

int UzemnaJednotka::getPocetPredprodObyv()
{
    return aPocetPredprodObyv;
}

int UzemnaJednotka::getPocetProdObyv()
{
    return aPocetProdObyv;
}

int UzemnaJednotka::getPocetPoprodObyv()
{
    return aPocetPoprodObyv;
}

long long UzemnaJednotka::getVymera()
{
    return (long long)aVymera;
}

long long UzemnaJednotka::getZastavanaPlocha()
{
    return (long long)aZastavanaPlocha;
}

int UzemnaJednotka::getPocetObyv()
{
    return (aPocetPredprodObyv + aPocetProdObyv + aPocetPoprodObyv);
}

double UzemnaJednotka::getZastavanost()
{
    return (100 * ((double)aZastavanaPlocha / (double)aVymera));
}

void UzemnaJednotka::addPocetPredprodObyv(int pPocetPredprodObyv)
{
    aPocetPredprodObyv += pPocetPredprodObyv;
}

void UzemnaJednotka::addPocetProdObyv(int pPocetProdObyv)
{
    aPocetProdObyv += pPocetProdObyv;
}

void UzemnaJednotka::addPocetPoprodObyv(int pPocetPoprodObyv)
{
    aPocetPoprodObyv += pPocetPoprodObyv;
}

void UzemnaJednotka::addVymera(double pVymera)
{
    aVymera += pVymera;
}

void UzemnaJednotka::addZastavanaPlocha(double pZastavanaPlocha)
{
    aZastavanaPlocha += pZastavanaPlocha;
}

bool UzemnaJednotka::patriDoVyssiehoCelku(UzemnaJednotka* pVyssiCelok)
{
    if (pVyssiCelok == getJeVOkrese() ||
        pVyssiCelok == getJeVKraji() ||
        pVyssiCelok == getJeVState())
    {
        return true;
    }
    else {
        return false;
    }
}
