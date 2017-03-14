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
	for (int i = 0; i<n; i++)
	{
		cout << "\n" << i << "\n";
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
void container::Sort()
{
	for (int k = 0; k<n; k++)
	{
		int koli = 0;
		node* prev;
		node* Node = mas[k];
		while(Node)
		{
			Node = Node->next;
			koli++;
		}
		for(int i = 0; i < koli - 1; i++) 
		{
			node* prev;
			Node = mas[k];
			for(int j = i + 1; j < koli; j++) 
			{
				if(Node->Animal->Less(*Node->next->Animal))
				{
					node* next = Node->next;
					Node->next = Node->next->next;
					next->next = Node;
					if(Node == mas[k])
					{
						mas[k] = next;
						prev = next;
					}
					else
					{
						prev->next = next;
						prev = next;
					}
				}
				else 
				{
					prev = Node;
					Node = Node->next;
				}
			}
		}
	}
}