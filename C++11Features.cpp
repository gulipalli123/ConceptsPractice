#include <iostream>
// C++11Features.cpp : This file contains the 'main' function. Program execution begins and ends there.
//1.auto - use auto when you dont care about the type
         // This is particularly useful when doing generic programming
template<typename T>
void count_things(const T& vec, int value)
{
    const auto count = std::count(begin(vec), end(vec), value);
}
//2.range based for loops
//The amount of boilerplate code that is removed here is astounding
//Using auto here is really helpful and if we add const before auto, it can avoid things like slicing

template<typename T>
void do_things(const T& vec, int value)
{
    for (const auto& elem : vec)
    {

    }
}

//3.Lambdas
// It gives us a simple way to create a function object and it again avoids a lot of boilerplate code
template<typename T>
void count_things_less_than_3(const T& vec, int value)
{
    const auto count = std::count(begin(vec), end(vec), [](int i) {return i < 3; });
}

//4.variadic templates
template<typename Func, typename ...T>
void call(const Func& function, const T& ... param)
{
    function(param...);
}

//5.unique_ptr
//it fixes some bugs in the language in auto_ptr
#include<memory>
void allocate_memory()
{
    std::unique_ptr<int> ptr(new int(5));
} // When this goes out of scope ptr is popped from the stack and its memory is freed and this goes back to destructors in RAII

//6.Constexpr
// it is quite limited in C++11, it can only call other constexpr functions
// it can only have a single return statement  and has to be expressed in recursive method 
constexpr int get_value()
{
    return 5 * 6;
}
constexpr auto value = get_value();
#include<array>
/*int main()
{
    
    std::array<int, value> values;

    std::cout << "Hello World!\n";
}*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
