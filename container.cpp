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
			while (vn)
			{
				vn->Animal->OutAnimal(f2);
				vn = vn->next;
			}
		}
	}
}
void container::MultiMethod(ofstream & f2)
{
	int k = 0;
	cout << "\nМультиметод: " << endl;
	f2 << "\nМультиметод: "  << endl;
	for (int i = 0; i<n; i++)
	{
		//cout << "\n" << i << "\n";
		if (mas[i] != NULL)
		{
			node* vn1 = mas[i];
			while (vn1)
			{
				for (int j = i; j<n; j++)
				{
					node* vn2;
					if (j==i)
						vn2 = vn1->next;
					else
						vn2 = mas[j];
					//cout << "\n" << i << "\n";
					if (mas[i] != NULL)
					{
						//vn2 = mas[i];
						while (vn2)
						{
							k++;
							cout << k << endl;
							vn1->Animal->MultiMethod(vn2->Animal, f2);
							vn1->Animal->OutAnimal(f2);
							vn2->Animal->OutAnimal(f2);
							vn2 = vn2->next;
						}
					}
				}
				vn1 = vn1->next;
			}
		}
	}
}