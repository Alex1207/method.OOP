#include "stdafx.h"
#include "bird.h"
#include <string>
#include "iostream"
#include <fstream>
#include "foolproof.h"

using namespace std;

void bird::In(ifstream &InFile)
{	
	CheckFileExist(InFile);
	CheckFileEnd(InFile);
	int M = 0;
	InFile >> M;
	CheckInputValue(InFile);
	if ((M == 0) || (M == 1))	
		migration = M;
	else 	
	{
		cout << "�������� ������ �� ������� �����(�������� ���� ����� ��������� ������ �������� 1 ��� 0)!\n";
		system("pause");
		exit(1);
	}
}
void bird::Out(ofstream &OutFile)
{
	//cout << " - ��� ������, ������� ";
	OutFile << " - ��� ������, ������� ";
	if(migration)
	{
		//cout << "���������";
		OutFile << "���������";
	}
	else 
	{
		//cout << "�� ���������";
		OutFile << "�� ���������";
	}
}
void bird::SetParam(int Param)
{
	migration = Param;
}
int bird::GetParam()
{
	return migration;
}