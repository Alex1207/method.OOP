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
			node* Node = mas[i]->next;
			delete mas[i];
			mas[i] = Node;
		}
	}
}
void container::In(ifstream & InFile)
{	
	CheckFileExist(InFile);
	CheckEmptyFile(InFile);
	int K;
	InFile >> K;
	CheckInputValue(InFile);	
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
		Animal = Animal->InAnimal(InFile);
		int Sum = 0;
		Sum = SumElementsOfString(Animal, (n));
		if (mas[Sum] == NULL)
		{
			mas[Sum] = new node;
			mas[Sum]->next = NULL;
			mas[Sum]->nAnimal = Animal;
		}
		else
		{
			node* Node = new node;
			Node->next = mas[Sum];
			Node->nAnimal = Animal;
			mas[Sum] = Node;
		}
	}		
	if(!InFile.eof())
	{
		cout << "После считанных данных в файле есть что-то еще. Эта информация обрабатываться не будет\n";
	}
}
void container::Out(ofstream & OutFile)
{
	//cout << "Общее количество: " << kol << endl;
	OutFile << "Общее количество: " << kol << endl;
	for (int i = 0; i<n; i++)
	{
		OutFile << "\n" << i << "\n";
		if (mas[i] != NULL)
		{
			node* Node = mas[i];
			while (Node)
			{
				Node->nAnimal->OutAnimal(OutFile);
				Node = Node->next;
			}
		}
	}
}
void container::Sort()
{
	for (int k = 0; k<n; k++)
	{
		int Koli = 0;
		node* Prev;
		node* Node = mas[k];
		while(Node)
		{
			Node = Node->next;
			Koli++;
		}
		for(int i = 0; i < Koli - 1; i++) 
		{
			node* Prev;
			Node = mas[k];
			for(int j = i + 1; j < Koli; j++) 
			{
				if(Node->nAnimal->Less(Node->next->nAnimal))
				{
					node* Next = Node->next;
					Node->next = Node->next->next;
					Next->next = Node;
					if(Node == mas[k])
					{
						mas[k] = Next;
						Prev = Next;
					}
					else
					{
						Prev->next = Next;
						Prev = Next;
					}
				}
				else 
				{
					Prev = Node;
					Node = Node->next;
				}
			}
		}
	}
}
void container::OutOnlyFish(ofstream & OutFile)
{
	//cout << "\n\nТолько рыбки:\n";
	OutFile << "\nТолько рыбки:\n";
	for (int i = 0; i<n; i++)
	{
		node* Node = mas[i];
		//cout << "\n" << i << "\n";
		if (mas[i] != NULL)
		{
			node* Node = mas[i];
			while (Node)
			{
				Node->nAnimal->OutFish(OutFile);
				Node = Node->next;
			}
		}
	}
}
int container::SumElementsOfString(animal* Animal, int N)
{
	string Str = Animal->name;
	int Sum = 0;
	for (int i = 0; i < Str.length(); i++)
	{
		Sum = (Sum + (unsigned char)Str[i])%N;
	}
	return Sum;
}