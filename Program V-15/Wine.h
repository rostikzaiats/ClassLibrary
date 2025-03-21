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
	virtual void printOn(ostream& os)const;
	virtual bool checkWine(const string& Parametr)const;
	virtual bool checkWine(double Parametr)const;
    virtual bool operator <(const Wine& other)const;

};
