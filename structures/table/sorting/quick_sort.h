#pragma once

#include "sort.h"
#include "../unsorted_sequence_table.h"
#include "../../../Kriterium.h"
#include "../../heap_monitor.h"

namespace structures
{

	/// <summary> Triedenie Quick sort. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	template <typename K, typename T, typename V>
	class QuickSort
	{
	public:
		/// <summary> Utriedi tabulku triedenim Quick sort. </summary>
		/// <param name = "table"> NonortedSequenceTable, ktoru ma utriedit. </param>
		void sort(UnsortedSequenceTable<K, T>& table, Kriterium<V, T>& crit, bool asc);
	private:
		void quick(int min, int max, UnsortedSequenceTable<K, T>& table, Kriterium<V, T>& crit, bool asc);
	};

	template<typename K, typename T, typename V>
	inline void QuickSort<K, T, V>::sort(UnsortedSequenceTable<K, T>& table, Kriterium<V, T>& crit, bool asc)
	{
		quick(0, table.size() - 1, table, crit, asc);
	}

	template<typename K, typename T, typename V>
	inline void QuickSort<K, T, V>::quick(int min, int max, UnsortedSequenceTable<K, T>& table, Kriterium<V, T>& crit, bool asc)
	{
		if (asc == true) {
			T pivot = (table)[((min + max) / 2)];
			int lavy = min;
			int pravy = max;
			do {
				while (crit.ohodnot((table)[lavy]) < crit.ohodnot(pivot)) {
					lavy++;
				}
				while (crit.ohodnot((table)[pravy]) > crit.ohodnot(pivot)) {
					pravy--;
				}
				if (lavy <= pravy) {
					table.swap(lavy, pravy);
					lavy++;
					pravy--;
				}
			} while (lavy <= pravy);
			if (min < pravy) {
				quick(min, pravy, table, crit, asc);
			}
			if (lavy < max) {
				quick(lavy, max, table, crit, asc);
			}
		}
		else {
			T pivot = (table)[((min + max) / 2)];
			int lavy = min;
			int pravy = max;
			do {
				while (crit.ohodnot((table)[lavy]) > crit.ohodnot(pivot)) {
					lavy++;
				}
				while (crit.ohodnot((table)[pravy]) < crit.ohodnot(pivot)) {
					pravy--;
				}
				if (lavy <= pravy) {
					table.swap(lavy, pravy);
					lavy++;
					pravy--;
				}
			} while (lavy <= pravy);
			if (min < pravy) {
				quick(min, pravy, table, crit, asc);
			}
			if (lavy < max) {
				quick(lavy, max, table, crit, asc);
			}
		}
		
	}

}