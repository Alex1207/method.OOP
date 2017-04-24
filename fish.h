#include "stdafx.h"
#include "iostream"
#include <fstream>
#include "animal.h"
using namespace std;

class fish: public animal
{
private:
	//string name;
	int place;
public:
	void In(ifstream &InFile);
	void Out(ofstream &OutFile);
	void OutFish(ofstream & OutFile);
	void SetParam(int Param);//
	int GetParam();
};