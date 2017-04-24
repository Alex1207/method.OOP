#include "stdafx.h"
#include "animal.h"
#include <string>
#include "iostream"
#include <fstream>
#include "bird.h"
#include "beast.h"
#include "fish.h"
#include "foolproof.h"
using namespace std;

animal* animal::InAnimal( ifstream &InFile)
{
	CheckFileExist(InFile);	
	CheckFileEnd(InFile);
	animal* Animal;
	int Key;
	InFile >> Key;
	CheckInputValue(InFile);
	if (!((Key>=0)&&(Key<3))) 	
	{
		cout << "Неверные данные во входном файле(Вид животного может принимать только значения от 0 до 2)!\n";// << key<<endl;
		system("pause");
		exit(1);
	}
	if (Key == 2)//2-beast
	{
		Animal = new beast;
	}
	if (Key == 1)//1-fish
	{
		Animal = new fish;
	}
	if (Key == 0)//0-bird
	{
		Animal = new bird;
	}
	Animal->In(InFile);
	CheckFileEnd(InFile);
	int Age;
	InFile >> Age;
	CheckInputValue(InFile);
	if (Age<0) 	
	{
		cout << "Неверные данные во входном файле(Возраст животного не может быть отрицательным)!\n";
		system("pause");
		exit(1);
	}
	Animal->age = Age;		
	CheckFileEnd(InFile);
	InFile >> Animal->name;
	return Animal;
}
void animal::OutAnimal(ofstream  &OutFile)
{
	//cout << name;
	OutFile << name;
	Out(OutFile);
	//cout << ", возраст: " << age;
	OutFile <<  ", возраст: " << age;
	//Out(OutFile);	
	//cout << ". Количество символов в имени: " << AmountSymbolsOfString() << "\n";
	OutFile << ". Количество символов в имени: " << AmountSymbolsOfString() << "\n";
}
int  animal::AmountSymbolsOfString()
{
	string Str = name;
	return Str.length();
}
bool animal::Less(animal* Animal2)
{
	return (AmountSymbolsOfString() < Animal2->AmountSymbolsOfString());
}
void animal::OutFish(ofstream & OutFile)
{
	//cout << endl;
	OutFile << endl;
}