#include <iostream>

using namespace std;

int fib(int n);

int main()
{
    setlocale(LC_ALL, "portuguese");

    int num1 = 20;

    for(int i = 0; i < num1; i++)
        cout << fib(i) << ", ";
    cout << "\n";

    return 0;
}

int fib(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return fib(n-1) + fib(n-2);
}


