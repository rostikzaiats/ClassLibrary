#include "Wine.h"

Wine::Wine(): w_name(""), w_color(""), w_swetness(""), w_strength(0.0){}

Wine::Wine(const string& name, const string& color, const string& swetness, double strength)
	: w_name(name), w_color(color), w_swetness(swetness), w_strength(strength){}
                                                                                                                                                                                         
Wine::Wine(const Wine& P) : w_name(P.w_name), w_color(P.w_color), w_swetness(P.w_swetness), 
w_strength(P.w_strength){}

Wine::~Wine(){
}

void Wine::printOn(ostream& os) const
{
	cout << w_name << " (" << w_color << ',' << w_swetness << ") " << w_strength << '%';
}

bool Wine::checkWine(const string& Parametr) const
{
	return Parametr == w_swetness;
}

bool Wine::checkWine(double Parametr) const
{
	return w_strength == Parametr;
}

bool Wine::operator<(const Wine& other) const
{
	return this->w_strength < other.w_strength;
}
