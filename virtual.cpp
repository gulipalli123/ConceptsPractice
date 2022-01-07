#include <iostream>



class Cat {
	int a = 5;
	int b = 10;
	friend class Dog;
};

class Dog {
	int x = 2;
	int y = 4;
	Cat ct;
public:
	void method(Cat cat)
	{
		std::cout << cat.a << cat.b;
	}
};

int main()
{
	Cat cat;
	Dog dog;
	dog.method(cat);
}