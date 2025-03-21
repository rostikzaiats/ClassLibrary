#pragma once
#include<string>

using namespace std;

class Wine
{
protected: 
	string name;
	string color;
	string swetness;
	double strength;
private:
	


public:
	Wine();
	~Wine();


};

Wine::Wine()
{
}

Wine::~Wine()
{
}