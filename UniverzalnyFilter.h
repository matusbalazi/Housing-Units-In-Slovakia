#pragma once
#include "structures/heap_monitor.h"

template <typename T>
class UniverzalnyFilter
{
public:
	virtual bool splnaFilter(T pObjekt) = 0;
	virtual ~UniverzalnyFilter() = default;
};
