#include <iostream>
using namespace std;

#include "lista.hpp"

No* interseccao(No** lista1, No** lista2);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No *L1, *L2, *L3;

    inicializaL(&L1);
    inicializaL(&L2);
    inicializaL(&L3);

    int teste[10] = {2, 5, 3, 9, 9, 8, 7, 6, 2, 1};
    for(int i = 0; i < 10; i++) {
        insereInicioL(&L1, teste[i]);
    }

    int teste2[7] = {20, 30, 100, 6, 1, 5, 9};
    for(int i = 0; i < 7; i++) {
        insereInicioL(&L2, teste2[i]);
    }

    L3 = interseccao(&L1, &L2);
    mostraL(&L3);

    destroiL(&L1);
    destroiL(&L2);
    destroiL(&L3);

    return 0;
}

No* interseccao(No** lista1, No** lista2) {
    No* n1 = *lista1;
    No* n2 = *lista2;

    No* listaSaida;
    inicializaL(&listaSaida);

    while(n1 != NULL) {

        n2 = *lista2;
        while(n2 != NULL) {
            if(n1->dado == n2->dado && !buscaL(&listaSaida, n2->dado))
                insereInicioL(&listaSaida, n2->dado);

            n2 = n2->prox;
        }
        n1 = n1->prox;
    }

    return listaSaida;
}
