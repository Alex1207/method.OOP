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
	Group = q + 1;
}
void beast::Out(ofstream &f2)
{
	cout << " - ��� " << groups[Group - 1] << " ���";
	f2 << " - ��� " << groups[Group - 1] << " ���";
}
