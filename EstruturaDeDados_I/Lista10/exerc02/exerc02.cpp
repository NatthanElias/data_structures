#include <iostream>
using namespace std;
#include "lista_dupla.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Lista *L1;

    for(int i = 1; i<5; i++)
        insereFinalL(L1, i);

    cout << "Lista sem alteracoes:\n";
    mostraL(L1);

    int val;
    cout << "\nInforme o valor que deseja inserir ao final da lista:";
    cin >> val;
    fflush(stdin);

    insereFinalL(L1, val);
    mostraL(L1);

    cout << "\nRemovendo o primeiro:\n";
    removeInicioL(L1);
    mostraL(L1);

    cout << "\nRemovendo o ultimo:\n";
    removeFinalL(L1);
    mostraL(L1);

    return 0;
}
