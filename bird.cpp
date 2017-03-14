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
	cout << " - это птичка, которая ";
	f2 << " - это птичка, которая ";
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