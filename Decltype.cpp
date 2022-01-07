// decltype is like a function that returns the type of an expression.
// This feature is very useful in places where an explicit type is needed.
//first of all as a template parameter for class templates.
//
#include <vector>

int f(int x)
{
	return x - 3;
}
template<typename Vector1, typename Vector2>
auto operator+(const Vector1& v1, const Vector2& v2)->std::vector<decltype(v1[0] + v2[0])>;

int main()
{
	int x = 10;
	//The below use of decltype is too verobse, thus not very useful in this context.
	decltype(f(x) + x * 3) a = f(x) + x * 3;

	//The feature is very important where explicit type is needed; first of all
	// as a template parameter for class templates.
	// we can e.g. declare a vector whose elements can hold the sum of two other vector's
	// elements e.g. the type of v1[0] + v2[0]. This allows us t o express the 
	//appropriate return type for the sum of two vectors of different types.
	
}