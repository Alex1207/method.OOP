#include "stdafx.h"
#include "iostream"
#include <fstream>
#include "animal.h"

using namespace std;
class bird: public animal
{
private:
	string name;
	bool migration;
public:
	void In(ifstream &f1);
	void Out(ofstream &f2);
	int SumElementsOfString(int n);
};
