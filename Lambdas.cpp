#include<iostream>
#include<vector>
#include<algorithm>

auto func = [&](int a) {std::cout << a << std::endl; };

/*int main()
{
	std::vector<int> v1{ 5,3,6,4,8,6,7,2,3,3,3 };
	std::vector<int> v2{ 11,19,17,3,20,15,16 };
	int x = 2;
	auto itr = std::find_if(v1.begin(), v1.end(), [&x](int a) {return x == a; });
	if (itr != v1.end())
		std::cout << "element is present in v1\n";
	else
		std::cout << "element is not present in v1\n";
	{
		int count = std::count_if(v1.begin(), v1.end(), [&](int a) {return v2[3] == a; });
		std::cout << "The number of duplicates = " << count << "\n";
	}
	func(5);
}*/