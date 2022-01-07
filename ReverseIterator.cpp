// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<vector>
#include<iostream>


//function return type can be auto
template<typename T1, typename T2>
auto func123(T1 a, T2 b) {
	return a + b;
}
int main()

{
    std::cout << "Hello World124!\n";

	int c = func123(100, 5);
	std::cout << c << std::endl;

	std::vector<int> vec{ 2,4,8,9,5 };
	std::vector<int>::reverse_iterator ritr;
	std::vector<int>::iterator itr;

	for (ritr = vec.rbegin(); ritr != vec.rend(); ritr++)
	{
		std::cout << *ritr << std::endl;
	}
	//ritr = vec.rbegin();
	ritr = find(vec.rbegin(), vec.rend(), 8);
	//ritr = std::vector<int>::reverse_iterator(itr);
	std::cout << *(ritr) << std::endl;

	//itr = std::vector<int>::iterator(ritr);
	itr = ritr.base();
	std::cout << *itr << std::endl;

	//vec.insert(itr, 15);
	//vec.insert(ritr.base(), 15);
	//vec.insert(ritr, 15);  (It does not work)
	for (itr = vec.begin(); itr != vec.end(); itr++)
	{
		std::cout << *itr << std::endl;
	}
	vec = { 1,2,3,4,5 };
	ritr = find(vec.rbegin(), vec.rend(), 3);
	vec.erase(ritr.base());

	for (itr = vec.begin(); itr != vec.end(); itr++)
	{
		std::cout << *itr << std::endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
