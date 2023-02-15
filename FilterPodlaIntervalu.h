#pragma once
#include "Filter.h"
#include "UzemnaJednotka.h"
#include "structures/heap_monitor.h"

template <typename K, typename T, typename V>
class FilterPodlaIntervalu : public Filter<K, T, V>
{
protected:
	V aMin;
	V aMax;
public:
	FilterPodlaIntervalu(Kriterium<V, T>* pKriterium, V pMin, V pMax);
	bool splnaFilter(T pObjekt) override;
};

template <typename K, typename T, typename V>
inline FilterPodlaIntervalu<K, T, V>::FilterPodlaIntervalu(Kriterium<V, T>* pKriterium, V pMin, V pMax) :
	Filter<K,T,V>::Filter(pKriterium), aMin(pMin), aMax(pMax)
{
}

template <typename K, typename T, typename V>
inline bool FilterPodlaIntervalu<K, T, V>::splnaFilter(T pObjekt)
{
	V hodnota = Filter<K, T, V>::aKriterium->ohodnot(pObjekt);
	return (hodnota >= aMin && hodnota <= aMax);
}


class FilterUJPocetObyvatelov : public FilterPodlaIntervalu<std::string, UzemnaJednotka*, int>
{
public:
	FilterUJPocetObyvatelov(Kriterium<int, UzemnaJednotka*>* pKriterium, int pMin, int pMax) :
		FilterPodlaIntervalu(pKriterium, pMin, pMax)
	{
	};
};

class FilterUJZastavanost : public FilterPodlaIntervalu<std::string, UzemnaJednotka*, double>
{
public:
	FilterUJZastavanost(Kriterium<double, UzemnaJednotka*>* pKriterium, double pMin, double pMax) :
		FilterPodlaIntervalu(pKriterium, pMin, pMax)
	{
	};
};

