#include "stdafx.h"
#include "fish.h"
#include <string>
#include "iostream"
#include <fstream>
#include "foolproof.h"

using namespace std;
string places[6]={"����", "�����", "����", "�����", "����", "��������"};
void fish::In(ifstream &InFile)
{
	CheckFileExist(InFile);
	CheckFileEnd(InFile);
	int Place = 6;
	InFile >> Place; //0 - river, 1 - lake, 2 - sea, 3 - ocean, 4 - pond, 5 - aquarium
	//InFile >> F->name;
	CheckInputValue(InFile);
	if ((Place>=0)&&(Place<6))
		place = Place;
	else
	{
		cout << "�������� ������ �� ������� �����(����� �������� ����� ����� ��������� ������ �������� �� 0 �� 5)!\n";
		system("pause");
		exit(1);
	}
	//InFile >> Place; //0 - river, 1 - lake, 2 - sea, 3 - ocean, 4 - pond, 5 - aquarium
	//InFile >> name;
}
void fish::Out(ofstream &OutFile)
{
	//cout <<  " - ��� �����" << ", ����� �� ��������: " << places[Place];
	OutFile <<  " - ��� �����" <<  ", ����� �� ��������: " << places[place];
}
void fish::OutFish(ofstream & OutFile)
{
	//cout << name;
	OutFile << name;
	//cout <<  " - ��� �����" << ", ����� �� ��������: " << places[Place] << endl;
	OutFile <<  " - ��� �����" <<  ", ����� �� ��������: " << places[place];	
	OutFile <<  ", �������: " << age;
	//Out(OutFile);	
	//cout << ". ���������� �������� � �����: " << AmountSymbolsOfString() << "\n";
	OutFile << ". ���������� �������� � �����: " << AmountSymbolsOfString() << "\n";
}
void fish::SetParam(int Param)
{
	place = Param;
}
int fish::GetParam()
{
	return place;
}