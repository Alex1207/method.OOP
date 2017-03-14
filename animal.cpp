#include "stdafx.h"
#include "animal.h"
#include <string>
#include "iostream"
#include <fstream>
#include "bird.h"
#include "fish.h"
using namespace std;
int animal::SumElementsOfString(int n)
{
	string str = name;
	int sum = 0;
	for (int i = 0; i < str.length(); i++)
	{
		sum = (sum + (unsigned char)str[i])%n;
	}
	return sum;
}
animal* animal::InAnimal( ifstream &f1)
{
	animal* Animal;
	int key;
	f1 >> key;
	if (key == 1)//1-fish
	{
		Animal = new fish;
	}
	if (key == 0)//0-bird
	{
		Animal = new bird;
	}
	Animal->In(f1);
	f1 >> Animal->name;
	return Animal;
}
void animal::OutAnimal(ofstream  &f2)
{
	cout << name;
	f2 << name;
	Out(f2);	
	cout << ". Количество символов в имени: " << AmountSymbolsOfString() << "\n";
	f2 << ". Количество символов в имени: " << AmountSymbolsOfString() << "\n";
}
int  animal::AmountSymbolsOfString()
{
	string str = name;
	return str.length();
}
bool animal::Less(animal &Animal2)
{
	return (AmountSymbolsOfString() > Animal2.AmountSymbolsOfString());
}