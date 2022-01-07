#include<iostream>
//Implicit conversion to a class object happens 
//1. When you assign(using = )/pass(as an argument to a function) a data that is the same type as the constructor of the class accepts
//2. Also you can use the another  data type that can be converted to the data type of constructor. This means I can use a double inplace of an integer. 
// As double can be rounded off to an integer.

//Why const is used in copy constructor and assignment operator - sometimes we copy from temporary objects or rvalues which can be copied if the lvalue is constant only
// check this error -  cannot bind non-const lvalue reference of type 'abc&' to an rvalue of type 'abc'
class abc
{
	
public:
	int x;
	abc(int a):x(a) {}
	abc(const abc& obj)
	{
		x = obj.x;
	}
	int operator+(const abc& obj)
	{
		x = x + obj.x;
		return x;
	}
	abc& operator=(const abc& obj)
	{
		x = obj.x;
		std::cout << "base assignment" << "\n";
		return *this;
	}
	virtual ~abc() = default;
};

class def : public abc
{
	int y;
public:
	def& operator=(const def& rhs)
	{
		if (&rhs == this)
			return *this;
		abc::operator=(rhs);
		y = rhs.y;
		return *this;
	}


};

void function(abc obj)
{
	std::cout << obj.x << "\n";
}
/*
int main()
{
	function(20.05);
	abc obj1(5), obj2(10);
	obj1  = obj1 + 50;
	function(obj1);
	obj1 = 89;
	function(obj1);
}*/