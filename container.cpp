#include "stdafx.h"
#include "container.h"
#include "animal.h"
#include "iostream"
#include <fstream>
#include "foolproof.h"

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
	kol = 0;
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
	CheckFileExist(f1);
	CheckEmptyFile(f1);
	int K;
	f1 >> K;
	CheckInputValue(f1);	
	if (K<0) 	
	{
		cout << "Неверные данные во входном файле(Количество животных не может быть отрицательным)!\n";
		system("pause");
		exit(1);
	}
	kol = K;
	for (int i = 0; i<kol; i++)
	{
		animal *Animal;
		Animal = Animal->InAnimal(f1);
		int sum = 0;
		sum = SumElementsOfString(Animal, (n));
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
	if(!f1.eof())
	{
		cout << "После считанных данных в файле есть что-то еще. Эта информация обрабатываться не будет\n";
	}
}
void container::Out(ofstream & f2)
{
	//cout << "Общее количество: " << kol << endl;
	f2 << "Общее количество: " << kol << endl;
	for (int i = 0; i<n; i++)
	{
		f2 << "\n" << i << "\n";
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
				if(Node->Animal->Less(Node->next->Animal))
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
void container::OutOnlyFish(ofstream & f2)
{
	//cout << "\n\nТолько рыбки:\n";
	f2 << "\nТолько рыбки:\n";
	for (int i = 0; i<n; i++)
	{
		node* vn = mas[i];
		//cout << "\n" << i << "\n";
		if (mas[i] != NULL)
		{
			node* vn = mas[i];
			while (vn)
			{
				vn->Animal->OutFish(f2);
				vn = vn->next;
			}
		}
	}
}
int container::SumElementsOfString(animal* Animal, int n)
{
	string str = Animal->name;
	int sum = 0;
	for (int i = 0; i < str.length(); i++)
	{
		sum = (sum + (unsigned char)str[i])%n;
	}
	return sum;
}