#pragma once
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "../heap_monitor.h"

	class BaseSet
	{

	private:
		int aMin;
		int aMax;
	public:
		BaseSet() : aMin(0), aMax(0) { srand(time(0)); }
		int getMin() { return aMin; }
		int getMax() { return aMax; };
		int genNumber(unsigned int pMin, unsigned int pMax) { return (pMax < pMin) ? 0 : (rand() % (pMax - pMin + 1) + pMin); };
		void setMinAndMax(int pMin, int pMax) { if (pMin < pMax) { aMin = pMin; aMax = pMax; } }
		~BaseSet() { aMin = 0; aMax = 0; };

	};

