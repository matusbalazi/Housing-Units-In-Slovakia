#pragma once
#include "UniverzalnyFilter.h"
#include "structures/table/sorted_sequence_table.h"
#include "structures/heap_monitor.h"

template <typename K, typename T>
class Filtrovac
{
public:
	Filtrovac();
	void vyfiltrujTabulku(structures::SortedSequenceTable<K, T>& pTabulka,
		UniverzalnyFilter<T>* pUniverzalnyFilter,
		structures::SortedSequenceTable<K, T>& pCistaTabulka);
	void vyfiltrujTabulkuPodlaNazvu(structures::SortedSequenceTable<K, T>& pTabulka,
		UniverzalnyFilter<T>* pUniverzalnyFilter,
		structures::SortedSequenceTable<K, T>& pCistaTabulka, std::string pNazov);
};

template <typename K, typename T>
inline Filtrovac<K, T>::Filtrovac()
{
}

template <typename K, typename T>
inline void Filtrovac<K, T>::vyfiltrujTabulku(
	structures::SortedSequenceTable<K, T>& pTabulka,
	UniverzalnyFilter<T>* pUniverzalnyFilter,
	structures::SortedSequenceTable<K, T>& pCistaTabulka)
{
	for (auto item : pTabulka) {
		if (pUniverzalnyFilter->splnaFilter(item->accessData())) {
			pCistaTabulka.insert(item->getKey(), item->accessData());
		}
	}
}

template<typename K, typename T>
inline void Filtrovac<K, T>::vyfiltrujTabulkuPodlaNazvu(structures::SortedSequenceTable<K, T>& pTabulka, UniverzalnyFilter<T>* pUniverzalnyFilter, structures::SortedSequenceTable<K, T>& pCistaTabulka, std::string pNazov)
{
	if (pTabulka.containsKey(pNazov)) {
		UzemnaJednotka* uzemnaJednotka = (pTabulka)[pNazov];
		pCistaTabulka.insert(pNazov, uzemnaJednotka);
	}
}
