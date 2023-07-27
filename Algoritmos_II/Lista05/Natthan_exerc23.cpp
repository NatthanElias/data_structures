#include <iostream>

using namespace std;

int calcula(int n);

int main()
{
    setlocale(LC_ALL, "portuguese");

    int num1;

    do
    {
        cout << "Informe um numero inteiro menor que 999: ";
        cin >> num1;
    }while(num1 >= 999);

    cout << "\nResultado: " << calcula(num1) << "\n";

    return 0;
}

int calcula(int n)
{
    if(n/10 == 0)
       return n;
    else
        return n%10 + calcula(n/10);
}
