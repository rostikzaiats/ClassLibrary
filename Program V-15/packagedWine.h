#pragma once
#include "Wine.h"
#include <string>

enum  ContainerType {
	Glass,
	TetraPack
};


inline string getContainerName(ContainerType type) {
	switch (type) {
	case ContainerType::Glass: return "Glass";
	case ContainerType::TetraPack: return "Tetra Pack";
	default: return "Unknown";
	}
}


class PackagedWine : public Wine
{
private:
	double pacW_volume;
	ContainerType pacW_package;

public:
	PackagedWine();
	PackagedWine(const string& name, const string& color, const string& swetness, double strength,
	double volume);
	PackagedWine(const PackagedWine& P);
	~PackagedWine();
	virtual void printOn(ostream& os)const override;
	void changePackage();
	PackagedWine operator/(double n);
	double getVolume();
};
