#include <iostream>

using namespace std;

void leia(int &n);
void leiaVerif(int &v);
int contadorVerif(int n, int v, int c);

int main()
{
    setlocale(LC_ALL, "portuguese");

    int num1, num2, cont = 0;

    leia(num1);
    leiaVerif(num2);
    cout << "Resposta:" << contadorVerif(num1, num2, cont) << "\n";

    return 0;
}

void leia(int &n)
{
    do
    {
        cout << "Informe um número inteiro qualquer maior que 10: ";
        cin >> n;
    }while (n<10);

}

void leiaVerif(int &v)
{
    do
    {
        cout << "Informe um número verificador inteiro entre 1 e 9 (inclusive 1 e 9): ";
        cin >> v;
    }while(v <= 1 || v >= 9);
}

int contadorVerif(int n, int v, int c)
{
    if(n == 0)
        return 0;

    if(n%10 == v)
        c = 1;
    else
        c = 0;

    return c + contadorVerif(n/10, v, c);
}

