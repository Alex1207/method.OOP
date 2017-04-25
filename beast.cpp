#include "stdafx.h"
#include "beast.h"
#include <string>
#include "iostream"
#include <fstream>
#include "foolproof.h"

using namespace std;
string groups[3] = {"травоядный", "хищный", "всеядный"};
void beast::In(ifstream &InFile)
{	
	CheckFileExist(InFile);	
	CheckFileEnd(InFile);
	if (!InFile)
	{
		cout << "Ошибка чтения входного файла! Возможно, файла не существует.\n";
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
		cout << "Неверные данные во входном файле(Группа зверя может принимать только значения от 0 до 2)!\n";
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
	//cout << " - это " << groups[Group] << " звёр";
	OutFile << " - это " << groups[group] << " звёр";
}
void beast::MultiMethod(animal* Other, ofstream  &OutFile)
{
	Other->MMBeast(OutFile);
}
void beast::MMFish(ofstream &OutFile)
{
	//cout << "\nРыбка и звёр" << endl;
	OutFile << "\nРыбка и звёр" << endl;
}
void beast::MMBird(ofstream &OutFile)
{
	//cout << "\nПтичка и звёр" << endl;
	OutFile << "\nПтичка и звёр" << endl;
}
void beast::MMBeast(ofstream &OutFile)
{
	//cout << "\nЗвёр и звёр" << endl;
	OutFile << "\nЗвёр и звёр" << endl;
}
