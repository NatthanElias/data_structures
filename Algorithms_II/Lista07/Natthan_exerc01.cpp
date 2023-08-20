#include <iostream>

using namespace std;

void leitura(int *p, int v);

int main()
{
    setlocale(LC_ALL, "portuguese");
    cout << fixed;
    cout.precision(2);


    int tempo;
    int *ptempo = &tempo;
    int volta = 1;

    leitura(ptempo, volta);

    cout << "O melhor tempo é: " << *ptempo << " segundos.";

    return 0;
}

void leitura(int *p, int v)
{
    int m, *pm = &m;

    while(*p)
    {
        cout << "Informe o tempo(em segundos) na volta " << v++ << ": ";
        cin >> *pm;

        if(*pm == 0)
            return;
        else if(*pm < *p)
            *p = *pm;
    }
}
