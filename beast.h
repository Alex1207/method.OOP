#include "stdafx.h"
#include "iostream"
#include <fstream>
#include "animal.h"
using namespace std;
class beast: public animal
{
private:
	//string name;
	int group;//�������������, ����������, �������, ��������
public:
	void In(ifstream &InFile);
	void Out(ofstream &OutFile);
	void SetParam(int Param);//
	int GetParam();
};
