#include "Wine.h"

Wine::Wine(): w_name(""), w_color(""), w_swetness(""), w_strength(0.0){}

Wine::Wine(const string& name, const string& color, const string& swetness, double strength)
	: w_name(name), w_color(color), w_swetness(swetness), w_strength(strength){}

Wine::Wine(const Wine& P) : w_name(P.w_name), w_color(P.w_color), w_swetness(P.w_swetness), 
w_strength(P.w_strength){}

Wine::~Wine(){
}
