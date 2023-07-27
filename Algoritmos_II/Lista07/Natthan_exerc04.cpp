#include <iostream>
#include <cmath>

using namespace std;

void leitura(int *n);
void verifica(int *n);

int main()
{
    setlocale(LC_ALL, "portuguese");

    int num, *pnum = &num;

    leitura(pnum);
    verifica(pnum);

    return 0;
}

void leitura(int *n)
{
    cout << "Informe um valor inteiro e positivo: ";
    cin >> *n;
}

void verifica(int *n)
{
    int imp = 1, *pimp = &imp;
    int total = 1, *ptotal = &total;

    while(*ptotal < *n)
    {
        *pimp += 2;
        *ptotal += *pimp;
    }

    if((*n == *ptotal || *n == 0))
        cout << "\nÉ quadrado perfeito!";
    else
        cout << "\nNão é quadrado perfeito!";

}
