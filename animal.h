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
	static animal* InAnimal(ifstream &InFile);
	void OutAnimal(ofstream &OutFile);
	virtual void In(ifstream  &InFile) = 0;
	virtual void Out(ofstream  &OutFile) = 0;
	int AmountSymbolsOfString();	
	bool Less(animal* Animal2);
	virtual void OutFish(ofstream &OutFile);
	virtual int GetParam() = 0;
	virtual void SetParam(int Param) = 0;
};
#endif
