// ��������� �� ����� ������ � ������������ �� � ������ ���� � ����� �������� ����(����������� �����)
//+������������
#include "stdafx.h"
#include <Windows.h>
#include "iostream"
#include <fstream>
#include <string>
#include <clocale>
#include "container.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{	
	setlocale(LC_ALL,"rus");
	if (argc!=3) 
	{
		cout << "������� ������������ ���������� ����������!!!\n������� � �������: <���_������������_�����> <���_��������_�����> <���_���������_�����>";
		return 0;
	}
	ifstream InFile(argv[1]);
	container mas;
	mas.In(InFile);
	ofstream OutFile(argv[2]);
	mas.Sort();
	mas.Out(OutFile);
	mas.OutOnlyFish(OutFile);
	mas.MultiMethod(OutFile);
	mas.Del();
	system("pause");
	return 0;
}

