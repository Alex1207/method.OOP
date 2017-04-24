#include "stdafx.h"
#include "bird.h"
#include <string>
#include "iostream"
#include <fstream>
#include "foolproof.h"

using namespace std;

void bird::In(ifstream &f1)
{	
	CheckFileExist(f1);
	CheckFileEnd(f1);
	int M = 0;
	f1 >> M;
	CheckInputValue(f1);
	if ((M == 0) || (M == 1))	
		migration = M;
	else 	
	{
		cout << "Неверные данные во входном файле(миграция птиц может принимать только значения 1 или 0)!\n";
		system("pause");
		exit(1);
	}
}
void bird::Out(ofstream &f2)
{
	//cout << " - это птичка, которая ";
	f2 << " - это птичка, которая ";
	if(migration)
	{
		//cout << "мигрирует";
		f2 << "мигрирует";
	}
	else 
	{
		//cout << "не мигрирует";
		f2 << "не мигрирует";
	}
}
void bird::SetParam(int param)
{
	migration = param;
}
int bird::GetParam()
{
	return migration;
}