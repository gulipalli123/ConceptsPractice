#pragma once
#include<iostream>
#include<memory>

class Base {
public:
	static int x ;
	Base() {
		x++;
	}
	int a;
	std::shared_ptr<int> sp = std::make_shared<int>(++x);
	void print() {
		std::cout << *sp << std::endl;
	}
};
int Base::x = 10;

