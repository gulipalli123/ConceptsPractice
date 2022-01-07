// C++Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
// How do I throw polymorphically

//sometimes people write code like this

#include <iostream>
/*
class Base
{

};

class Derived : public Base
{

};

void f(Base& b)

{
    throw b;
}
int main()
{
    Derived d;
   // Base* b = &d;
    try {
        f(d);
    }
    
    catch (Derived d)
    {
        std::cout << "Derived exception\n";
    }

    catch (Base b)
    {
        std::cout << "Base exception" << std::endl;
    }
    std::cout << "end of program\n";
}*/

//If you try the above, you might be surprised that  at run-time your catch(Base b) clause is entered though you have thrown a derived object. This is because you didn't throw polymorphically.
//In the function f(Base& b), the throw b, throws an object with the same type as the static type of the expression e. In other words it throws an instance of base object.

class Base
{
public:
    virtual void raise()
    {
        throw* this;
    }
};

class Derived : public Base
{
public:
    void raise()
    {
        throw* this;
    }
};

void f(Base& b)
{
    b.raise();
}

int main()
{
    Derived d;
    try {
        f(d);
    }
    catch (Derived & d)
    {
        std::cout << "Derived exception\n";
    }
    catch (Base & b)
    {
        std::cout << "Base exception\n";
    }
    std::cout << "end of program\n";
}

//Note that the throw statement has been moved to a virtual function. The statement b.raise() will exhibit polymorphic behaviour, since raise is declared virtual ans b is passed by reference.
//As before the thrown object will be static type of the object in the throw statement and this time the static type in Derived::raise() is Derived object.

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
