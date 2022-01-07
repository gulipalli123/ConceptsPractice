#include<iostream>
#include<list>
#include<algorithm>

template<typename T>
class smartPtr {
public:
	explicit smartPtr(T* t = nullptr)
	{
		ptr = t;
	}
	T& operator*()
	{
		return *ptr;
	}
	T* operator->()
	{
		return ptr;
	}
	~smartPtr()
	{
		delete ptr;
	}
private:
	T* ptr;

	
};

struct abc
{
	int a = 10;
	char b = 'B';
	float c = 10.2;
};

template<typename T>
void custom_add(T a, T b)
{
	std::cout << a + b << std::endl;
}
#if 0
int main()
{
	smartPtr<abc>  P(new abc);
	std::cout << P->a << (*P).a << std::endl;
	std::cout << P->b << (*P).b << std::endl;
	std::cout << P->c << (*P).c << std::endl;
	int a = 5;
	int b = 6;
	float c = 1.2;
	custom_add<int>(a, b);
	custom_add(a, b);
	custom_add<int>(a, c);
	custom_add(a, c);
}
#endif