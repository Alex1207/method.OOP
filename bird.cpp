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
		cout << "Неверные данные во входном файле(миграция птиц может принимать только значения 1 или 0)!\n";
		system("pause");
		exit(1);
	}
}
void bird::Out(ofstream &OutFile)
{
	//cout << " - это птичка, которая ";
	OutFile << " - это птичка, которая ";
	if(migration)
	{
		//cout << "мигрирует";
		OutFile << "мигрирует";
	}
	else 
	{
		//cout << "не мигрирует";
		OutFile << "не мигрирует";
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
void bird::MultiMethod(animal* Other, ofstream  &OutFile)
{
	Other->MMBird(OutFile);
}
void bird::MMFish(ofstream &OutFile)
{
	//cout << "\nРыбка и птичка" << endl;
	OutFile << "\nРыбка и птичка" << endl;
}
void bird::MMBird(ofstream &OutFile)
{
	//cout << "\nПтичка и птичка" << endl;
	OutFile << "\nПтичка и птичка" << endl;
}
void bird::MMBeast(ofstream &OutFile)
{
	//cout << "\nЗвёр и птичка" << endl;
	OutFile << "\nЗвёр и птичка" << endl;
}