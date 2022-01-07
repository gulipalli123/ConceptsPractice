// DynamicStrings.cpp : Defines the entry point for the application.
//

#include "DynamicStrings.h"
#include <string>
#include <charconv>

using namespace std;

// Use these functions if you want high performant, locale-independent conversions e.g. to serialize and deserialize 
// numerical data to/from human readable formats such as JSON, XML and so on.

// Use an std::string_view instead of const std::string& or a const char* whenever a function requires a read-only
// string as one of its parameters

std::string_view extractExtension(string_view file_name)
{
	return file_name.substr(file_name.rfind('.'));
}

int main()
{
	cout << "Hello CMake." << endl;
	/*std::string out(10, ' ');

	//auto result  = std::to_chars(out.data(), out.data() + out.size(), 12345);
	auto [ptr, ec] = std::to_chars(out.data(), out.data() + out.size(), 12345);		// C++17 structured binding 
	if (ec == std::errc())
	{
		std::cout << "int to str conversion successful\n";
	}
	std::cout << out << "\n";
	std::cout << "ptr = " << *ptr << "\n";

	// float to string
	std::string out1(10, ' ');
	auto [ptr1, ec1] = std::to_chars(out1.data(), out1.data() + out1.size(), 3.141F, chars_format::fixed);
	if (ec1 == std::errc())
	{
		std::cout << "float to str conversion successful\n";
	}
	std::cout << out1 << "\n";
	std::cout << "ptr1 = " << *ptr << "\n";
	
	// string to float
	std::string in("23.54");
	float ft_value;

	auto [ptr2, ec2] = std::from_chars(in.data(), in.data() + in.size(), ft_value, chars_format::general);

	std::cout << ft_value << "\n";

	// Use Raw string literals when you need multiple lines of code or you need to ignore escape sequences

	string file_name = R"(c:\temp\my_file.txt)";
	std::cout << "C++ string: " << extractExtension(file_name) << std::endl;

	const char* c_string = R"(c:\temp\my_file.JSON)";
	std::cout << "C++ string: " << extractExtension(c_string) << std::endl;

	std::cout << "C++ string: " << extractExtension("c:\temp\my_file.XML") << std::endl;*/

	//auto result
	return 0;
}
