#include <iostream>
using namespace std;

#include "lista.hpp"

void retiraPrimeiros(No** l, int x);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No* lista;

    inicializaL(&lista);

    insereInicioL(&lista, 10);
    insereInicioL(&lista, 20);
    insereInicioL(&lista, 30);
    insereInicioL(&lista, 60);
    insereInicioL(&lista, 100);
    insereInicioL(&lista, 105);

    int x;

    cout << "Infome os X valores a serem retirados ";
    cin >> x;
    fflush(stdin);

    if(x > totalL(&lista)) {
        cout << "O valor informado deve ser menor que a quantidade de itens na lista";
        return 0;
    }

    cout << "Antes: ";
    mostraL(&lista);

    retiraPrimeiros(&lista, x);

    cout << "Depois: ";
    mostraL(&lista);

    return 0;
}

void retiraPrimeiros(No** l, int x) {

    for(int i = 0; i < x; i++) {
        int aux = removeInicioL(l);
        insereFinalL(l, aux);
    }
}
