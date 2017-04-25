#include "stdafx.h"
#include "animal.h"
#include "iostream"
#include <fstream>

using namespace std;
struct node//узел
{
	animal *nAnimal;
	node* next;
};
class container
{
public://private:
	int kol;
	int n;
	node** mas;
public:
	container();
	~container(){Del();};
	int SumElementsOfString(animal* Animal, int N);
	void Del();
	void In(ifstream & InFile);
	void Out(ofstream & OutFile);
	void Sort();
	void OutOnlyFish(ofstream & OutFile);
	void MultiMethod(ofstream  &OutFile);
};