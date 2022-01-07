//why Inheritance is required?
// A "is-a" relationship recognises the pattern that the real world objects tend to exist in hierarchies.
// We can simply copy the base class code and changing the relevant parts or amending the code, we can achieve the goal of creating a new class that is slightly different
// from the original. But this makes an OOP programmer highly annoyed.
// reason - A bug fix to the original will not be reflected in the new class because the two classes contain completely separate code.
// The compiler does not know any relationship between the two classes, so they are not polymorphic, they are not just different variations of the same thing.
// Not surprisingly, C++ provides built-in support for defining a true is-a relationship.

// A derived class can access public and protected methods and data members declared in its base class as though they were its own.

// A pointer or reference to an object of a base class can refer to the object of the base class as well as any of its derived classes. You cannot call
// methods from the derived class through the base pointer directly. Oneway to do this is upcasting(static_cast<Derived*>(base)->someOtherMethod();)

//Derived classes retain their overridden methods when referred to by a base pointer or reference. They lose their uniqueness when cast to a base class object.
//  The loss of the derived class's data members and overridden methods is called slicing.

// If the method is declared virtual, the correct implementation is called through the use of vtable memory.
// Each class that has one or more virtual methods, has a vtable and every object of such a class contains a pointer to said vtable.
// vtable does not contain any entry for non-virtual functions

// Once a method or destructor is made virtual, it is virtual for all derived classes even if the virtual keyword is removed from derived classes.
#include <iostream>

//curiously recursive template pattern - It combines template programming efficiently with inheritance.
#if 0
template <class T>
struct  Inequality
{
public:
	bool operator!=(const T& rhs)
	{
		std::cout << __FUNCTION__ << std::endl;
		return !(static_cast<T&>(*this) == rhs);
	}
};

class Derived : public Inequality <Derived>
{
	int x, y;
public:
	Derived(int a, int b)
	{
		x = a;
		y = b;
	}
	bool operator==(const Derived& rhs)
	{
		std::cout << __FUNCTION__ << std::endl;
		return x == rhs.x && y == rhs.y;
	}
};
#endif

//#if 0
class Base
{
public:
	virtual Base* somePrint()
	{
		std::cout << "Base: func" << "\n";
		return this;
	}
	virtual Base& operator=(const Base& rhs)
	{
		std::cout << "Base: assign" << "\n";
		return *this;
	}
	void someOtherMethod()
	{
		std::cout << "Base:someOtherMethod\n";
	}
};

class Derived : public Base
{
public:
	Derived* somePrint() override
	{
		std::cout << "Derived: func" << "\n";
		return this;
	}
	Derived& operator=(const Derived& rhs)
	{
		std::cout << "Derived: Assign" << "\n";
		if (this == &rhs)
			return *this;
		Base::operator=(rhs);
		//Do neccesary assignments for derived classes
		return *this;
	}
	void someOtherMethod()
	{
		std::cout << "Derived:someOtherMethod\n";
	}
	void derivedMethod()
	{
		std::cout << "defined only in derived\n";
	}
};
//#endif

#if 0
int main()
{
	//Inequality <Derived> d;
	/*Derived obj1(10, 20);
	Derived obj2(10, 20);
	if (obj2 != obj1)
		std::cout << "Not Equal\n";
	else
		std::cout << "Equal\n";*/
	//Base* base = new Derived();
	//static_cast<Derived*>(base)->someOtherMethod();

	Base base_obj;
	Derived derived_obj;
	base_obj = derived_obj;
	base_obj.someOtherMethod();


}
#endif