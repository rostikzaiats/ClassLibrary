#pragma once
#include "Wine.h"
#include <string>

Class PackagedWine : public Wine
{
private:
	double pacW_volume;
	string pacW_container;

public:
	PackagedWine();
	PackagedWine(double volume, string container);
	PackagedWine(const PackagedWine& P);
	virtual ~PackagedWine();

	
}
