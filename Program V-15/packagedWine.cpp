#include "packagedWine.h"

PackagedWine::PackagedWine() : Wine(), pacW_volume(0), pacW_package(GLASS_CONTAINER) {}

PackagedWine::PackagedWine(const string& name, const string& color, const string& swetness,
	double strength, double volume) : Wine(name,color,swetness,strength), pacW_volume(volume),
	pacW_package(GLASS_CONTAINER){}

PackagedWine::PackagedWine(const PackagedWine& P) : Wine(P), pacW_volume(P.pacW_volume),
pacW_package(P.pacW_package) {}

PackagedWine::~PackagedWine()
{
}

void PackagedWine::printOn(ostream& os) const
{
	Wine::printOn(os); cout << '.' << pacW_volume << " in" << pacW_package << " pack.";
}

void PackagedWine::changePackage()
{
	if (this->pacW_package == GLASS_CONTAINER)
	{
		pacW_package = PAKAGE_CONTAINER;
	}
	else if(this->pacW_package == PAKAGE_CONTAINER)
	{
		pacW_package = GLASS_CONTAINER;
	}
	else
	{
		throw("BAD PAKAGE");
	}
}

PackagedWine PackagedWine::operator/(double n)
{
	if (n == 0) { throw("Determinant can't be 0!"); }
  this->pacW_volume = pacW_volume / n;
   return *this;
}

double PackagedWine::getVolume()
{
	return this->pacW_volume;
}
