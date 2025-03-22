#include "WineBox.h"

void WineBox::extensions()
{
	wines_capacity *= 2;
	PackagedWine* newWines = new PackagedWine[wines_capacity];
	for (int i = 0; i < wines_number; i++)
	{
		newWines[i] = wines[i];
	}
	delete[] wines;
	wines = newWines;
}

WineBox::WineBox() : wines_number(0), wines_capacity(10)
{
}

WineBox::WineBox(int capacity) :wines_capacity(capacity)
{
	wines= new PackagedWine[capacity];
}

WineBox::WineBox(const WineBox& WB) : wines_number(WB.wines_number), wines_capacity(WB.wines_capacity)
{
	wines = new PackagedWine[WB.wines_capacity];
	for (size_t i = 0; i < WB.wines_number; i++)
	{
		wines[i] = WB.wines[i];
	}
}

WineBox::~WineBox()
{
	delete[] wines;
}

void WineBox::addW(const string& name, const string& color, const string& swetness, double strength, double volume)
{
	if (wines_number > wines_capacity)
	{
		extensions();
	}
	wines[wines_number] = PackagedWine(name, color, swetness, strength, volume);
	wines_number++;
}

void WineBox::loadFromFile(const string& filename)
{
	ifstream file(filename);
	string name, color, swetness;
	double strength, volume;
	while (file >> name >> color >> swetness >> strength >> volume)
	{
		addW(name, color, swetness, strength, volume);
	}
	file.close();
}

void WineBox::sortByStrenght()
{
	for (int i = 0; i < wines_number - 1; i++)
	{
		for (int j = i + 1; j < wines_number; j++)
		{
			if (wines[i] < wines[j])
			{
				swap(wines[i], wines[j]);
			}
		}
   }
}

void WineBox::printW()
{
	for (size_t i = 0; i < wines_number; i++)
	{
		wines[i].printOn(cout); cout << endl;
	}
}

double WineBox::totalVolume(const string& swetness) const
{
	double totalVolume = 0.0;
	for (int i = 0; i < wines_number; i++)
	{
		if (wines[i].checkWine(swetness))
		{
			totalVolume += wines[i].getVolume();
		}
	}
	return totalVolume;
}

double WineBox::totalVolume(double strength) const
{
	double totalVolume = 0.0;
	for (int i = 0; i < wines_number; i++)
	{
		if (wines[i].checkWine(strength))
		{
			totalVolume += wines[i].getVolume();
		}
	}
	return totalVolume;
}