#pragma once
#include<iostream>

class SpreadsheetCell2 {
public:
	SpreadsheetCell2(double x) :mValue(x) {}
	void setValue(double inValue) { mValue = inValue; }
	double getValue() const { return mValue; }
	/*SpreadsheetCell2 operator+(const SpreadsheetCell2& cell) const{
		return SpreadsheetCell2(getValue() + cell.getValue());
	}*/
	//explicit SpreadsheetCell2(int y);
	SpreadsheetCell2 operator+=(const SpreadsheetCell2& rhs) {
		setValue(getValue() + rhs.getValue());
		return *this;
	}
	
private:
	double mValue;
};

//global operator+ 
SpreadsheetCell2 operator+(const SpreadsheetCell2& lhs, const SpreadsheetCell2& rhs) {
	return SpreadsheetCell2(lhs.getValue() + rhs.getValue());
}

//global comparison operator
bool operator==(const SpreadsheetCell2& lhs, const SpreadsheetCell2& rhs) {
	return (lhs.getValue() == rhs.getValue());
}
