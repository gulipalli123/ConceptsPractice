//Providing a special behaviour to a template function/class- suppose we have implemented a sort function which can sort
//any data type and we have used Quicksort internally. Suppose we have a char data type now and we want to sort them and
// we know that quicksort method is not an efficient way to sort chars as they have a small range(0-255) ans instead 
//we can use counting sort.So C++ allows us to write a specialised behaviour to handle chars while the remaining data
//data types can still use the main template function.

//Compiler generates a copy of the template function or class when a new data type is encountered.It first matches with
// the specialized template function or class when a call is made and if does not find a match then it checks with the
// generic template function or class.

#include<iostream>
#include<vector>
template<class T>
void sort(T& data)
{
	std::cout << "template function - applying quicksort\n";
}
template<>
void sort(std::vector<char>& data)
{
	std::cout << "specialized template function - applying counting sort\n";
}
template<class T>
class Test
{
public:
	Test(T data)
	{
		std::cout << "Generic template object" << data << "\n" ;
	}
};
template<>
class Test<char>
{
public:
	Test(char data)
	{
		std::cout << "Specialized template object" << data << "\n";
	}
};

/*int main()
{
	std::vector<int> int_vec{};
	std::vector<char> char_vec{};
	std::vector<float> float_vec{};
	sort(int_vec);
	sort(char_vec);
	sort(float_vec);
	int num = 10;
	Test<int> T1(num);
	Test<char> T2('A');

}*/