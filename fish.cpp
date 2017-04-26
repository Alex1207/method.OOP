#include "stdafx.h"
#include "fish.h"
#include <string>
#include "iostream"
#include <fstream>

using namespace std;
string places[6]={"река", "озеро", "море", "океан", "пруд", "аквариум"};
void fish::In(ifstream &f1)
{
	f1 >> Place; //0 - river, 1 - lake, 2 - sea, 3 - ocean, 4 - pond, 5 - aquarium
	//f1 >> name;
}
void fish::Out(ofstream &f2)
{
	cout <<  " - это рыбка" << ", место ее обитани€: " << places[Place] << "\n";
	f2 <<  " - это рыбка" <<  ", место ее обитани€: " << places[Place] << "\n";
}
void fish::MultiMethod(animal* other, ofstream  &f2)
{
	other->MMFish(f2);
}
void fish::MMFish(ofstream &f2)
{
	cout << "\n–ыбка и рыбка" << endl;
	f2 << "\n–ыбка и рыбка" << endl;
}
void fish::MMBird(ofstream &f2)
{
	cout << "\nѕтичка и рыбка" << endl;
	f2 << "\nѕтичка и рыбка" << endl;
}