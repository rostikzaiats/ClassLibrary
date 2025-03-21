#pragma once
#include<iostream>
#include<string>

using namespace std;

class Wine
{
protected: 
	string w_name;
	string w_color;
	string w_swetness;
	double w_strength;
private:
	
public:
	Wine();
	Wine(const string& name, const string& color, const string& swetness, double strength);
	Wine(const Wine& P);
	virtual ~Wine();

	bool checkWine(const string& is_wine)const;

	bool operator <(const Wine& other)const;

	void printON(ostream& os)const;
};
