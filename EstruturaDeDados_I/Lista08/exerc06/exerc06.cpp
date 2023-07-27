#include <iostream>
using namespace std;

#include "lista.hpp"

bool buscaMaisQCinco(No **lista, DadoNoLista valor);
No* naoSeguras(No **l);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No* lista;
    No* aux;

    inicializaL(&lista);
    inicializaL(&aux);

    string teste[10] = {"abcd", "jklmn", "abcd", "jklmn", "jklmn", "jklmn", "jklmn", "jklmn", "54", "rs"};
    for(int i = 0; i < 10; i++)
        insereInicioL(&lista, teste[i]);

    aux = naoSeguras(&lista);

    mostraL(&aux);

    destroiL(&lista);
    destroiL(&aux);

    return 0;
}

bool buscaMaisQCinco(No **lista, DadoNoLista valor) {
    No *n = *lista;
    int cont = 0;

    while (n != NULL)
    {
        if (n->dado == valor)
        {
            cont ++;
            if(cont == 6)
                return true;
        }

        n = n->prox;
    }

    return false;
}

No* naoSeguras(No **l) {
    No* n = *l;

    No* aux;
    inicializaL(&aux);

    bool teste = true;

    while(n != NULL) {
        //cout << n->dado.size();
        if(n->dado.size() < 4 || buscaMaisQCinco(l, n->dado)) {
            if(buscaL(&aux, n->dado)==NULL || teste)
            {
                insereInicioL(&aux, n->dado);
                teste = false;
            }

        }

        n = n->prox;
    }

    return aux;
}
