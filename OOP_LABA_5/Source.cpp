#include <iostream>
#include <ctime>
#include <memory> 
using namespace std;
class Animal
{
private:
	string classname, voice;
	string objectname;
public:
	Animal(string name) // ����������� �� ������� - ���������� ��� �������, ��� ����, ����� ��������, ����� ������ ��������� � �����������
	{
		objectname = name;
		classname = "Animal";
		voice = "nothing";
		cout << "Animal(string name)\n";
	}
	Animal()
	{
		cout << "Animal()\n";
	}
	virtual ~Animal()
	{
		cout << "virtual ~Animal()";
		if (objectname != "")
			cout << ", deleted object - " << objectname << "\n"; // ������� ��� �������, ������� �������� 
		else cout << "\n";
	}

	virtual string GetClassName()        // �����, ������� ���������� �������� ������ �������
	{
		return classname;
	}

	virtual bool isA(string name)
	{
		if (name == classname)
			return true;
		else return false;
	}

	virtual void Speak()
	{
		cout << voice << "\n";
	}

	void DoSomething1()        // ����� 1, ������� �������� ����� 2
	{
		cout << "Animal::void DoSomething1()\n";
		DoSomething2();
	}

	void DoSomething2()      // ������������� �����, ������� ������������� � ������-�������
	{
		cout << "Animal::void DoSomething2()\n";
	}

	void DoSomething3()        // ����� 3, ������� �������� ����� 4
	{
		cout << "Animal::void DoSomething3()\n";
		DoSomething4();
	}

	virtual void DoSomething4()      // ����������� �����, ������� ������������� � ������-�������
	{
		cout << "Animal::void DoSomething4()\n";
	}
};

class Cat : public Animal
{
private:
	string classname, voice;
	string objectname;
public:

	Cat()
	{
		cout << "Cat()\n";
	}
	Cat(string name)
	{
		objectname = name;
		classname = "Cat";
		voice = "mew-mew";
		cout << "Cat(string name)\n";
	}

	~Cat()
	{
		cout << "~Cat()";
		if (objectname != "")
			cout << ", deleted object - " << objectname << "\n";
		else cout << "\n";
	}


	string GetClassName()  // ����� ��� ������ �������� �� �������������� � ������ ����� ������� �����
	{
		return classname;
	}

	bool isA(string name)  // ����� ��� ������ �������� �� �������������� � ������ ����� ��������� � ���������� ������
	{
		if (name == classname)
			return true;
		else return false;
	}

	void Speak()
	{
		cout << voice << "\n";
	}

	void SayMurr()
	{
		cout << "Murr\n";
	}

	void DoSomething2()  // ���������������� ������������� �����
	{
		cout << "Cat::void DoSomething2()\n";
	}

	void DoSomething4()      // ���������������� ����������� �����
	{
		cout << "Cat::void DoSomething4()\n";
	}
};

class Dog : public Animal
{
private:
	string classname, voice;
	string objectname;
public:
	Dog()
	{
		cout << "Dog()\n";
	}
	Dog(string name)
	{
		objectname = name;
		classname = "Dog";
		voice = "gav-gav";
		cout << "Dog(string name)\n";
	}

	~Dog()
	{
		cout << "~Dog()";
		if (objectname != "")
			cout << " , deleted object - " << objectname << "\n";
		else cout << "\n";
	}

	string GetClassName()
	{
		return classname;
	}

	bool isA(string name)
	{
		if (name == classname)
			return true;
		else return false;
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

Animal foo(Animal& object)
{
	cout << "Animal foo(Animal object)\n";
	return object;
}



class Base
{
public:

	Base()
	{
		cout << "Base()\n";
	};
	Base(Base* obj)
	{ 
		cout << "Base(Base* obj)\n";
	};
	Base(Base& obj)
	{ 
		cout << "Base(Base& obj)\n";
	};
	~Base() 
	{ 
		cout << "~Base()\n";
	};

};

class Desc : public Base
{
public:

	Desc() 
	{  
		cout << "Desc()\n";
	};
	Desc(Desc* obj) 
	{
		cout << "Desc(Desc* obj)\n";
	};
	Desc(Desc& obj) 
	{ 
		cout << "Desc(Desc& obj)\n";
	};
	~Desc()
	{ 
		cout << "~Desc()\n";
	};

};

void func1(Base  obj) 
{ 
	cout << "void func1(Base  obj)\n";
};
void func2(Base* obj) 
{
	cout << "void func2(Base*  obj)\n";
};
void func3(Base& obj) 
{  
	cout << "void func3(Base& obj)\n";
};

Base func4(Base obj) 
{  
	return(obj);
};
Base* func5(Base *obj)
{  
	return(obj);
};
Base& func6(Base &obj)
{  
	return(obj);
};



int main()
{
	srand(time(0));
	Animal* barsik = new Cat("barsik");
	//cout << barsik->GetClassName() << "\n";  
	cout  << "Animal\n"; // ����� �� ��������, �.�. ������ Cat ������� � ���������� ������-������
	Cat* barsik2 = new Cat("barsik2");
	cout << barsik2->GetClassName() << "\n";    // ����� ��������, �.�. ������ Cat ������� � ���������� ������ ������ 
	delete barsik2;

	cout << "\n\n";

	cout << barsik->GetClassName() << "\n";  // ����� �� �����������, ���������� ����������� �����
	barsik->Speak();              // ����� �����������, ���������� ����������� ����������� �����
	delete barsik;                   // ���������� Animal �����������, ������� ������� ���������� ���������� Cat

	cout << "\n\n";

	Animal* pet;
	if (rand() % 2 == 0)                         //� ���������� ������ Animal ��������� ������� �������� ������ ������ Cat ��� Dog
		pet = new Cat("somecat");
	else
		pet = new Dog("somedog");

	if (pet->GetClassName() == "Cat") // ������ �������� �� �������������� � ������ � ������� ������  GetClassName
		((Cat*)pet)->SayMurr();               // ���������� ������ ���������� � ���� ����� ��������
	else
		((Dog*)pet)->SayWoof();

	Animal* pet1;
	if (rand() % 2 == 0)                           //� ���������� ������ Animal ��������� ������� �������� ������ ������ Cat ��� Dog
		pet1 = new Cat("somecat1");
	else
		pet1 = new Dog("somedog1");

	if (pet->isA("Dog"))                             // ������ �������� �� �������������� � ������ � ������� ������ isA
		((Dog*)pet1)->SayWoof();              // ���������� ������ ���������� � ���� ����� ��������
	else
		((Cat*)pet1)->SayMurr();

	Animal* pet2;
	if (rand() % 2 == 0)  // ��� �� ��������� ������� �������� � pet2 Cat ��� Dog
		pet2 = new Cat("somecat2");
	else
		pet2 = new Dog("somedog2");

	if (dynamic_cast<Cat*>(pet2)) // �������� �� �������������� � ������ � ������� dynamic_cast
		((Cat*)pet2)->SayMurr();       // ���������� ���������� � ���� ����� �������� � ������� dynamic_cast
	else
		((Dog*)pet2)->SayWoof();
	delete pet;
	delete pet1;
	delete pet2;

	cout << "\n\n";

	Animal pet3("somepet");
	Animal* pet4 = new Animal("pet4");  // ������ ������ ���������� �� Animal
	*pet4 = foo(pet3);                             // � 0 ������ ������� ��������� ��������� ������� foo - ������� ������ ������
	delete pet4;                                      // ���������� ���������� ��� �������� ������ �������, ����� �������, ����� pet3

	cout << "\n\n";
	{
		unique_ptr<Animal> pet5(new Animal("pet5")); // ����������� ������� pet5, �������� ����� ������������� �� ���� unique_ptr, �� ���������� ��������� pet5 �������� ���
	} // pet5 ������� �� ���� ���������, ������ ���������
	cout << "\n\n";
	Animal* pet6 = new Animal("pet6");

	{
		shared_ptr<Animal> ptr1(pet6);
		{
			shared_ptr<Animal> ptr2(ptr1);  // ���������� ���������� ������������� ��� �������� ������� shared_ptr �� ptr1, ������������ �� ��� �� ������
		} // ptr2 ������� �� ������� ��������� �����, �� ������ �� ����������, �.�. ptr1 ��� ��������� � ���� ���������
	} // ptr1 ������� �� ������� ��������� �����, � pet6 ������������ ����� �����

	cout << "\n\n";

	Cat* barsik3 = new Cat("barsik3");
	barsik3->DoSomething1();    // ��� ������ �������������� ������ ���������� ����� ������
	barsik3->DoSomething3();   // ��� ������ ������������ ������ ���������� ����� �������
	cout << "\n\n";

	Animal* barsik4 = new Cat("barsik4");
	barsik4->DoSomething2(); // ��� ��������� � ������� ����� ��������� �� ������� �����, ���������� ������������� ����� ������
	barsik3->DoSomething2(); // ��� ��������� � ������� ����� ��������� �� �����-�������, ���������� ������������� ����� �������
	cout << "\n\n";

	barsik4->DoSomething4(); // ��� ��������� � ������� ����� ��������� �� ������� �����, ���������� ����������� ����� �������
	barsik3->DoSomething4(); // ��� ��������� � ������� ����� ��������� �� �����-�������, ���������� ����������� ����� �������


	cout << "\n\n";
	Base object1;
	Base *object2 = new Base;
	func1(object1);
	func2(object2);
	func3(object1);
	Desc object3;
	Desc* object4 = new Desc;
	func1(object3);
	func2(object4);
	func3(object3);

	Base object5;
	Base* object6 = new Base;  
	object5 = func4(object6);
	object5 = func5(object6);
	object5 = func6(*object6);
	delete object6;
    cout << "\n\n";
}