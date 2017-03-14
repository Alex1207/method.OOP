#include "stdafx.h"
#include "beast.h"
#include <string>
#include "iostream"
#include <fstream>

using namespace std;
string groups[3] = {"травоядный", "хищный", "всеядный"};
void beast::In(ifstream &f1)
{
	int q;
	f1 >> q; 
	Group = q + 1;
}
void beast::Out(ofstream &f2)
{
	cout << " - это " << groups[Group - 1] << " звёр";
	f2 << " - это " << groups[Group - 1] << " звёр";
}
