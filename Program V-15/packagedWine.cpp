#include "packagedWine.h"

PackagedWine::PackagedWine() : Wine(), pacW_volume(0), pacW_package(GLASS_CONTAINER) {}

PackagedWine::PackagedWine(const string& name, const string& color, const string& swetness,
	double strength, double volume) : Wine(name,color,swetness,strength), pacW_volume(volume),
	pacW_package(GLASS_CONTAINER){}

PackagedWine::PackagedWine(const PackagedWine& P) : Wine(P), pacW_volume(P.pacW_volume),
pacW_package(P.pacW_package) {}

PackagedWine::~PackagedWine()
{}

void PackagedWine::printOn(ostream& os) const
{
	Wine::printOn(os); os << ". " << pacW_volume << "L. in " << pacW_package << " pack.";
}

void PackagedWine::changePackage()
{
	if (pacW_package == GLASS_CONTAINER)
	{
		pacW_package = PAKAGE_CONTAINER;
	}
	else if(pacW_package == PAKAGE_CONTAINER)
	{
		pacW_package = GLASS_CONTAINER;
	}
	else
	{
		throw runtime_error("Invalid package type");
	}
}

PackagedWine PackagedWine::operator/(double n)
{
	if (n == 0) { throw runtime_error("Division by 0"); }
	PackagedWine result(*this); 
	result.pacW_volume /= n;    
	return result;
}

double PackagedWine::getVolume()
{
	return pacW_volume;
}
