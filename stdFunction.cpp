//class template std::function is a general purpose polymorphic function wrapper. Instances od std::function can store
// copy and invoke any callable target -- functions, lambda expressions, bind expressions, or other function objects
// as well as pointers to member functions and pointers to data members.
// The stored callable object is called target of std::function. If a std::function has no target, it is called empty.
//Invoking the target of an empty std::function results in std::bad_function_call exception being thrown.
#include<functional>
#include<iostream>

struct Foo
{
	Foo(int num) :num_(num) 
	{

	}
	void print_add(int i) const
	{
		std::cout << num_ + i << std::endl;
	}
	int num_;
};

void print_num(int i)
{
	std::cout << i << std::endl;
}

//function object
struct PrintNum
{
	void operator()(int i) const
	{
		std::cout << i << std::endl;
	}
};

/*int main()
{
	//store a free function
	std::function<void(int)> free_func = print_num;
	free_func(12);

	//store a lambda
	std::function<void(int)> lambda_func = [](int i) {print_num(i); };
	lambda_func(234);

	//store the result of a call to std::bind
	std::function<void()> bind_func = std::bind(print_num, 45);
	bind_func();

	//store a call to a member function
	std::function<void(const Foo&, int)> member_func = &Foo::print_add;
	const Foo foo(3244);
	member_func(foo, 3);

	//store a call to a data member accessor
	std::function<int(const Foo&)> data_member_func = &Foo::num_;
	std::cout << data_member_func(foo) << std::endl;

	//store a call to a member function and object
	using std::placeholders::_1;
	std::function<void(int)> object_member_func = std::bind(&Foo::print_add, foo, _1);
	object_member_func(5);

	//store a call to a member function and object ptr
	std::function<void(int)> object_ptr_member_func = std::bind(&Foo::print_add, &foo, _1);
	object_ptr_member_func(10);

	//store a call to a function object
	std::function<void(int)> func_object = PrintNum();
	func_object(24);
}*/