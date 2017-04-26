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
public:
	void In(ifstream &f1);
	void Out(ofstream &f2);
	//int SumElementsOfString(int n);
	void MultiMethod(animal* other, ofstream  &f2);
	void MMFish(ofstream &f2);//
	void MMBird(ofstream &f2);//
};