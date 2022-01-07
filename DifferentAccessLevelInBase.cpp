#include<iostream>

class Secret
{
protected:
	virtual void dontTell()
	{
		std::cout << "I will never tell" << std::endl;
	}
public:
	virtual ~Secret() = default;
};

class Blabber: public Secret
{
public:
	virtual void dontTell()
	{
		std::cout << "I will tell all" << std::endl;
	}
};

/*int main()
{
	Blabber myBlabber;
	myBlabber.dontTell();
	Secret* mySecretPtr = &myBlabber;
	Secret& mySecretRef = myBlabber;
	mySecretPtr->dontTell();
	mySecretRef.dontTell();

}*/