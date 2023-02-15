#pragma once
#include "UniverzalnyFilter.h"
#include "structures/list/array_list.h"
#include "structures/heap_monitor.h"

template <typename T>
class ZlozenyFilter : public UniverzalnyFilter<T>
{
private:
	structures::ArrayList<UniverzalnyFilter<T>*>* aZoznamFiltrov;
public:
	ZlozenyFilter();
	void pridajFilter(UniverzalnyFilter<T>* pFilter);
	void odstranVsetkyFiltre();
	bool splnaFilter(T pObjekt) override;
	~ZlozenyFilter();
};

template <typename T>
inline ZlozenyFilter<T>::ZlozenyFilter()
{	
	aZoznamFiltrov = new structures::ArrayList<UniverzalnyFilter<T>*>();
}

template <typename T>
inline void ZlozenyFilter<T>::pridajFilter(UniverzalnyFilter<T>* pFilter)
{
	aZoznamFiltrov->add(pFilter);
}

template<typename T>
inline void ZlozenyFilter<T>::odstranVsetkyFiltre()
{
	/*for (int i = 0; i < aZoznamFiltrov->size(); i++) {
		delete (*aZoznamFiltrov)[i];
	}*/
	for (auto item : *aZoznamFiltrov) {
		delete item;
	}
	aZoznamFiltrov->clear();
}

template <typename T>
inline bool ZlozenyFilter<T>::splnaFilter(T pObjekt)
{
	for (auto item : *aZoznamFiltrov) {
		if (!item->splnaFilter(pObjekt)) {
			return false;
		}
	}
	return true;
}

template <typename T>
inline ZlozenyFilter<T>::~ZlozenyFilter()
{
	delete aZoznamFiltrov;
	aZoznamFiltrov = nullptr;
}
