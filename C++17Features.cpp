#include<iostream>
#include<string_view>
//1.structured binding
//auto [a,b,c] =<expression>;
//Can be used to split a structure into multiple variables
//Works with c-style arrays, simple classes and structs with 
//all public member data
//All fixed-size containers in C++17 have structure binding support
//(for example: std::tuple, std::pair and std::array)
#include<map>
#include<string>
#include<utility>
int& add_local(std::map<std::string, int>vars, const std::string new_var_name)
{
	std::pair<std::map<std::string, int>::iterator, bool>
		new_var = vars.insert(std::make_pair(new_var_name, 0));
	if (new_var.second == false)
		throw std::runtime_error("variable already exists");
	else
		return new_var.first->second;
}
//C++17 Structured binding
int& add_local_cpp14(std::map<std::string, int>vars, const std::string new_var_name)
{
	if (auto[itr, success]= vars.insert(std::make_pair(new_var_name, 0)); success == false)
		throw std::runtime_error("variable already exists");
	else
	{
		//return itr->second;
		auto [key, value] = *itr;
	}
		
}
//if-init expressions
//if(auto[key, value]= *my_map.begin(); key == "mykey"){}
// also works for switch conditions
// declarations are valid for else block also

//std::string_view
//Provides a light weight std::string like view into an array of characters
//It can be constructed from a const char*(which may require a call to strlen() internally
// or automatically converted to from an std::string or
void use_string(std::string_view sv) {

}
//use_string("helloworld");
//use_string(some_std_string);

/*int main()
{
	std::map<std::string, int> locals;
	int& i = add_local(locals, "my_var");
	i = 5;
	use_string("helloworld");
	return i;

}*/