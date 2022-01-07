//According to the C++17 standard, what is the output of this program ?


#include <iostream>
#include <utility>

int y(int&) { return 1; }
int y(int&&) { return 2; }

template <class T> int f(T&& x) { return y(x); }
template <class T> int g(T&& x) { return y(std::move(x)); }
template <class T> int h(T&& x) { return y(std::forward<T>(x)); }

int k(int&& x) { return y(x);  }

int main() {
    int i = 10;
    std::cout << f(i) << f(20);
    std::cout << g(i) << g(20);
    std::cout << h(i) << h(20);

    //std::cout << k(i) << k(20); //an rvalue reference cannot be bound to an lvalue
    return 0;
}
/* The T&& in the templated functions do not necessarily denote an rvalue reference, it depends on the type that is used to instantiate the template.
If instantiated with an lvalue, it collapses to an lvalue reference, if instantiated with an rvalue, it collapses to an rvalue reference.See note[1].

Scott Meyers has written a very good article about this, where he introduces the concept of "universal references" (the official term is "forwarding reference") http://isocpp.org/blog/2012/11/universal-references-in-c11-scott-meyers

In this example, all three functions are called once with an lvalueand once with an rvalue.In all cases, calling with an lvalue(i) collapses T&& x to T& x(an lvalue reference), 
and calling with an rvalue(20) collapses T&& x to T&& x(an rvalue reference).Inside the functions, x itself is always an lvalue, no matter if its type is an rvalue reference or an lvalue reference.

- For the first example, y(int&) is called for both cases.Output : 11.
- For the second example, move(x) obtains an rvalue reference, and y(int&&)is called for both cases.Output : 22.
- For the third example, forward<T>(x) obtains an lvalue reference when x is an lvalue reference, and an rvalue reference when x is an rvalue reference, 
resulting in first a call to y(int&) and then a call to y(int&&).Output : 12.

Note[1] : [dcl.ref] �11.3.2�6 in the standard : "If a typedef-name (�10.1.3, �17.1) or a decltype-specifier (�10.1.7.2) denotes a type TR that is a reference to a type T,
an attempt to create the type �lvalue reference to cv TR� creates the type �lvalue reference to T�, while an attempt to create the type �rvalue reference to cv TR� creates the type TR." 
The example at the end of that paragraph is worth a look.
*/