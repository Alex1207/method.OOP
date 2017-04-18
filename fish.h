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
	void OutFish(ofstream & f2);
	void SetParam(int param);//
	int GetParam();
};