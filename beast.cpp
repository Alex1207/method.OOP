#include "stdafx.h"
#include "beast.h"
#include <string>
#include "iostream"
#include <fstream>

using namespace std;
string groups[3] = {"����������", "������", "��������"};
void beast::In(ifstream &f1)
{
	int q;
	f1 >> q; 
	Group = q;
}
void beast::SetParam(int param)
{
	Group = param;
}
int beast::GetParam()
{
	return Group;
}
void beast::Out(ofstream &f2)
{
	//cout << " - ��� " << groups[Group] << " ���";
	f2 << " - ��� " << groups[Group] << " ���";
}
