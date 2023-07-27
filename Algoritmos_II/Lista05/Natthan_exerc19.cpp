#include <iostream>

using namespace std;

int mdc(int n1, int n2);

int main()
{
    setlocale(LC_ALL, "portuguese");

    int num1, num2,aux;

    cout << "Informe um numero inteiro e positivo: ";
    cin >> num1;

    cout << "Informe outro numero inteiro e positivo: ";
    cin >> num2;

    if(num2 > num1)
    {
        aux = num1;
        num1 = num2;
        num2 = aux;
    }
    else
    {
        aux = num2;
        num2 = num1;
        num1 = aux;
    }

    cout << "\nO MDC dos numero informados é "<< mdc(num1, num2) << "\n";

    return 0;
}

int mdc(int n1, int n2)
{
    if(n1%n2 == 0)
        return n2;
    else
        return mdc(n2, n1%n2);
}
