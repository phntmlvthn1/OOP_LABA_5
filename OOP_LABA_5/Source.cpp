#include <iostream>
#include <ctime>
using namespace std;
class Animal
{
private:
	string classname, voice;
public:
	Animal()
	{
		classname = "Animal";
		voice = "nothing";
    }

	virtual ~Animal()
	{
		cout << "virtual ~Animal()" << "\n";
	}

	string GetClassName()
	{
		return classname;
	}

	virtual void Speak()
	{
		cout << voice << "\n";
	}
};

class Cat : public Animal
{
private:
	string classname, voice;
public: 

	Cat()
	{
		classname = "Cat";
		voice = "mew-mew";
	}

	~Cat()
	{
		cout << "~Cat()" << "\n";
	}

	string GetClassName()
	{
		return classname;
	}

	 void Speak()
	{
		cout << voice << "\n";
	}

	 void SayMurr()
	 {
		 cout <<"Murr\n";
	 }
};

class Dog : public Animal
{
private:
	string classname, voice;
public:

	Dog()
	{
		classname = "Dog";
		voice = "gav-gav";
	}

	~Dog()
	{
		cout << "~Dog()" << "\n";
	}

	string GetClassName()
	{
		return classname;
	}

	void Speak()
	{
		cout << voice << "\n";
	}

	void SayWoof()
	{
		cout << "Woof\n";
	}
};



int main()
{
	srand(time(0));
	Animal *barsik = new Cat;
	cout << barsik->GetClassName()<<"\n";       // ����� �� ��������, �.�. ������ Cat ������� � ���������� ������-������
	Cat *pushok = new Cat;
	cout << pushok->GetClassName() << "\n";    // ����� ��������, �.�. ������ Cat ������� � ���������� ������ ������ 
	delete pushok;

	cout << "\n\n";

	cout << barsik->GetClassName() << "\n";  // ����� �� �����������, ���������� ����������� �����
	barsik->Speak();              // ����� �����������, ���������� ����������� ����������� �����
	delete barsik;                   // ���������� Animal �����������, ������� ������� ���������� ���������� Cat

	cout << "\n\n";

	Animal* pet;
	if (rand() % 2 == 0)  //� ���������� ������ Animal ��������� ������� �������� ������ ������ Cat ��� Dog
		pet = new Cat;
	else
		pet = new Dog;
    
	if (pet->GetClassName() == "Cat") // ������ �������� �� �������������� � ������
		((Cat*)pet)->SayMurr();               // ���������� ������ ���������� � ���� ����� ��������
	else  
		((Dog*)pet)->SayWoof();
	
	Animal* pet2;
	if (rand() % 2 == 0)  // ��� �� ��������� ������� �������� � pet2 Cat ��� Dog
		pet2 = new Cat;
	else
		pet2 = new Dog;

	if (dynamic_cast<Cat*>(pet2)) // �������� �� �������������� � ������ � ������� dynamic_cast
		((Cat*)pet2)->SayMurr();       // ���������� ���������� � ���� ����� �������� � ������� dynamic_cast
	else
		((Dog*)pet2)->SayWoof();
}