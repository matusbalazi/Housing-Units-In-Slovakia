#pragma once
#include "UniverzalnyFilter.h"
#include "Kriterium.h"
#include "structures/table/sorted_sequence_table.h"
#include "structures/heap_monitor.h"

template <typename K, typename T, typename V>
class Filter : public UniverzalnyFilter<T>
{
protected:
	Kriterium<V, T>* aKriterium;
public:
	Filter(Kriterium<V, T>* pKriterium);
	//void vyfiltrujTabulku(structures::SortedSequenceTable<K, T>& pTabulka, structures::SortedSequenceTable<K, T>& pCistaTabulka);
};

template <typename K, typename T, typename V>
inline Filter<K, T, V>::Filter(Kriterium<V, T>* pKriterium) : aKriterium(pKriterium)
{
}

//template <typename K, typename T, typename V>
//inline void Filter<K, T, V>::vyfiltrujTabulku(structures::SortedSequenceTable<K, T>& pTabulka, structures::SortedSequenceTable<K, T>& pCistaTabulka)
//{
//	for (auto item : pTabulka) {
//		if (this->splnaFilter(item->accessData())) {
//			pCistaTabulka.insert(item->getKey(), item->accessData());
//		}
//	}
//}
