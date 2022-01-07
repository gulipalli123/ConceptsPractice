#pragma once
#include<iostream>


class FooNew;
class Bar {
public:
	void processFooNew(const FooNew&);
};

class FooNew {
	int mValue;
public:
	FooNew(int value) : mValue(value)
	{
	}
	friend void Bar::processFooNew(const FooNew& foo);
	//friend class Bar;
};

void Bar::processFooNew(const FooNew& foo) {
	std::cout << "Accessing foo.mValue in Bar class = " << foo.mValue << "\n";
}
