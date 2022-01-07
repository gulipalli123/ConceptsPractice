#include<iostream>

/* To Avoid obscure bugs, you should override all versions of an overloaded method
	either explicitly or with the using keyword, but keep the risks of the using clause in mind*/
class Base
{
public:
	virtual ~Base() = default;
	virtual void overload()
	{
		std::cout << "Base overload method" << std::endl;
	}
	virtual void overload(int i)
	{
		std::cout << "Base overload method with arg" << std::endl;
	}
};

class Derived: public Base
{
public:
	//virtual ~Derived() = default;
	using Base::overload;
	virtual void overload()
	{
		std::cout << "Derived overload method" << std::endl;
	}

};

/*int main()
{
	Derived myDerived;
	myDerived.overload(6); //too many arguments in function call
}*/