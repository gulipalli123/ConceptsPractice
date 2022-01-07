#include<string>
#include<iostream>
class Base 
{
public:
	virtual ~Base() = default;
	Base() = default;
	Base(std::string str) { std::cout << str << std::endl; }
	Base(float f) { std::cout << "Base::f" << std::endl; }
	int x;
};
class Derived : public Base
{
   int x;
public:
	using Base::Base;
	Derived(int i) { std::cout << i << std::endl; }
	Derived(float f){ std::cout << "Derived::f" << std::endl; }
	void func()
	{
		//int x;
		std::cout << x + x << "\n";
	}
};

//You cannot overide a static method, A method cannot be both static and virtual
class BaseStatic
{
public:
	static void beStatic()
	{
		std::cout << "Base Static being static" << std::endl;
	}
};
class DerivedStatic :public BaseStatic
{
public:
	static void beStatic()
	{
		std::cout << "Derived Static being static" << std::endl;

	}
};

int main()
{
	Derived derived1(2);
	Derived derived2(std::string("kiran"));
	Derived derived3(1.23f);

	//C++ does not care what the object actually is when calling a static method. 
	//It only cares about the compile time type. 
	DerivedStatic myDerivedStatic;
	BaseStatic& ref = myDerivedStatic;
	myDerivedStatic.beStatic();
	ref.beStatic();
}