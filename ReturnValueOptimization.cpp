//Copy elision is to optimize copy and move constructors and thus leads to a copy-free pass-by-value semantics.
//Under the following circumstances, the compilers are allowed to optimize the copy and move constructors
//away from a class objects, even if the copy , move constructor and destructors have visible side effects.
//1.If a function returns a class type(object) by value and the return statement consists of the name of a
//local variable(object is local), which is  neither an argument of the function nor an argument of the
// catch clause, then copying or moving is omitted. The local variable is created directly at the location
// to which otherwise the return value would have copied or moved. This is called Named Return Value
// Optimization(NRVO).
// 2.If an unnamed , temporary and no-referenced variable would be copied or moved into an object, without
// taking into consideration of cv qualification, the copying or moving is omitted. When the temporary
// variable is created, it is created directly at the memory location to which otherwise it would have
// copied or moved. If the unnamed variable is in the return statement of a function, it is called Return
// Value Optimization(RVO).
// The omission of the copy or move operation can be chained as desired.
// In Const expressions and initialization of constants, the removal  of any copy and move operation is
// guaranteed.
// If a compiler cannot perform a copy elision with in a return statement or throw expression though all
// the conditions for it are met, it shall try to use the move constructor.
// Since not all compilers use copy elision in every permitted situation (e.g. without optimization),
// programs that rely on side effects of copy or move constructors and destructors are  not easily portable.
// When a method or function contains multiple return statements and if it does not return the same object
// from different return statements, then copy elision cannot be performed.
#include<iostream>

class CopyElisionTest
{
public:
	CopyElisionTest() { std::cout << "Constructor called\n"; }
	CopyElisionTest(const CopyElisionTest&) { std::cout << "copy constructor called\n"; }
	CopyElisionTest(CopyElisionTest&& rhs) noexcept { std::cout << "move constructor called\n"; }
	~CopyElisionTest() { std::cout << "destructor called\n"; }
};

CopyElisionTest func()
{
	CopyElisionTest obj;
		return obj;
}


/*int main()
{
	CopyElisionTest obj = func();
}*/