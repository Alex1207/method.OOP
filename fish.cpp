#include "stdafx.h"
#include "fish.h"
#include <string>
#include "iostream"
#include <fstream>

using namespace std;
string places[6]={"����", "�����", "����", "�����", "����", "��������"};
void fish::In(ifstream &f1)
{
	f1 >> Place; //0 - river, 1 - lake, 2 - sea, 3 - ocean, 4 - pond, 5 - aquarium
	//f1 >> name;
}
void fish::Out(ofstream &f2)
{
	//cout <<  " - ��� �����" << ", ����� �� ��������: " << places[Place];
	f2 <<  " - ��� �����" <<  ", ����� �� ��������: " << places[Place];
}
void fish::OutFish(ofstream & f2)
{
	//cout << name;
	f2 << name;
	//cout <<  " - ��� �����" << ", ����� �� ��������: " << places[Place] << endl;
	f2 <<  " - ��� �����" <<  ", ����� �� ��������: " << places[Place];	
	f2 <<  ", �������: " << age;
	//Out(f2);	
	//cout << ". ���������� �������� � �����: " << AmountSymbolsOfString() << "\n";
	f2 << ". ���������� �������� � �����: " << AmountSymbolsOfString() << "\n";
}
void fish::SetParam(int param)
{
	Place = param;
}
int fish::GetParam()
{
	return Place;
}