#include<iostream>
#include<string>
#include<sstream>
#include <vector>

/*template<typename T>
void print(const T& t)
{
	std::cout << t << "\n";
}*/

template<typename T>
std::string to_string_impl(const T& t)
{
	std::stringstream ss;
	ss << t;
	return ss.str();
}

std::vector<std::string> to_string()
{
	return {};
}


/*template<typename P1, typename...Param>
std::vector<std::string> to_string(const P1& p1, const Param&... param)
{
	std::vector<std::string> string_vec;
	string_vec.push_back(to_string_impl(p1));
	const auto remainder = to_string(param...);
	string_vec.insert(string_vec.end(), remainder.begin(), remainder.end());
	return string_vec;
}*/

template<typename...Param>
std::vector<std::string> to_string(const Param&... param)
{
	return { to_string_impl(param)... };
}
int main()
{
	//print(1);
	//print("HelloWorld");
	//print(5.3);
	//std::cout << to_string(123) << "\n";
	const auto vec = to_string("hello", 1, 5.3);
    for(const auto &o:vec)
    {
		std::cout << o << "\n";
    }
}