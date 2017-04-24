#include "stdafx.h"
#include "iostream"
#include <fstream>
#include "animal.h"
using namespace std;
class beast: public animal
{
private:
	//string name;
	int group;//млекопитающие, траво€дные, хищники, все€дные
public:
	void In(ifstream &InFile);
	void Out(ofstream &OutFile);
	void SetParam(int Param);//
	int GetParam();
};
