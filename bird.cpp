#include "stdafx.h"
#include "bird.h"
#include <string>
#include "iostream"
#include <fstream>

using namespace std;

void bird::In(ifstream &f1)
{
	f1 >> migration; 
}
void bird::Out(ofstream &f2)
{
	cout << " - это птичка, котора€ ";
	f2 << " - это птичка, котора€ ";
	if(migration)
	{
		cout << "мигрирует\n";
		f2 << "мигрирует\n";
	}
	else 
	{
		cout << "не мигрирует\n";
		f2 << "не мигрирует\n";
	}
}
void bird::MultiMethod(animal* other, ofstream  &f2)
{
	other->MMBird(f2);
}
void bird::MMFish(ofstream &f2)
{
	cout << "\n–ыбка и птичка" << endl;
	f2 << "\n–ыбка и птичка" << endl;
}
void bird::MMBird(ofstream &f2)
{
	cout << "\nѕтичка и птичка" << endl;
	f2 << "\nѕтичка и птичка" << endl;
}