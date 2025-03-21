#pragma once
#include "Wine.h"
#include <string>

	const static string GLASS_CONTAINER = "Glass";
	const static string PAKAGE_CONTAINER = "Tetra Pack";
class PackagedWine : public Wine
{
private:
	double pacW_volume;
	string pacW_package;

public:
	PackagedWine();
	PackagedWine(const string& name, const string& color, const string& swetness, double strength,
	double volume);
	PackagedWine(const PackagedWine& P);
	~PackagedWine();
	virtual void printOn(ostream& os)const override;
	void changePackage();
	PackagedWine operator/(double n);
};
