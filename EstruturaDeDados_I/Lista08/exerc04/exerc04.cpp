#include <iostream>
using namespace std;

#include "lista.hpp"

bool verificaCrescente(No **lista);
bool verificaDecrescente(No **lista);
void verificaOrdem(No **lista);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No *lista;
    No *lista2;

    inicializaL(&lista);
    inicializaL(&lista2);

    char teste[5] = {1,2,3,4,5};
    for(int i = 0; i < 5; i++)
        insereInicioL(&lista, teste[i]);

    mostraL(&lista);

    verificaOrdem(&lista);

    char teste2[5] = {1,2,3,4,5};
    for(int j = 0; j < 5; j++)
        insereFinalL(&lista2, teste2[j]);

    mostraL(&lista2);

    verificaOrdem(&lista2);

    destroiL(&lista);
    destroiL(&lista2);

    return 0;
}

bool verificaCrescente(No **lista) {
    int i = removeInicioL(lista);

    insereInicioL(lista, i);

    int aux;
    No *listaAux;
    inicializaL(&listaAux);

    while(!vaziaL(lista)) {
        aux = removeInicioL(lista);
        insereInicioL(&listaAux, aux);

        if(aux != i)
            return false;

        i++;
    }

    while(!vaziaL(&listaAux)) {
        aux = removeInicioL(&listaAux);
        insereInicioL(lista, aux);
    }

    return true;
}

bool verificaDecrescente(No **lista) {
    int i = removeInicioL(lista);

    insereInicioL(lista, i);

    int aux;
    No *listaAux;
    inicializaL(&listaAux);

    while(!vaziaL(lista)) {
        aux = removeInicioL(lista);
        insereInicioL(&listaAux, aux);

        if(aux != i)
            return false;

        i--;
    }

    while(!vaziaL(&listaAux)) {
        aux = removeInicioL(&listaAux);
        insereInicioL(lista, aux);
    }

    return true;
}

void verificaOrdem(No **lista) {
    if(verificaCrescente(lista))
        cout << "Lista ordenada em ordem crescente\n\n";
    else if(verificaDecrescente(lista))
        cout << "Lista ordenada em ordem decrescente\n\n";
    else
        cout << "Lista nao ordenada\n\n";


}
