#pragma once

#include <iostream>
#include "base_set.h"
#include "../structure.h"
#include "../structure_iterator.h"
#include "../ds_structure_types.h"
#include "../heap_monitor.h"

namespace structures 
{
	class BitSet
	{
	private:
		unsigned long long* aBitSet;
		BaseSet* aBaseSet;
		int aSize;
	public:
		BitSet(BaseSet* pBaseSet);
		BitSet(BitSet& other);
		BitSet& operator=(BitSet& other);
		bool operator==(BitSet& other);
		
		bool isSubset(BitSet& other);
		BitSet& intersection(BitSet& other);
		BitSet& unionWith(BitSet& other);
		BitSet& substraction(BitSet& other);

		void insert(int pData);
		void remove(int pData);
		bool contains(int pData);

		int size();
		void print();
		~BitSet();
	};

	inline BitSet::BitSet(BaseSet* pBaseSet) {
		aBaseSet = pBaseSet;
		aSize = (pBaseSet->getMax() - pBaseSet->getMin() + 1) / 64 + 1;
		aBitSet = new unsigned long long[aSize];

		for (int i = 0; i < aSize; i++) {
			aBitSet[i] = 0;
		}

		/*aBitSet[0] = 1;
		aBitSet[1] = 1;
		aBitSet[2] = 1;
		aBitSet[3] = 1;*/
	}

	inline BitSet::BitSet(BitSet& other) {
		aBaseSet = other.aBaseSet;
		aSize = other.aSize;
		aBitSet = new unsigned long long[other.aSize];
		for (int i = 0; i < aSize; i++) {
			aBitSet[i] = other.aBitSet[i];
		}
	}

	inline BitSet& BitSet::operator=(BitSet& other)
	{
		if (this != &other) {
			delete[] aBitSet;

			aBaseSet = other.aBaseSet;
			aSize = other.aSize;
			aBitSet = new unsigned long long[other.aSize];
			for (int i = 0; i < aSize; i++) {
				aBitSet[i] = other.aBitSet[i];
			}
		}
		return *this;
	}

	inline bool BitSet::operator==(BitSet& other)
	{
		if (this != &other) {
			if (aBaseSet->getMin() == other.aBaseSet->getMin() && aBaseSet->getMax() == other.aBaseSet->getMax()) {
				int index = 0;
				while (aBitSet[index] == other.aBitSet[index] && index < aSize) {
					index++;
				}
				if (index == aSize) {
					return true;
				}
				return false;
			}
			return false;
		}
		return true;
	}

	inline bool BitSet::isSubset(BitSet& other)
	{
		if (aBaseSet->getMin() == other.aBaseSet->getMin() && aBaseSet->getMax() == other.aBaseSet->getMax()) {
			for (int i = 0; i < aSize; i++) {
				if ((other.aBitSet[i] ^ (aBitSet[i] & other.aBitSet[i])) != 0) {
					return false;
				}
			}
			return true;
		}
		return false;
	}

	inline BitSet& BitSet::intersection(BitSet& other)
	{
		if (aBaseSet->getMin() == other.aBaseSet->getMin() && aBaseSet->getMax() == other.aBaseSet->getMax()) {
			BitSet* set = new BitSet(*this);
			for (int i = 0; i < aSize; i++) {
				set->aBitSet[i] = aBitSet[i] & other.aBitSet[i];
			}
			return *set;
		}
		return *this;
	}

	inline BitSet& BitSet::unionWith(BitSet& other)
	{
		if (aBaseSet->getMin() == other.aBaseSet->getMin() && aBaseSet->getMax() == other.aBaseSet->getMax()) {
			BitSet* set = new BitSet(*this);
			for (int i = 0; i < aSize; i++) {
				set->aBitSet[i] = aBitSet[i] | other.aBitSet[i];
			}
			return *set;
		}
		return *this;
	}

	inline BitSet& BitSet::substraction(BitSet& other)
	{
		if (aBaseSet->getMin() == other.aBaseSet->getMin() && aBaseSet->getMax() == other.aBaseSet->getMax()) {
			BitSet* set = new BitSet(*this);
			for (int i = 0; i < aSize; i++) {
				set->aBitSet[i] = aBitSet[i] ^ (aBitSet[i] & other.aBitSet[i]);
			}
			return *set;
		}
		return *this;
	}

	inline void BitSet::insert(int pData)
	{
		if (pData >= aBaseSet->getMin() && pData <= aBaseSet->getMax()) {
			aBitSet[(pData - aBaseSet->getMin()) / 64] |= (unsigned long long) 1 << ((pData - aBaseSet->getMin()) % 64);
		}
	}

	inline void BitSet::remove(int pData)
	{
		if (pData >= aBaseSet->getMin() && pData <= aBaseSet->getMax()) {
			aBitSet[(pData - aBaseSet->getMin()) / 64] &= (~((unsigned long long) 1 << ((pData - aBaseSet->getMin()) % 64)));
		}
	}

	inline bool BitSet::contains(int pData)
	{
		if (pData >= aBaseSet->getMin() && pData <= aBaseSet->getMax()) {
			unsigned long long offset = (unsigned long long) 1;
			offset <<= ((pData - aBaseSet->getMin()) % 64);
			if (offset == (offset & aBitSet[(pData - aBaseSet->getMin()) / 64])) {
				return true;
			}
		}
		return false;
	}

	inline int BitSet::size()
	{
		return aSize;
	}

	inline void BitSet::print()
	{
		for (int i = aBaseSet->getMin(); i < aSize * 64; i++) {
			std::cout << contains(i);
			if (i % 64 == 0) {
				std::cout << std::endl;
			}
		}
		std::cout << std::endl;
	}

	inline BitSet::~BitSet() {

		delete[] aBitSet;
		aBitSet = nullptr;
		aSize = 0;
	}
}
