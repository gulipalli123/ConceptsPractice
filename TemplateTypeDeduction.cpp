#include<iostream>
using namespace std;
#include<vector>
//template<typename T>
//void Foo(T t) {}

template<typename T>
void Foo(T& t) {
	//T x = 2;  //  T int const
	//x++;
}

//template<typename T>
//void Foo(T* t) {}

template<typename T>
bool Equals(T lhs, T rhs)
{
	return lhs == rhs;
}
template<typename It>
bool Contains(It first, It last, bool(*pred)(const typename It::value_type&))
{
	for (; first != last; ++first)
	{
		if (pred(*first))
		{
			return true;
		}
	}
	return false;
}

template<typename It, typename Pred>
bool ContainsSimplified(It first, It last, Pred pred)
{
	for (; first != last; ++first)
	{
		if (pred(*first))
		{
			return true;
		}
	}
	return false;
}

bool HasATwo(const int& i) { return i == 2; }

//functors
struct S {
	bool operator()(int const& i) { return i == 2; }
};

/*int main()
{
	//Foo(42);
	const int x = 42;
	Foo(x);
	//Foo(&x);
	Equals(1, static_cast<int>(1.0f)); // allowing compiler to deduce the types
	Equals<int>(1, 1.0f);  //forcing compiler to take args as ints
	vector<int> v = { 1,2,3,4,5 };
	Contains(v.begin(), v.end(), HasATwo);
	Contains(v.begin(), v.end(), [](const int& i) {return i == 2; });
	//Contains(v.begin(), v.end(), S());
	ContainsSimplified(v.begin(), v.end(), S());
	return 0;
}*/