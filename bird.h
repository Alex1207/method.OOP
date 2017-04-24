#include "stdafx.h"
#include "iostream"
#include <fstream>
#include "animal.h"

using namespace std;
class bird: public animal
{
private:
	//string name;
	bool migration;
public:
	void In(ifstream &InFile);
	void Out(ofstream &OutFile);
	void SetParam(int Param);//
	int GetParam();
	//int SumElementsOfString(int n);
};
