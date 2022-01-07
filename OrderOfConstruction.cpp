#include<iostream>
class Something
{
public:
	Something()
	{
		std::cout << "10" << std::endl;
	}
};

class Base
{
public:
	Base(int x)
	{
		std::cout << x << std::endl;
	}
	Something mSth;
};

class Derived : public Base
{
public:
	Derived(int y): Base(y)
	{
		std::cout << y+1 << std::endl;
	}
private:
	//Something mSth;
};

/*int main()
{
	Derived myDerived(5);
	return 0;
}*/