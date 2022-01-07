#include<iostream>
//1.auto - return type deduction as I dont care what count type is
template<typename T>
auto count_things(const T& vec, int value)
{
    const auto count = std::count(begin(vec), end(vec), value);
    return count;
}
//2.there is no change in range based for loops in C++14

//Lambda- Generic
// I can in C++14, technically the lambda function below works with any thing like int, long int, float, double
// So it is handly I can change the lambda argument to auto and ask the compiler to create a implicit template for me

template<typename T>
void count_things_less_than_3(const T& vec, int value)
{
    const auto count = std::count(begin(vec), end(vec), [](const auto i) {return i < 3; });

}
//Lambda- Generalize capture expression, I can possibly add anything inside capture expression
template<typename T>
void count_things_less_than_3_cpp14(const T& vec, int value)
{
    const auto count = std::count(begin(vec), end(vec), [value = []() {return 3; }] (const auto i) {return (i < 3)+value; });

}

//4.variadic templates did not change in C++14

//5.Unique_ptr - make_unique is introduced in C++14
//new and delete now no longer needed
// unique_ptr and shared_ptr are tools for automatic memory management and are important topics to focus on
#include<memory>
void allocate_memory_cpp14()
{
    auto ptr(std::make_unique<int>(5));
}
//6.constexpr in C++14
// it got much more flexible, can have loops, branches, 
//multiple return statements, except other functions that are not constexpr 

constexpr int get_value()
{
    int val = 8;
    int val2 = 10;
    if (val > 3)
        return val + val2;
    else
        return val - val2;
}
/*int main()
{
    return get_value();
}*/