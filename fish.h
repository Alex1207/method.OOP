#include "stdafx.h"
#include "iostream"
#include <fstream>
#include "animal.h"
using namespace std;

class fish: public animal
{
private:
	//string name;
	int Place;
	//Enumerated type would be clearer here.
public:
	void In(ifstream &f1);
	void Out(ofstream &f2);
	//int SumElementsOfString(int n); 
	void OutFish(ofstream & f2);
};