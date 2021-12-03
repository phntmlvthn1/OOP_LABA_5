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
	Animal(string name) // конструктор со строкой - передается имя объекта, для того, чтобы понимать, какой объект удаляется в деструкторе
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
			cout << ", deleted object - " << objectname << "\n"; // выводим имя объекта, который удалился 
		else cout << "\n";
	}

	virtual string GetClassName()        // метод, который возвращает название класса объекта
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

	void DoSomething1()        // метод 1, который вызывает метод 2
	{
		cout << "Animal::void DoSomething1()\n";
		DoSomething2();
	}

	void DoSomething2()      // невиртуальный метод, который переопределен в классе-потомке
	{
		cout << "Animal::void DoSomething2()\n";
	}

	void DoSomething3()        // метод 3, который вызывает метод 4
	{
		cout << "Animal::void DoSomething3()\n";
		DoSomething4();
	}

	virtual void DoSomething4()      // виртуальный метод, который переопределен в классе-потомке
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


	string GetClassName()  // метод для ручной проверка на принадлежность к классу через возврат имени
	{
		return classname;
	}

	bool isA(string name)  // метод для ручной проверка на принадлежность к классу через сравнение с переданным именем
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

	void DoSomething2()  // переопределенный невиртуальный метод
	{
		cout << "Cat::void DoSomething2()\n";
	}

	void DoSomething4()      // переопределенный виртуальный метод
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
	cout  << "Animal\n"; // метод не перекрыт, т.к. объект Cat помещен в переменную класса-предка
	Cat* barsik2 = new Cat("barsik2");
	cout << barsik2->GetClassName() << "\n";    // метод перекрыт, т.к. объект Cat помещен в переменную своего класса 
	delete barsik2;

	cout << "\n\n";

	cout << barsik->GetClassName() << "\n";  // метод не виртуальный, вызывается наследуемый метод
	barsik->Speak();              // метод виртуальный, вызывается наследуемый виртуальный метод
	delete barsik;                   // деструктор Animal виртуальный, поэтому сначала вызывается деструктор Cat

	cout << "\n\n";

	Animal* pet;
	if (rand() % 2 == 0)                         //в переменную класса Animal случайным образом помещаем объект класса Cat или Dog
		pet = new Cat("somecat");
	else
		pet = new Dog("somedog");

	if (pet->GetClassName() == "Cat") // ручная проверка на принадлежность к классу с помощью метода  GetClassName
		((Cat*)pet)->SayMurr();               // безопасное ручное приведение к типу после проверки
	else
		((Dog*)pet)->SayWoof();

	Animal* pet1;
	if (rand() % 2 == 0)                           //в переменную класса Animal случайным образом помещаем объект класса Cat или Dog
		pet1 = new Cat("somecat1");
	else
		pet1 = new Dog("somedog1");

	if (pet->isA("Dog"))                             // ручная проверка на принадлежность к классу с помощью метода isA
		((Dog*)pet1)->SayWoof();              // безопасное ручное приведение к типу после проверки
	else
		((Cat*)pet1)->SayMurr();

	Animal* pet2;
	if (rand() % 2 == 0)  // так же случайным образом помещаем в pet2 Cat или Dog
		pet2 = new Cat("somecat2");
	else
		pet2 = new Dog("somedog2");

	if (dynamic_cast<Cat*>(pet2)) // проверка на принадлежность к классу с помощью dynamic_cast
		((Cat*)pet2)->SayMurr();       // безопасное приведение к типу после проверки с помощью dynamic_cast
	else
		((Dog*)pet2)->SayWoof();
	delete pet;
	delete pet1;
	delete pet2;

	cout << "\n\n";

	Animal pet3("somepet");
	Animal* pet4 = new Animal("pet4");  // создаю массив указателей на Animal
	*pet4 = foo(pet3);                             // в 0 ячейку массива записываю результат функции foo - функция вернет объект
	delete pet4;                                      // вызывается деструктор для удаления ячейки массива, затем массива, затем pet3

	cout << "\n\n";
	{
		unique_ptr<Animal> pet5(new Animal("pet5")); // динамически создаем pet5, передаем право собственности на него unique_ptr, по завершении программы pet5 удалится сам
	} // pet5 выходит из зоны видимости, объект удаляется
	cout << "\n\n";
	Animal* pet6 = new Animal("pet6");

	{
		shared_ptr<Animal> ptr1(pet6);
		{
			shared_ptr<Animal> ptr2(ptr1);  // используем копирующую инициализацию для создания второго shared_ptr из ptr1, указывающего на тот же объект
		} // ptr2 выходит из области видимости здесь, но ничего не происходит, т.к. ptr1 еще находится в зоне видимости
	} // ptr1 выходит из области видимости здесь, и pet6 уничтожается также здесь

	cout << "\n\n";

	Cat* barsik3 = new Cat("barsik3");
	barsik3->DoSomething1();    // при вызове невиртуального метода вызывается метод предка
	barsik3->DoSomething3();   // при вызове виртуального метода вызывается метод потомка
	cout << "\n\n";

	Animal* barsik4 = new Cat("barsik4");
	barsik4->DoSomething2(); // при обращении к объекту через указатель на базовый класс, вызывается невиртуальный метод предка
	barsik3->DoSomething2(); // при обращении к объекту через указатель на класс-потомок, вызывается невиртуальный метод потомка
	cout << "\n\n";

	barsik4->DoSomething4(); // при обращении к объекту через указатель на базовый класс, вызывается виртуальный метод потомка
	barsik3->DoSomething4(); // при обращении к объекту через указатель на класс-потомок, вызывается виртуальный метод потомка


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