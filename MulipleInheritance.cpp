#include<iostream>

class Book
{
public:
	Book() {};
	virtual std::string getDescription() const
	{
		return "Book";
	}
	virtual int getHeight() const
	{
		return 120;
	}
	virtual ~Book() = default;
};

class Paperback : public Book
{
public:
	std::string getDescription() const
	{
		return "Paperback" + Book::getDescription();
	}
	/*int getHeight() const
	{
		return 120 + Book::getHeight();
	}*/
	virtual ~Paperback() = default;
};

class Romance : public Paperback
{
public:
	std::string getDescription() const
	{
		return "Romance" + Paperback::getDescription();
	}
	int getHeight() const
	{
		return  60 + Paperback::getHeight();
	}
};

void downcasting(Book* bookptr)
{
	Paperback* ptr = dynamic_cast<Paperback*>(bookptr);
	if(ptr != nullptr)
		std::cout << ptr->getDescription();
}

/*int main()
{
	Romance novel;
	Book book;
	std::cout << book.getDescription() << std::endl;
	std::cout << novel.getHeight() << std::endl;
	std::cout << novel.getDescription() << std::endl;
	Paperback pback;
	downcasting(&novel);


	return 0;
}*/
