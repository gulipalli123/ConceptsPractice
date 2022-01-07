#include<iostream>
#include<memory>
class Cherry
{
public:
	virtual void polish()
	{
		std::cout << "Polished Cherry" << std::endl;
	}
};

class BingCherry : public Cherry
{
public:
	virtual void polish() override
	{
		std::cout << "Polished BingCherry" << std::endl;
	}

};

class CherryTree
{
public:
	virtual Cherry* pick()
	{
		return new Cherry();
	}
};

class BingCherryTree: public CherryTree
{
public:
	virtual BingCherry* pick() override
	{
		auto theCherry = std::make_unique<BingCherry>();
		theCherry->polish();
		return theCherry.release();
	}
};
/*
int main()
{
	BingCherryTree theTree;
	std::unique_ptr<Cherry> theCherry(theTree.pick());
	theCherry->polish();
}*/