#pragma once
#include "Filter.h"
#include "UzemnaJednotka.h"
#include "structures/heap_monitor.h"

template <typename K, typename T, typename V>
class FilterPodlaHodnoty : public Filter<K, T, V>
{
protected:
	V aHodnota;
public:
	FilterPodlaHodnoty(Kriterium<V, T>* pKriterium, V pHodnota);
	bool splnaFilter(T pObjekt) override;
};

template <typename K, typename T, typename V>
inline FilterPodlaHodnoty<K, T, V>::FilterPodlaHodnoty(Kriterium<V, T>* pKriterium, V pHodnota) :
	Filter<K,T,V>::Filter(pKriterium), aHodnota(pHodnota)
{
}

template <typename K, typename T, typename V>
inline bool FilterPodlaHodnoty<K, T, V>::splnaFilter(T pObjekt)
{
	return (Filter<K, T, V>::aKriterium->ohodnot(pObjekt) == aHodnota);
}


class FilterUJNazov : public FilterPodlaHodnoty<std::string, UzemnaJednotka*, std::string>
{
public:
	FilterUJNazov(Kriterium<std::string, UzemnaJednotka*>* pKriterium, std::string pHodnota) :
		FilterPodlaHodnoty(pKriterium, pHodnota)
	{
	};
};

class FilterUJTyp : public FilterPodlaHodnoty<std::string, UzemnaJednotka*, Typ>
{
public:
	FilterUJTyp(Kriterium<Typ, UzemnaJednotka*>* pKriterium, Typ pHodnota) :
		FilterPodlaHodnoty(pKriterium, pHodnota)
	{
	};
};

class FilterUJPrislusnost : public FilterPodlaHodnoty<std::string, UzemnaJednotka*, bool>
{
public:
	FilterUJPrislusnost(Kriterium<bool, UzemnaJednotka*>* pKriterium, bool pHodnota) :
		FilterPodlaHodnoty(pKriterium, pHodnota)
	{
	};
};
