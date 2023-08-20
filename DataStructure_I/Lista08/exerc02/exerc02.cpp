#include <iostream>
using namespace std;

#include "lista.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No *lista;
    No *lista2;

    inicializaL(&lista);
    inicializaL(&lista2);

    insereInicioL(&lista, 10);
    insereInicioL(&lista, 20);
    insereInicioL(&lista, 30);
    insereInicioL(&lista, 60);
    insereInicioL(&lista, 10);
    insereInicioL(&lista, 10);

    insereInicioL(&lista2, 10);
    insereInicioL(&lista2, 20);
    insereInicioL(&lista2, 30);
    insereInicioL(&lista2, 40);
    insereInicioL(&lista2, 40);

    //cout << totalL(&lista);
    //cout << igualL(&lista, &lista2);

    insereFinalL(&lista, 50);
    mostraL(&lista);

    //cout << endl << leFinalL(&lista);

    //cout << endl << removeFinalL(&lista) << endl;

    //cout << endl << lePosicao(&lista, 0) << endl;

    No *lista3;
    inicializaL(&lista3);

    uniao(&lista, &lista2, &lista3);
    mostraL(&lista3);

    destroiL(&lista);
    destroiL(&lista2);

    return 0;
}
