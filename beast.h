#include "stdafx.h"
#include "iostream"
#include <fstream>
#include "animal.h"
using namespace std;
class beast: public animal
{
private:
	//string name;
	int Group;//млекопитающие, траво€дные, хищники, все€дные
public:
	void In(ifstream &f1);
	void Out(ofstream &f2);
};
