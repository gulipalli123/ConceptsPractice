#include <iostream>

using namespace std;
#pragma optimize("", off)

struct Shape
{
	virtual Shape* Clone() = 0;
	virtual ~Shape() = default;
};

struct  Square: public Shape
{
	virtual Square* Clone() { return new Square(*this); }
	int x = 1;
};

struct Rectangle : public Shape
{
	Rectangle* Clone() { return new Rectangle(*this); }
	int x = 1;
	int y = 2;
};