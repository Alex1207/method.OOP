#include "stdafx.h"
#include "fish.h"
#include <string>
#include "iostream"
#include <fstream>
#include "foolproof.h"

using namespace std;
string places[6]={"река", "озеро", "море", "океан", "пруд", "аквариум"};
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
		cout << "Неверные данные во входном файле(место обитания рыбок может принимать только значения от 0 до 5)!\n";
		system("pause");
		exit(1);
	}
	//InFile >> Place; //0 - river, 1 - lake, 2 - sea, 3 - ocean, 4 - pond, 5 - aquarium
	//InFile >> name;
}
void fish::Out(ofstream &OutFile)
{
	//cout <<  " - это рыбка" << ", место ее обитания: " << places[Place];
	OutFile <<  " - это рыбка" <<  ", место ее обитания: " << places[place];
}
void fish::OutFish(ofstream & OutFile)
{
	//cout << name;
	OutFile << name;
	//cout <<  " - это рыбка" << ", место ее обитания: " << places[Place] << endl;
	OutFile <<  " - это рыбка" <<  ", место ее обитания: " << places[place];	
	OutFile <<  ", возраст: " << age;
	//Out(OutFile);	
	//cout << ". Количество символов в имени: " << AmountSymbolsOfString() << "\n";
	OutFile << ". Количество символов в имени: " << AmountSymbolsOfString() << "\n";
}
void fish::SetParam(int Param)
{
	place = Param;
}
int fish::GetParam()
{
	return place;
}