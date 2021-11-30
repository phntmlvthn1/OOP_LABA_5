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
	cout << barsik->GetClassName()<<"\n";       // метод не перекрыт, т.к. объект Cat помещен в переменную класса-предка
	Cat *pushok = new Cat;
	cout << pushok->GetClassName() << "\n";    // метод перекрыт, т.к. объект Cat помещен в переменную своего класса 
	delete pushok;

	cout << "\n\n";

	cout << barsik->GetClassName() << "\n";  // метод не виртуальный, вызывается наследуемый метод
	barsik->Speak();              // метод виртуальный, вызывается наследуемый виртуальный метод
	delete barsik;                   // деструктор Animal виртуальный, поэтому сначала вызывается деструктор Cat

	cout << "\n\n";

	Animal* pet;
	if (rand() % 2 == 0)  //в переменную класса Animal случайным образом помещаем объект класса Cat или Dog
		pet = new Cat;
	else
		pet = new Dog;
    
	if (pet->GetClassName() == "Cat") // ручная проверка на принадлежность к классу
		((Cat*)pet)->SayMurr();               // безопасное ручное приведение к типу после проверки
	else  
		((Dog*)pet)->SayWoof();
	
	Animal* pet2;
	if (rand() % 2 == 0)  // так же случайным образом помещаем в pet2 Cat или Dog
		pet2 = new Cat;
	else
		pet2 = new Dog;

	if (dynamic_cast<Cat*>(pet2)) // проверка на принадлежность к классу с помощью dynamic_cast
		((Cat*)pet2)->SayMurr();       // безопасное приведение к типу после проверки с помощью dynamic_cast
	else
		((Dog*)pet2)->SayWoof();
}