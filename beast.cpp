#include "stdafx.h"
#include "beast.h"
#include <string>
#include "iostream"
#include <fstream>
#include "foolproof.h"

using namespace std;
string groups[3] = {"����������", "������", "��������"};
void beast::In(ifstream &f1)
{	
	CheckFileExist(f1);	
	CheckFileEnd(f1);
	if (!f1)
	{
		cout << "������ ������ �������� �����! ��������, ����� �� ����������.\n";
		system("pause");
		exit(1);
	}
	int G = 3;
	f1 >> G; 
	CheckInputValue(f1);
	if ((G>=0)&&(G<3))
		Group = G;
	else 	
	{
		cout << "�������� ������ �� ������� �����(������ ����� ����� ��������� ������ �������� �� 0 �� 2)!\n";
		system("pause");
		exit(1);
	}
	/*int q;
	f1 >> q; 
	Group = q;*/
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
