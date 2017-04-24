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

animal* animal::InAnimal( ifstream &f1)
{
	CheckFileExist(f1);	
	CheckFileEnd(f1);
	animal* Animal;
	int key;
	f1 >> key;
	CheckInputValue(f1);
	if (!((key>=0)&&(key<3))) 	
	{
		cout << "�������� ������ �� ������� �����(��� ��������� ����� ��������� ������ �������� �� 0 �� 2)!\n";// << key<<endl;
		system("pause");
		exit(1);
	}
	if (key == 2)//2-beast
	{
		Animal = new beast;
	}
	if (key == 1)//1-fish
	{
		Animal = new fish;
	}
	if (key == 0)//0-bird
	{
		Animal = new bird;
	}
	Animal->In(f1);
	CheckFileEnd(f1);
	int age;
	f1 >> age;
	CheckInputValue(f1);
	if (age<0) 	
	{
		cout << "�������� ������ �� ������� �����(������� ��������� �� ����� ���� �������������)!\n";
		system("pause");
		exit(1);
	}
	Animal->age = age;		
	CheckFileEnd(f1);
	f1 >> Animal->name;
	return Animal;
}
void animal::OutAnimal(ofstream  &f2)
{
	//cout << name;
	f2 << name;
	Out(f2);
	//cout << ", �������: " << age;
	f2 <<  ", �������: " << age;
	//Out(f2);	
	//cout << ". ���������� �������� � �����: " << AmountSymbolsOfString() << "\n";
	f2 << ". ���������� �������� � �����: " << AmountSymbolsOfString() << "\n";
}
int  animal::AmountSymbolsOfString()
{
	string str = name;
	return str.length();
}
bool animal::Less(animal* Animal2)
{
	return (AmountSymbolsOfString() < Animal2->AmountSymbolsOfString());
}
void animal::OutFish(ofstream & f2)
{
	//cout << endl;
	f2 << endl;
}