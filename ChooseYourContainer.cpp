#include <iostream>




#include <iostream>
#include <vector>

int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return n;
   // if (fib[n] != 0)
      //  return fib[n];
    return  fibonacci(n - 1) + fibonacci(n - 2);

}
int main()
{
    int n;
    std::cin >> n;
    /*std::vector<int> fib_ser(n+1, 0);
    std::cout << fib_ser.size() << std::endl;;
    for (auto i : fib_ser)
    {
        std::cout << i << std::endl;
    }*/
    //fib_ser.resize(n);
    //fib_ser.assign(n, 0);
    std::cout << fibonacci(n) << std::endl;

    return 0;
}