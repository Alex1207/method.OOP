#include "stdafx.h"
#include "animal.h"
#include "iostream"
#include <fstream>

using namespace std;
//class node
//{
//public:
//	...
//}
struct node//узел
{
	animal *Animal;
	node* next;
};
class container
{
private:
	int kol;
	int n;
	node** mas;
public:
	container();
	~container(){Del();};
	void Del();
	void In(ifstream & f1);
	void Out(ofstream & f2);
	void Sort();
	void OutOnlyFish(ofstream & f2);
	//int SumElementsOfString(animal* Animal,int n);
};