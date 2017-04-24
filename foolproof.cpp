#include "stdafx.h"
//#include "iostream"
//#include <fstream>
#include "foolproof.h"

void CheckFileExist(ifstream &InFile)
{
	if (!InFile)
	{
		cout << "������ ������ �������� �����! ��������, ����� �� ����������.\n";
		system("pause");
		exit(1);
	}
}
void CheckEmptyFile(ifstream &InFile)
{
	InFile.seekg (0, std::ios::end);
	int file_size = InFile.tellg();
	InFile.seekg (0, std::ios::beg);
	if (file_size == 0)	
	{
		cout << "������ ������ �������� �����! ���� ����.\n";
		system("pause");
		exit(1);
	}
}
void CheckFileEnd(ifstream &InFile)
{
	if(InFile.eof())
	{
		cout << "������ ������ �������� �����! ����������� ����� �����.\n";
		system("pause");
		exit(1);
	}
}
void CheckInputValue(ifstream &InFile)
{
	if(InFile.fail())
	{
		cout << "������ ������ �������� �����! ������� ������������ ��������.\n" << endl;
		system("pause");
		exit(1);
	}
}