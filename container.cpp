#include "stdafx.h"
#include "container.h"
#include "animal.h"
#include "iostream"
#include <fstream>

using namespace std;
container::container()
{
	kol = 0;
	n = 10;
	mas = new node*[n];
	for (int i = 0; i < n; i++)
	{
		mas[i] = NULL;
	}
}
void container::Del()
{
	for (int i = 0; i<n; i++)
	{
		while (mas[i] != NULL)
		{
			node* vn = mas[i]->next;
			delete mas[i];
			mas[i] = vn;
		}
	}
}
void container::In(ifstream & f1)
{	
	f1 >> kol;
	for (int i = 0; i<kol; i++)
	{
		animal *Animal;
		Animal = Animal->InAnimal(f1);
		int sum = 0;
		sum = Animal->SumElementsOfString(n);
		if (mas[sum] == NULL)
		{
			mas[sum] = new node;
			mas[sum]->next = NULL;
			mas[sum]->Animal = Animal;
		}
		else
		{
			node* vn = new node;
			vn->next = mas[sum];
			vn->Animal = Animal;
			mas[sum] = vn;
		}
	}	
}
void container::Out(ofstream & f2)
{
	cout << "Общее количество: " << kol << endl;
	f2 << "Общее количество: " << kol << endl;
	for (int i = 0; i<n; i++)
	{
		//cout << "\n" << i << "\n";
		if (mas[i] != NULL)
		{
			node* vn = mas[i];
			while (mas[i])
			{
				mas[i]->Animal->OutAnimal(f2);
				mas[i] = mas[i]->next;
			}
		}
	}
}