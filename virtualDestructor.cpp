//Making your destructor non-virtual can result in situations in which memory is not freed by object destruction.
//Only class that is marked as final , you could make its destructor non-virtual.
//If a derived class uses memory that is dynamically allocated in the constructor and deleted in the destructor, it will never be freed if the destrucotr is never called.
// Or if the derived class has members that are automatically deleted when an isntance of the class is destroyed, such as std::unique_ptrs, then those members
// will not get deleted if the destructor is never called.

#include <iostream>
class Base
{
public:
	virtual ~Base() {};
};

class Derived : public Base
{
public:
	Derived()
	{
		m_string = new char[30];
		std::cout << "m_string allocated\n";
	}
	~Derived()
	{
		delete[] m_string;
		std::cout << "m_string deallocated\n";
	}
private:
	char* m_string;
};

/*int main()
{
	//Base* ptr1 = new Derived();
	//delete ptr1;
	Base obj1;
	Base obj2(obj1);

	return 0;
}*/