#include <iostream>
using namespace std;

#include "lista.hpp"

void ordena(No **lista);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No* lista;

    inicializaL(&lista);

    int teste[5] = {100,20,8,90,77};
    for(int i = 0; i < 5; i++)
        insereInicioL(&lista,teste[i]);

    mostraL(&lista);

    ordena(&lista);
    mostraL(&lista);

    destroiL(&lista);

    return 0;
}

void ordena(No **lista) {
    No *atual = *lista;
    No *prox = NULL;

    int aux;

    while (atual != NULL)
    {
        prox = atual->prox;

        if(atual->dado > prox->dado) {
            aux = atual->dado;
            atual->dado = prox->dado;
            prox->dado = aux;

            atual = *lista;
            continue;
        }

        atual = atual->prox;
    }
}
