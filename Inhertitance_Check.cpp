#include <iostream>
#include <string_view>
#include <string>
#include <optional>
#include <vector>
using namespace std;

class SpreadsheetCell
{
public:
	virtual ~SpreadsheetCell() = default;
	virtual void set(std::string inString) = 0;
	virtual std::string getString() const = 0;
};

class DoubleSpreadsheetCell;
class StringSpreadsheetCell : public SpreadsheetCell
{
public:
	StringSpreadsheetCell() = default;
	StringSpreadsheetCell(const DoubleSpreadsheetCell& inDoubleCell);
	virtual void set(std::string inString) override;
	virtual std::string getString() const override;
	//StringSpreadsheetCell operator+(const StringSpreadsheetCell& lhs, const StringSpreadsheetCell& rhs);
private:
	std::string mValue;
};

void StringSpreadsheetCell::set(std::string inString)
{
	mValue = inString;
}
std::string StringSpreadsheetCell::getString() const
{
	return mValue;
}

class DoubleSpreadsheetCell : public SpreadsheetCell
{
public:
	virtual void set(double inDouble);
	virtual void set(std::string inString) override;
	virtual std::string getString() const override;
private:
	static std::string doubleToString(double inDouble);
	static double stringToDouble(std::string inString);
	double mValue = 0;
};

void DoubleSpreadsheetCell::set(double inDouble)
{
	mValue = inDouble;
}
void DoubleSpreadsheetCell::set(std::string inString)
{
	mValue = stringToDouble(inString);
}
std::string DoubleSpreadsheetCell::getString() const
{
	return doubleToString(mValue);
}

std::string DoubleSpreadsheetCell::doubleToString(double inDouble)
{
	return std::to_string(inDouble);
}

double DoubleSpreadsheetCell::stringToDouble(std::string inString)
{
	return strtod(inString.data(), nullptr);
}

StringSpreadsheetCell::StringSpreadsheetCell(const DoubleSpreadsheetCell& inDoubleCell)
{
	mValue = inDoubleCell.getString();
}
StringSpreadsheetCell operator+(const StringSpreadsheetCell& lhs,
	const StringSpreadsheetCell& rhs)
{
	StringSpreadsheetCell newCell;
	newCell.set(lhs.getString() + rhs.getString());
	return newCell;
}
/*int main()
{
	std::vector<unique_ptr<SpreadsheetCell>> cellArray;

	cellArray.push_back(std::make_unique<StringSpreadsheetCell>());
	cellArray.push_back(std::make_unique<DoubleSpreadsheetCell>());

	cellArray[0]->set("hello");
	cellArray[1]->set("1.21");

	std::cout << cellArray[0]->getString() << std::endl;
	std::cout << cellArray[1]->getString() << std::endl;
	DoubleSpreadsheetCell myDbl;
	myDbl.set(8.4);
	//
	StringSpreadsheetCell result = myDbl + myDbl;
	//std::cout << myDbl.getString() << std::endl;
	
}*/
