#include <string>
#include "stdafx.h"
#include "iostream"
#include <fstream>

using namespace std;
#ifndef __animal__ 
#define __animal__
class animal
{
private:
	//type key;
	//void* object;
	string name;
public:
	static animal* InAnimal(ifstream &f1);
	void OutAnimal(ofstream &f2);
	virtual void In(ifstream  &f1)=0;
	virtual void Out(ofstream  &f2)=0;
	int SumElementsOfString(int n);
};
#endif
