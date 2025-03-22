#include"..\Program V-15\Wine.h"
#include <iostream>
#include"..\Program V-15\Wine.h"
#include"..\Program V-15\WineBox.h"
#include"..\Program V-15\packagedWine.h"


int main()
{
    std::cout << "Hello World!\n";
    
    Wine wine1("Chardonnay", "White", "Dry", 12.0);
    PackagedWine packagedWine1("Merlot", "Red", "Dry", 14.0, 1.5);
    PackagedWine packagedWine2("Cabernet", "Red", "Sweet", 13.5, 2.0);

    cout << "Wine Information:" << endl;
    wine1.printOn(cout);
    cout << endl;

    cout << "Packaged Wine Information:" << endl;
    packagedWine1.printOn(cout);
    cout << endl;

    packagedWine2.printOn(cout);
    cout << endl;


    packagedWine1.changePackage();
    packagedWine1.printOn(cout);
    cout << endl;

    WineBox wineBox(5);
    wineBox.addW("Chardonnay", "White", "Dry", 12.0, 1.0);
    wineBox.addW("Pinot Noir", "Red", "Dry", 13.0, 1.5);
    wineBox.addW("Sauvignon Blanc", "White", "Sweet", 11.5, 0.75);
    wineBox.addW("Merlot", "Red", "Dry", 14.0, 2.0);

    cout << "All wines in the box:" << endl;
    wineBox.printW(cout);
    cout << endl;


    double strange = 12.;
    double totalVolume = wineBox.totalVolume(strange);
    cout << "Total volume of " << strange << " wines: " << totalVolume << " liters" << endl;

    wineBox.loadFromFile("Wine.txt");

    wineBox.sortByStrenght();
    cout << "Wines sorted by strength:" << endl;
    wineBox.printW(cout);
   


}


