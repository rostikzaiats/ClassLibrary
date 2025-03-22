#pragma once
#include "Wine.h"
#include "packagedWine.h"
#include <iostream>
#include <fstream>

class WineBox
{
private: 
	PackagedWine* wines;
	int wines_number;
	int wines_capacity;

	void extensions();

public:
	WineBox();
	WineBox(int capacity);
	WineBox(const WineBox& WB);
	~WineBox();

	void addW(const string& name, const string& color, const string& swetness, double strength, double volume);
	void loadFromFile(const string& filename);
	void sortByStrenght();
	void printW(ostream& os);
	double totalVolume(const string& swetness) const;
	double totalVolume(double strength) const;


};