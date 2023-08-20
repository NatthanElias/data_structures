#include <iostream>

using namespace std;

int calcula(int n1, int n2);

int main()
{
    setlocale(LC_ALL, "portuguese");

    int num1, num2;

    cout << "Informe uma base inteira e positiva: ";
    cin >> num1;

    cout << "Informe um expoente inteiro e positivo: ";
    cin >> num2;


    cout << "\nA base " << num1 << " elavada a " << num2 << " é " << calcula(num1, num2) << "\n";

    return 0;
}

int calcula(int n1, int n2)
{
    if(n2 == 1)
        return n1;
    else
        return n1 * calcula(n1,--n2);
}

