#include<iostream>
#include <initializer_list>
class SpreadsheetCell1 {
public:
	void print() {
		std::cout << "spreadsheet cell class" << "\n";
	}
};

class Foo {
public:
	Foo(double value);
private:
	double mValue;
};

Foo::Foo(double value) :mValue(value) {
	std::cout << "Foo::mValue: " << mValue << "\n";
}

class MyClass {
public:
	MyClass(double value);
	MyClass(int x, int y) {
		mValue = x;
		std::cout << "2nd Constructor this is-> " << this << std::endl;
		std::cout << "x = " << x << "y = " << y << "\n";
	}
private:
	//Foo mFoo;
	double mValue;

};

// Delegating constructor
MyClass::MyClass(double value) : MyClass(static_cast<int>(value) + 1, static_cast<int>(value) - 1) {
	mValue = value;
	std::cout << "first constructor this is -> " << this << std::endl;
}
//Constructor Initializer
/*MyClass::MyClass(double value): mValue(value), mFoo(mValue) {
	std::cout << "MyClass::mValue: " << mValue << "\n";
}*/
//Initializer-List Constructors
class EvenSequence {
public:
	EvenSequence(std::initializer_list<double> args) {
		if (args.size() % 2 != 0)
			throw std::invalid_argument("initializer list should contain even number of elements");
		mSequence.reserve(args.size());
		for (const auto& value : args) {
			mSequence.push_back(value);
		}
	}

	void dump() const {
		for (const auto& value : mSequence)
			std::cout << value << ", ";
	}
private:
	std::vector<double> mSequence;
};