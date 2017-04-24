// UnitTest.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "gtest/gtest.h"
#include "..\3(5).OOP\animal.h"
#include <string>
#include "iostream"
#include <fstream>
#include "..\3(5).OOP\bird.h"
#include "..\3(5).OOP\beast.h"
#include "..\3(5).OOP\fish.h"
#include "..\3(5).OOP\container.h"
#include <Windows.h>
#include <clocale>

using namespace std;
bool FileCompare(ifstream &f1, ifstream &f2)
{
	string s1;
	string s2;
	bool flag = true;
	int i = 0;
	while ((!f1.eof())||(!f2.eof())) 
	{ 
		i++;
		getline(f1,s1); 
		getline(f2,s2); 
		if (s1 != s2)
		{
			cout << i << "\n" << s1 << "\n" << s2 << "\n";
			return false;
		}
	}
	return true;
}

class CBirdTest : public ::testing::Test 
{
};
TEST_F(CBirdTest, CheckBirdIn) //
{
	ifstream f1("InBird.txt");
	bird Bird;
	Bird.In(f1);
	f1.close();
	ASSERT_TRUE(Bird.GetParam() == 1) << "Bird input test was failed!!";
}
TEST_F(CBirdTest, CheckBirdOut) //
{
	bird Bird;
	Bird.SetParam(1);
	ofstream f2("aOutBird.txt");
	Bird.Out(f2);
	f2.close();
	ifstream actual("aOutBird.txt");
	ifstream expect("eOutBird.txt");
	EXPECT_TRUE(FileCompare(actual, expect)) << "Bird output test was failed!!";
	actual.close();
	expect.close();
}

class CFishTest : public ::testing::Test 
{
};
TEST_F(CFishTest, CheckFishIn) //
{	
	ifstream f1("InFish.txt");
	fish Fish;
	Fish.In(f1);
	f1.close();
	ASSERT_TRUE(Fish.GetParam() == 2) << "Fish input test was failed!!";
}
TEST_F(CFishTest, CheckFishOut) //
{
	fish Fish;
	Fish.SetParam(1);
	ofstream f2("aOutFish.txt");
	Fish.Out(f2);
	f2.close();
	ifstream actual("aOutFish.txt");
	ifstream expect("eOutFish.txt");
	EXPECT_TRUE(FileCompare(actual, expect)) << "Fish output test was failed!!";
	actual.close();
	expect.close();
}
TEST_F(CFishTest, CheckOnlyFishOut) //
{
	fish Fish;
	Fish.SetParam(1);
	Fish.name = "лещ";
	Fish.age = 4;
	Fish.SetParam(1);
	ofstream f2("aOutOnlyFish.txt");
	Fish.OutFish(f2);
	f2.close();
	ifstream actual("aOutOnlyFish.txt");
	ifstream expect("eOutOnlyFish.txt");
	EXPECT_TRUE(FileCompare(actual, expect)) << "Only fish output test was failed!!";
	actual.close();
	expect.close();
}

class CBeastTest : public ::testing::Test 
{
};
TEST_F(CBeastTest, CheckBeastIn) //
{	
	ifstream f1("InBeast.txt");
	beast Beast;
	Beast.In(f1);
	f1.close();
	ASSERT_TRUE(Beast.GetParam() == 2) << "Beast input test was failed!!";
}
TEST_F(CBeastTest, CheckBeastOut) //
{
	beast Beast;
	Beast.SetParam(1);
	ofstream f2("aOutBeast.txt");
	Beast.Out(f2);
	f2.close();
	ifstream actual("aOutBeast.txt");
	ifstream expect("eOutBeast.txt");
	EXPECT_TRUE(FileCompare(actual, expect)) << "Beast output test was failed!!";
	actual.close();
	expect.close();
}

bool AnimalCompare(animal* a1, animal* a2)
{
	return((a1->age == a2->age)&&(a1->name == a2->name)&&(a1->GetParam() == a2->GetParam()));
}

animal* NewInAnimal(int key, int age, string name, int param)
{
	animal* Animal;
	if (key == 0)
	{		
		Animal = new bird;
	}
	if (key == 1)
	{		
		Animal = new fish;
	}
	if (key == 2)
	{
		Animal = new beast;
	}
	Animal->SetParam(param);
	Animal->age = age; 
	Animal->name = name;
	return Animal;
}
class CAnimalTest : public ::testing::Test 
{
};
TEST_F(CAnimalTest, CheckAnimalIn) //
{
	animal *actual;
	animal *expect;
	ifstream f1("InAnimalBird.txt");
	actual = actual->InAnimal(f1);
	f1.close();
	expect = NewInAnimal(0, 5, "клест", 1);
	EXPECT_TRUE(AnimalCompare(actual, expect)) << "Animal(Bird) input test was failed!!";

	ifstream f2("InAnimalFish.txt");
	actual = actual->InAnimal(f2);
	f2.close();
	expect = NewInAnimal(1, 13, "лещ", 3);
	EXPECT_TRUE(AnimalCompare(actual, expect)) << "Animal(Fish) input test was failed!!";

	ifstream f3("InAnimalBeast.txt");
	actual = actual->InAnimal(f3);
	f3.close();
	expect = NewInAnimal(2, 21, "человек", 2);
	EXPECT_TRUE(AnimalCompare(actual, expect)) << "Animal(Beast) input test was failed!!";
}
TEST_F(CAnimalTest, CheckAnimalOut) //
{
	animal *Animal;
	Animal = NewInAnimal(0, 5, "клест", 1);
	ofstream f1("aOutAnimalBird.txt");
	Animal->OutAnimal(f1);
	f1.close();
	ifstream actual1("aOutAnimalBird.txt");
	ifstream expect1("eOutAnimalBird.txt");
	EXPECT_TRUE(FileCompare(actual1, expect1)) << "Animal(Bird) output test was failed!!";
	actual1.close();
	expect1.close();

	Animal = NewInAnimal(1, 1, "лещ", 3);
	ofstream f2("aOutAnimalFish.txt");
	Animal->OutAnimal(f2);
	f2.close();
	ifstream actual2("aOutAnimalBird.txt");
	ifstream expect2("eOutAnimalBird.txt");
	EXPECT_TRUE(FileCompare(actual2, expect2)) << "Animal(Fish) output test was failed!!";
	actual2.close();
	expect2.close();

	Animal = NewInAnimal(2, 21, "человек", 2);
	ofstream f3("aOutAnimalBeast.txt");
	Animal->OutAnimal(f3);
	f3.close();
	ifstream actual3("aOutAnimalBeast.txt");
	ifstream expect3("eOutAnimalBeast.txt");
	EXPECT_TRUE(FileCompare(actual3, expect3)) << "Animal(Beast) output test was failed!!";
}
TEST_F(CAnimalTest, CheckAnimalAmountSymbolsOfString) //
{
	animal* Animal;
	Animal = new fish;
	Animal->name = "";
	EXPECT_TRUE(Animal->AmountSymbolsOfString() == 0) << "Animal amount symbols of string (empty string) test was failed!!";
	Animal->name = "лосось";
	EXPECT_TRUE(Animal->AmountSymbolsOfString() == 6) << "Animal amount symbols of string test was failed!!";
}
TEST_F(CAnimalTest, CheckAnimalLess) //
{
	animal* Animal1;
	Animal1 = new fish;
	Animal1->name = "лось";
	EXPECT_TRUE(Animal1->Less(Animal1) == false) << "Animal compare(a=b) test was failed!!";	
	animal* Animal2;
	Animal2 = new beast;
	Animal2->name = "лебедь";
	EXPECT_TRUE(Animal1->Less(Animal2) == true) << "Animal compare(a<b) test was failed!!";
	EXPECT_TRUE(Animal2->Less(Animal1) == false) << "Animal compare(a>b) test was failed!!";
}

class CContainerTest : public ::testing::Test 
{
};
void EmptyContainer(container &c)
{
	c.kol = 0;
	c.n = 10;
	c.mas = new node*[c.n];
	for (int i = 0; i < c.n; i++)
		c.mas[i] = NULL;
}
bool ContainerCompare(container c1, container c2)
{
	//system("pause");
	if (c1.n != c2.n)
	{
		cout << "N\n\n\n";
		return false;
	}
	if (c1.kol != c2.kol)
	{
		//system("pause");
		cout << "KOL\n\n\n";
		return false;
	}
	for (int i = 0; i < c1.n; i++)
	{
		if ((c1.mas[i] != NULL)^(c2.mas[i] != NULL))
		{
			cout << "NULL\n"<<i<<"\n\n";
			return false;
		}
		if ((c1.mas[i] != NULL)||(c2.mas[i] != NULL))
		{
			node* vn1 = c1.mas[i];
			node* vn2 = c2.mas[i];
			while (vn1 || vn2)
			{
				if ((vn1 != NULL)^(vn2 != NULL))
					return false;
				if (!(AnimalCompare(vn1->nAnimal, vn2->nAnimal)))
				{
					cout << "ANI\n\n\n";
					return false;
				}
				vn1 = vn1->next;
				vn2 = vn2->next;
			}
		}
	}
	return true;
}
void ExpectContainer1(container &c)
{
	c.kol = 10;
	animal* Animal;
	node* vn;

	c.mas[0] = new node;
	Animal = NewInAnimal(0, 2, "голубь", 0);	
	c.mas[0]->nAnimal = Animal; c.mas[0]->next = NULL;
	vn = new node;
	vn->next = c.mas[0]; Animal = NewInAnimal(1, 3, "осетр", 0); vn->nAnimal = Animal; c.mas[0] = vn;
	vn = new node;
	vn->next = c.mas[0]; Animal = NewInAnimal(0, 7, "кукушка", 0); vn->nAnimal = Animal; c.mas[0] = vn;

	c.mas[1] = new node;
	Animal = NewInAnimal(0, 5, "клест", 1);
	c.mas[1]->nAnimal = Animal; c.mas[1]->next = NULL;
	vn = new node;
	vn->next = c.mas[1]; Animal = NewInAnimal(2, 1, "слон", 0); vn->nAnimal = Animal; c.mas[1] = vn;
	vn = new node;
	vn->next = c.mas[1]; Animal = NewInAnimal(2, 9, "тигр", 1); vn->nAnimal = Animal; c.mas[1] = vn;

	//c.mas[2] = NULL;

	c.mas[3] = new node;
	Animal = NewInAnimal(1, 13, "лещ", 3);
	c.mas[3]->nAnimal = Animal; c.mas[3]->next = NULL;

	//c.mas[4] = NULL;
	//c.mas[5] = NULL;
	//c.mas[6] = NULL;
	//c.mas[7] = NULL;

	c.mas[8] = new node;
	Animal = NewInAnimal(2, 21, "человек", 2);
	c.mas[8]->nAnimal = Animal; c.mas[8]->next = NULL;
	vn = new node;
	vn->next = c.mas[8]; Animal = NewInAnimal(1, 4, "язь", 3); vn->nAnimal = Animal; c.mas[8] = vn;
	vn = new node;
	vn->next = c.mas[8]; Animal = NewInAnimal(1, 6, "форель", 1); vn->nAnimal = Animal; c.mas[8] = vn;

	//c.mas[9] = NULL;
}
void ExpectContainer2(container &c)
{
	c.kol = 15;
	animal* Animal;
	node* vn;

	c.mas[0] = new node;
	Animal = NewInAnimal(0, 2, "голубь", 0);	
	c.mas[0]->nAnimal = Animal; c.mas[0]->next = NULL;
	vn = new node;
	vn->next = c.mas[0]; Animal = NewInAnimal(1, 3, "осетр", 0); vn->nAnimal = Animal; c.mas[0] = vn;
	vn = new node;
	vn->next = c.mas[0]; Animal = NewInAnimal(0, 7, "кукушка", 0); vn->nAnimal = Animal; c.mas[0] = vn;
	vn = new node;
	vn->next = c.mas[0]; Animal = NewInAnimal(0, 7, "журавль", 1); vn->nAnimal = Animal; c.mas[0] = vn;

	c.mas[1] = new node;
	Animal = NewInAnimal(0, 5, "клест", 1);
	c.mas[1]->nAnimal = Animal; c.mas[1]->next = NULL;
	vn = new node;
	vn->next = c.mas[1]; Animal = NewInAnimal(2, 1, "слон", 0); vn->nAnimal = Animal; c.mas[1] = vn;
	vn = new node;
	vn->next = c.mas[1]; Animal = NewInAnimal(2, 9, "тигр", 1); vn->nAnimal = Animal; c.mas[1] = vn;
	vn = new node;
	vn->next = c.mas[1]; Animal = NewInAnimal(2, 8, "змея", 1); vn->nAnimal = Animal; c.mas[1] = vn;

	//c.mas[2] = NULL;

	c.mas[3] = new node;
	Animal = NewInAnimal(1, 13, "лещ", 3);
	c.mas[3]->nAnimal = Animal; c.mas[3]->next = NULL;

	c.mas[4] = new node;
	Animal = NewInAnimal(2, 5, "кот", 1);
	c.mas[4]->nAnimal = Animal; c.mas[4]->next = NULL;
	//c.mas[5] = NULL;
	//c.mas[6] = NULL;
	//c.mas[7] = NULL;

	c.mas[8] = new node;
	Animal = NewInAnimal(2, 21, "человек", 2);
	c.mas[8]->nAnimal = Animal; c.mas[8]->next = NULL;
	vn = new node;
	vn->next = c.mas[8]; Animal = NewInAnimal(1, 4, "язь", 3); vn->nAnimal = Animal; c.mas[8] = vn;
	vn = new node;
	vn->next = c.mas[8]; Animal = NewInAnimal(1, 6, "форель", 1); vn->nAnimal = Animal; c.mas[8] = vn;

	c.mas[9] = new node;
	Animal = NewInAnimal(1, 10, "пескарь", 4);
	c.mas[9]->nAnimal = Animal; c.mas[9]->next = NULL;
	vn = new node;
	vn->next = c.mas[9]; Animal = NewInAnimal(0, 2, "дятел", 1); vn->nAnimal = Animal; c.mas[9] = vn;
}
void ExpectContainer1Sort(container &c)
{
	c.kol = 10;
	animal* Animal;
	node* vn;

	c.mas[0] = new node;
	Animal = NewInAnimal(1, 3, "осетр", 0);	
	c.mas[0]->nAnimal = Animal; c.mas[0]->next = NULL;
	vn = new node;
	vn->next = c.mas[0]; Animal = NewInAnimal(0, 2, "голубь", 0); vn->nAnimal = Animal; c.mas[0] = vn;
	vn = new node;
	vn->next = c.mas[0]; Animal = NewInAnimal(0, 7, "кукушка", 0); vn->nAnimal = Animal; c.mas[0] = vn;

	c.mas[1] = new node;
	Animal = NewInAnimal(2, 1, "слон", 0);
	c.mas[1]->nAnimal = Animal; c.mas[1]->next = NULL;
	vn = new node;
	vn->next = c.mas[1]; Animal = NewInAnimal(2, 9, "тигр", 1); vn->nAnimal = Animal; c.mas[1] = vn;
	vn = new node;
	vn->next = c.mas[1]; Animal = NewInAnimal(0, 5, "клест", 1); vn->nAnimal = Animal; c.mas[1] = vn;

	//c.mas[2] = NULL;

	c.mas[3] = new node;
	Animal = NewInAnimal(1, 13, "лещ", 3);
	c.mas[3]->nAnimal = Animal; c.mas[3]->next = NULL;

	//c.mas[4] = NULL;
	//c.mas[5] = NULL;
	//c.mas[6] = NULL;
	//c.mas[7] = NULL;

	c.mas[8] = new node;
	Animal = NewInAnimal(1, 4, "язь", 3);
	c.mas[8]->nAnimal = Animal; c.mas[8]->next = NULL;
	vn = new node;
	vn->next = c.mas[8]; Animal = NewInAnimal(1, 6, "форель", 1); vn->nAnimal = Animal; c.mas[8] = vn;
	vn = new node;
	vn->next = c.mas[8]; Animal = NewInAnimal(2, 21, "человек", 2); vn->nAnimal = Animal; c.mas[8] = vn;

	//c.mas[9] = NULL;
}
void ExpectContainer2Sort(container &c)
{
	c.kol = 15;
	animal* Animal;
	node* vn;

	c.mas[0] = new node;
	Animal = NewInAnimal(1, 3, "осетр", 0);	
	c.mas[0]->nAnimal = Animal; c.mas[0]->next = NULL;
	vn = new node;
	vn->next = c.mas[0]; Animal = NewInAnimal(0, 2, "голубь", 0); vn->nAnimal = Animal; c.mas[0] = vn;
	vn = new node;
	vn->next = c.mas[0]; Animal = NewInAnimal(0, 7, "кукушка", 0); vn->nAnimal = Animal; c.mas[0] = vn;
	vn = new node;
	vn->next = c.mas[0]; Animal = NewInAnimal(0, 7, "журавль", 1); vn->nAnimal = Animal; c.mas[0] = vn;

	c.mas[1] = new node;
	Animal = NewInAnimal(2, 1, "слон", 0);
	c.mas[1]->nAnimal = Animal; c.mas[1]->next = NULL;
	vn = new node;
	vn->next = c.mas[1]; Animal = NewInAnimal(2, 9, "тигр", 1); vn->nAnimal = Animal; c.mas[1] = vn;
	vn = new node;
	vn->next = c.mas[1]; Animal = NewInAnimal(2, 8, "змея", 1); vn->nAnimal = Animal; c.mas[1] = vn;
	vn = new node;
	vn->next = c.mas[1]; Animal = NewInAnimal(0, 5, "клест", 1); vn->nAnimal = Animal; c.mas[1] = vn;

	//c.mas[2] = NULL;

	c.mas[3] = new node;
	Animal = NewInAnimal(1, 13, "лещ", 3);
	c.mas[3]->nAnimal = Animal; c.mas[3]->next = NULL;

	c.mas[4] = new node;
	Animal = NewInAnimal(2, 5, "кот", 1);
	c.mas[4]->nAnimal = Animal; c.mas[4]->next = NULL;
	//c.mas[5] = NULL;
	//c.mas[6] = NULL;
	//c.mas[7] = NULL;

	c.mas[8] = new node;
	Animal = NewInAnimal(1, 4, "язь", 3);
	c.mas[8]->nAnimal = Animal; c.mas[8]->next = NULL;
	vn = new node;
	vn->next = c.mas[8]; Animal = NewInAnimal(1, 6, "форель", 1); vn->nAnimal = Animal; c.mas[8] = vn;
	vn = new node;
	vn->next = c.mas[8]; Animal = NewInAnimal(2, 21, "человек", 2); vn->nAnimal = Animal; c.mas[8] = vn;

	c.mas[9] = new node;
	Animal = NewInAnimal(0, 2, "дятел", 1);
	c.mas[9]->nAnimal = Animal; c.mas[9]->next = NULL;
	vn = new node;
	vn->next = c.mas[9]; Animal = NewInAnimal(1, 10, "пескарь", 4); vn->nAnimal = Animal; c.mas[9] = vn;
}
void ExpectContainer2Desort(container &c)
{
	c.kol = 15;
	animal* Animal;
	node* vn;

	c.mas[0] = new node;
	Animal = NewInAnimal(0, 7, "кукушка", 0);	
	c.mas[0]->nAnimal = Animal; c.mas[0]->next = NULL;
	vn = new node;
	vn->next = c.mas[0]; Animal = NewInAnimal(0, 7, "журавль", 1); vn->nAnimal = Animal; c.mas[0] = vn;
	vn = new node;
	vn->next = c.mas[0]; Animal = NewInAnimal(0, 2, "голубь", 0); vn->nAnimal = Animal; c.mas[0] = vn;
	vn = new node;
	vn->next = c.mas[0]; Animal = NewInAnimal(1, 3, "осетр", 0); vn->nAnimal = Animal; c.mas[0] = vn;

	c.mas[1] = new node;
	Animal = NewInAnimal(0, 5, "клест", 1);
	c.mas[1]->nAnimal = Animal; c.mas[1]->next = NULL;
	vn = new node;
	vn->next = c.mas[1]; Animal = NewInAnimal(2, 1, "слон", 0); vn->nAnimal = Animal; c.mas[1] = vn;
	vn = new node;
	vn->next = c.mas[1]; Animal = NewInAnimal(2, 9, "тигр", 1); vn->nAnimal = Animal; c.mas[1] = vn;
	vn = new node;
	vn->next = c.mas[1]; Animal = NewInAnimal(2, 8, "змея", 1); vn->nAnimal = Animal; c.mas[1] = vn;

	//c.mas[2] = NULL;

	c.mas[3] = new node;
	Animal = NewInAnimal(1, 13, "лещ", 3);
	c.mas[3]->nAnimal = Animal; c.mas[3]->next = NULL;

	c.mas[4] = new node;
	Animal = NewInAnimal(2, 5, "кот", 1);
	c.mas[4]->nAnimal = Animal; c.mas[4]->next = NULL;
	//c.mas[5] = NULL;
	//c.mas[6] = NULL;
	//c.mas[7] = NULL;

	c.mas[8] = new node;
	Animal = NewInAnimal(2, 21, "человек", 2);
	c.mas[8]->nAnimal = Animal; c.mas[8]->next = NULL;
	vn = new node;
	vn->next = c.mas[8]; Animal = NewInAnimal(1, 6, "форель", 1); vn->nAnimal = Animal; c.mas[8] = vn;
	vn = new node;
	vn->next = c.mas[8]; Animal = NewInAnimal(1, 4, "язь", 3); vn->nAnimal = Animal; c.mas[8] = vn;

	c.mas[9] = new node;
	Animal = NewInAnimal(1, 10, "пескарь", 4);
	c.mas[9]->nAnimal = Animal; c.mas[9]->next = NULL;
	vn = new node;
	vn->next = c.mas[9]; Animal = NewInAnimal(0, 2, "дятел", 1); vn->nAnimal = Animal; c.mas[9] = vn;
}
void ExpectContainerOneBird(container &c)
{
	c.kol = 1;
	animal* Animal;

	c.mas[0] = new node;
	Animal = NewInAnimal(0, 2, "голубь", 0);	
	c.mas[0]->nAnimal = Animal; c.mas[0]->next = NULL;
}
void ExpectContainerOneFish(container &c)
{
	c.kol = 1;
	animal* Animal;

	c.mas[3] = new node;
	Animal = NewInAnimal(1, 13, "лещ", 3);
	c.mas[3]->nAnimal = Animal; c.mas[3]->next = NULL;
}
void ExpectContainerOneBeast(container &c)
{
	c.kol = 1;
	animal* Animal;

	c.mas[8] = new node;
	Animal = NewInAnimal(2, 21, "человек", 2);
	c.mas[8]->nAnimal = Animal; c.mas[8]->next = NULL;
}
TEST_F(CContainerTest, CheckInit)
{
	container actual;
	container expect;
	EmptyContainer(expect);
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container init test was failed!!";
}
TEST_F(CContainerTest, CheckDel)
{
	container actual;
	ExpectContainer1(actual);
	actual.Del();
	container expect;
	EmptyContainer(expect);
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container(full) delete test was failed!!";
	actual.Del();
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container(empty) delete test was failed!!";
}
TEST_F(CContainerTest, CheckIn) //
{
	ifstream f("In1.txt");
	container actual;
	actual.In(f);
	f.close();
	container expect;
	ExpectContainer1(expect);
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container input(10 elements) test was failed!!";
	actual.Del();
	expect.Del();
	
	ifstream f1("In2.txt");
	actual.In(f1);
	f1.close();
	ExpectContainer2(expect);
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container input(15 elements) test was failed!!";
	actual.Del();
	expect.Del();

	ifstream f2("InCBird.txt");
	actual.In(f2);
	f2.close();
	ExpectContainerOneBird(expect);
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container input(1 element: bird) test was failed!!";
	actual.Del();
	expect.Del();

	ifstream f3("InCFish.txt");
	actual.In(f3);
	f3.close();
	ExpectContainerOneFish(expect);
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container input(1 element: fish) test was failed!!";
	actual.Del();
	expect.Del();

	ifstream f4("InCBeast.txt");
	actual.In(f4);
	f4.close();
	ExpectContainerOneBeast(expect);
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container input(1 element: beast) test was failed!!";
	actual.Del();
	expect.Del();
}
TEST_F(CContainerTest, CheckOut) //
{
	container c;
	ExpectContainer1(c);
	ofstream f("aOut1.txt");
	c.Out(f);
	c.Del();
	f.close();
	ifstream actual("aOut1.txt");
	ifstream expect("eOut1.txt");
	EXPECT_TRUE(FileCompare(actual, expect)) << "Container output(10 elements) test was failed!!";
	actual.close();
	expect.close();

	ExpectContainer2(c);
	ofstream f0("aOut2.txt");
	c.Out(f0);
	c.Del();
	f0.close();
	ifstream actual0("aOut2.txt");
	ifstream expect0("eOut2.txt");
	EXPECT_TRUE(FileCompare(actual0, expect0)) << "Container output(15 elements) test was failed!!";
	actual0.close();
	expect0.close();

	ExpectContainerOneBird(c);
	ofstream f1("aOutCBird.txt");
	c.Out(f1);
	c.Del();
	f1.close();
	ifstream actual1("aOutCBird.txt");
	ifstream expect1("eOutCBird.txt");
	EXPECT_TRUE(FileCompare(actual1, expect1)) << "Container output(1 element: Bird) test was failed!!";
	actual1.close();
	expect1.close();
	
	ExpectContainerOneFish(c);
	ofstream f2("aOutCFish.txt");
	c.Out(f2);
	c.Del();
	f2.close();
	ifstream actual2("aOutCFish.txt");
	ifstream expect2("eOutCFish.txt");
	EXPECT_TRUE(FileCompare(actual2, expect2)) << "Container output(1 element: Fish) test was failed!!";
	actual2.close();
	expect2.close();
	
	ExpectContainerOneBeast(c);
	ofstream f3("aOutCBeast.txt");
	c.Out(f3);
	c.Del();
	f3.close();
	ifstream actual3("aOutCBeast.txt");
	ifstream expect3("eOutCBeast.txt");
	EXPECT_TRUE(FileCompare(actual3, expect3)) << "Container output(1 element: Beast) test was failed!!";
	actual3.close();
	expect3.close();
}
TEST_F(CContainerTest, CheckSort) //
{
	container actual;
	container expect;
	ExpectContainer1(actual);
	actual.Sort();
	ExpectContainer1Sort(expect);
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container sort(10 elements) test was failed!!";
	actual.Sort();
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container sort(10 elements, sorted) test was failed!!";
	actual.Del();
	expect.Del();

	ExpectContainer2(actual);
	actual.Sort();
	ExpectContainer2Sort(expect);
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container sort(15 elements) test was failed!!";
	actual.Sort();
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container sort(15 elements, sorted) test was failed!!";
	actual.Del();
	expect.Del();

	ExpectContainer2Desort(actual);
	actual.Sort();
	ExpectContainer2Sort(expect);
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container sort(15 elements, desorted) test was failed!!";
	actual.Del();
	expect.Del();

	ExpectContainerOneBird(actual);
	actual.Sort();
	ExpectContainerOneBird(expect);
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container sort(1 element: Bird) test was failed!!";
	actual.Del();
	expect.Del();

	ExpectContainerOneFish(actual);
	actual.Sort();
	ExpectContainerOneFish(expect);
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container sort(1 element: Fish) test was failed!!";
	actual.Del();
	expect.Del();

	ExpectContainerOneBeast(actual);
	actual.Sort();
	ExpectContainerOneBeast(expect);
	EXPECT_TRUE(ContainerCompare(actual, expect)) << "Container sort(1 element: Beast) test was failed!!";
	actual.Del();
	expect.Del();
}
TEST_F(CContainerTest, CheckOutOnlyFish) //
{	
	container c;
	ExpectContainer1(c);
	ofstream f1("aOutOnlyFish1.txt");
	c.OutOnlyFish(f1);
	c.Del();
	f1.close();
	ifstream actual1("aOutOnlyFish1.txt");
	ifstream expect1("eOutOnlyFish1.txt");
	EXPECT_TRUE(FileCompare(actual1, expect1)) << "Container output(10 elements) test was failed!!";
	actual1.close();
	expect1.close();
		
	ExpectContainer2(c);
	ofstream f2("aOutOnlyFish2.txt");
	c.OutOnlyFish(f2);
	c.Del();
	f2.close();
	ifstream actual2("aOutOnlyFish2.txt");
	ifstream expect2("eOutOnlyFish2.txt");
	EXPECT_TRUE(FileCompare(actual2, expect2)) << "Container output(15 elements) test was failed!!";
	actual2.close();
	expect2.close();
}
TEST_F(CContainerTest, CheckSumElementsOfString) //
{
	container c;
	animal* Animal;
	Animal = new fish;
	Animal->name = "";
	EXPECT_TRUE(c.SumElementsOfString(Animal, c.n) == 0);
	Animal->name = "лещ";
	EXPECT_TRUE(c.SumElementsOfString(Animal, c.n) == 3);
	Animal->name = "клест";
	EXPECT_TRUE(c.SumElementsOfString(Animal, c.n) == 1);
	Animal->name = "человек";
	EXPECT_TRUE(c.SumElementsOfString(Animal, c.n) == 8);
	Animal->name = "кукушка";
	EXPECT_TRUE(c.SumElementsOfString(Animal, c.n) == 0);
	Animal->name = "тигр";
	EXPECT_TRUE(c.SumElementsOfString(Animal, c.n) == 1);
}
int main(int argc, char **argv) {
	setlocale(LC_ALL,"rus");
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("pause");
	return 0;
}