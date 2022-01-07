// Templates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Different type of polymorphism
//Inheritance -> subtype, runtime, dynamic polymorphism
//templates -> generics, compile-time polymorphism, parametric polymorphism
//overloading -> ad-hoc polymorphism
//casting ->coercion polymorphism

//Templates take the concept of parameterization a step further to allow you to parameterize on types as well as values.
// Types in C++ include priimitive types such as int, double etc and user-defined types  such user-deifned classes/ strructs
//With templates you can writecode that is notonly independent of values but also indepenmdent of types of those values.
//e.g. instead of writing separate stack classes for ints, chars, we can write one stack class with templates that is independent of type.
// Writing a classe template without specifying one or more types and clients then instantiate the template by specifying the types they want to use
// is callled generic programming.
// Thge biggest advantage of generic programming is type safety.
//Type safety means that you use the types correctly and, therefore, avoid unsafe casts and unions. 
//Within a class definition, the compiler interprets Grid as Grid<T> where needed( Grid is class name)
//However outside a class definition you need to use Grid<T>.
// Template requires you to put the implementation of the methods in the header file itself, because the compiler
// needs to know the complete definition, including the definition of methods, before it can create the instance of the template.
//However some ways around we can overcome this restriction.
// If you don't instantiate a class template for any types in your program, then the class method definitions are never compiled.

//Template Requirements on Types
// If you attaempt to instantiate a template with a type that does not support all operations(e.g. assignment, copy construction, destruction),
//used by the template in your particular program, the code will not compile.

//Class Templates:
//class templates define a class where the 
//   1. types of the variables, 2. return types of methods and/or 3. parameteres of the methods are specified as parameters.

//Distributing Template code between files
//Normally we put the class definitons in a header file and method definitions in a source file.
// Code that creats or uses objects of the class #include the header file and obtain access to the method code via the linker.
//Templates don't work that way. Because they are templates for the compiler to generate the actual methods for the instiated types, both class definitioins and
// method definitons must be avaialble to the compiler in any source file that uses them. There are several mechanisms to obtain this inclussion.

#include <iostream>
#include <vector>

//coding without templates
class GamePiece
{
public:
    virtual std::unique_ptr<GamePiece> clone() const = 0;
};

class ChessPiece : public GamePiece
{
    virtual std::unique_ptr<GamePiece> clone() const override;
};

std::unique_ptr<GamePiece> ChessPiece::clone() const
{
    return std::make_unique<ChessPiece>(*this);
}
//The implementation of gameboard uses a vector of vectors of unique_ptrs to store the gamepieces
class GameBoard
{
public:
    explicit GameBoard(size_t width = kDefaultWidth, size_t height = kDefaultHeight);
    GameBoard(const GameBoard& src);
    GameBoard& operator=(const GameBoard& rhs);
    virtual ~GameBoard() = default;

    GameBoard(GameBoard&& src) = default;
    GameBoard& operator= (GameBoard&& rhs) = default;

    std::unique_ptr<GamePiece>& at(size_t x, size_t y);
    const std::unique_ptr<GamePiece>& at(size_t x, size_t y) const;

    size_t getHeight() { return mHeight; }
    size_t getWidth() { return mWidth; }

    static const size_t kDefaultWidth = 10;
    static const size_t kDefaultHeight = 10;

    friend void swap(GameBoard& first, GameBoard& second) noexcept;

private:
    void verifyCoordinate(size_t x, size_t y) const;
    std::vector<std::vector<std::unique_ptr<GamePiece>>> mCells;
    size_t mWidth, mHeight;
};

GameBoard::GameBoard(size_t width, size_t height): mWidth(width), mHeight(height)
{
    mCells.resize(mWidth);
    for (auto& column : mCells)
    {
        column.resize(mHeight);
    }
}

GameBoard::GameBoard(const GameBoard& src) : mWidth(src.mWidth), mHeight(src.mHeight)
{
    for (size_t i = 0; i < mWidth; i++)
    {
        for (size_t j = 0; j < mHeight; j++)
        {
            if(src.mCells[i][j])
                mCells[i][j] = src.mCells[i][j]->clone();
        }
    }

}

void GameBoard::verifyCoordinate(size_t x, size_t y) const
{
    if (x >= mWidth || y >= mHeight)
    {
        throw std::out_of_range("values out of range");
    }
}

void swap(GameBoard)
int main()
{
    std::cout << " templates \n";
    return 0;
}