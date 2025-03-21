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
	wines = new PackagedWine[wines_capacity];
}

WineBox::WineBox(int number, int capacity) : wines_number(number) , wines_capacity(capacity)
{
}

WineBox::WineBox(WineBox& WB) : wines_number(WB.wines_number), wines_capacity(WB.wines_capacity)
{
}

WineBox::~WineBox()
{
	delete[] wines;
}

void WineBox::addW(const string& name, const string& color, const string& swetness, double strength, double volume)
{
	if (wines_number > wines_capacity)
	{
		exception();
	}
	wines[wines_number] = PackagedWine(name, color, swetness, strength, volume);
	wines_number++;
}

void WineBox::loadFromFile(const string& filename)
{
	ifstream file(filename);
	string name, color, swetness;
	double strength, volume;
	while (file >> name >> color >> swetness >> strength, volume)
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
	
}

double WineBox::totalVolumeByColor(const string& color) const
{
	return 0.0;
}
