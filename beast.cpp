#include "stdafx.h"
#include "beast.h"
#include <string>
#include "iostream"
#include <fstream>
#include "foolproof.h"

using namespace std;
string groups[3] = {"����������", "������", "��������"};
void beast::In(ifstream &InFile)
{	
	CheckFileExist(InFile);	
	CheckFileEnd(InFile);
	if (!InFile)
	{
		cout << "������ ������ �������� �����! ��������, ����� �� ����������.\n";
		system("pause");
		exit(1);
	}
	int G = 3;
	InFile >> G; 
	CheckInputValue(InFile);
	if ((G>=0)&&(G<3))
		group = G;
	else 	
	{
		cout << "�������� ������ �� ������� �����(������ ����� ����� ��������� ������ �������� �� 0 �� 2)!\n";
		system("pause");
		exit(1);
	}
	/*int q;
	InFile >> q; 
	Group = q;*/
}
void beast::SetParam(int Param)
{
	group = Param;
}
int beast::GetParam()
{
	return group;
}
void beast::Out(ofstream &OutFile)
{
	//cout << " - ��� " << groups[Group] << " ���";
	OutFile << " - ��� " << groups[group] << " ���";
}
void beast::MultiMethod(animal* Other, ofstream  &OutFile)
{
	Other->MMBeast(OutFile);
}
void beast::MMFish(ofstream &OutFile)
{
	//cout << "\n����� � ���" << endl;
	OutFile << "\n����� � ���" << endl;
}
void beast::MMBird(ofstream &OutFile)
{
	//cout << "\n������ � ���" << endl;
	OutFile << "\n������ � ���" << endl;
}
void beast::MMBeast(ofstream &OutFile)
{
	//cout << "\n��� � ���" << endl;
	OutFile << "\n��� � ���" << endl;
}
