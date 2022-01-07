#include<iostream>
#include<vector>

class Test
{
public:
	Test(int size) { ptr = new int[size]; }
	Test(const Test& copy): double_vec(copy.double_vec)
	{
		ptr = new int[sizeof(*copy.ptr)];
	}
private:
	std::vector<double> double_vec;
	int* ptr;
};
int x;
int getInt()
{
	return x;
}

int&& getInt_RValue()
{
	return std::move(x);
}
void printAddress(const int& v)
{
	std::cout << reinterpret_cast<const void*>(&v) << std::endl;
}

/*int main()
{
	printAddress(getInt());
	printAddress(x);
	printAddress(getInt_RValue());

	int y = 10;
	int& z = y;   // z is an alias to y because y is still accessable, optimized, no costructor called
	//int&& z = std::move(y);   //Now y becomes temporary object, so should not be used afterwards
	//int&& z = y;  //an rvalue reference cannot be bound to an lvalue
	//int z = std::move(y);  //equivalent to writing z = 10, no optimization
	std::cout << &y << " " << &z << " " << z << "\n";
}*/