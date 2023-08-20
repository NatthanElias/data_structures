#include <iostream>

using namespace std;

float calcula(int n);

int main()
{
    setlocale(LC_ALL, "portuguese");

    int num1;

    do
    {
        cout << "Informe um numero inteiro maior ou igual a 1: ";
        cin >> num1;
    }while(num1 < 1);

    cout << calcula(num1) << "\n";

    return 0;
}

float calcula(int n)
{
    if(n == 1)
        return 1;
    else
        return (float)1/n + calcula(n - 1);
}


