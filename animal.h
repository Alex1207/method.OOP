#include <string>
#include "stdafx.h"
#include "iostream"
#include <fstream>

using namespace std;
#ifndef __animal__ 
#define __animal__
class animal
{
public://private:
	int age;
public:
	string name;
public:
	static animal* InAnimal(ifstream &f1);
	void OutAnimal(ofstream &f2);
	virtual void In(ifstream  &f1) = 0;
	virtual void Out(ofstream  &f2) = 0;
	int AmountSymbolsOfString();	
	bool Less(animal* Animal2);
	virtual void OutFish(ofstream & f2);
	virtual int GetParam() = 0;
	virtual void SetParam(int param) = 0;
};
#endif
