#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
#include "lista_float.hpp"

float media(Lista* lista);
float somaQuadradoDif(Lista* lista, float media);
float calcDesvioPadrao(Lista* lista);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    cout << fixed;
    cout.precision(2);

    ifstream f;
    f.open("entrada.txt", ios::in);

    Lista* L1 = new Lista();

    float n = 0.00;

    while(!f.eof()) {

        if(!(f >> n))
            break;

        insereFinalL(L1, n);
    }
    mostraL(L1);

    cout << calcDesvioPadrao(L1);

    return 0;
}

float media(Lista* lista) {
    float soma = 0.00;
    No* n = lista->inicio;

    while(n!=NULL) {
        soma += n->dado;

        n = n->prox;
    }

    return soma/lista->tamanho;
}

float somaQuadradoDif(Lista* lista, float media) {
    float soma = 0.00;
    No* n = lista->inicio;

    while(n!=NULL) {
        soma += (n->dado - media)*(n->dado - media);

        n = n->prox;
    }

    return soma/lista->tamanho;
}

float calcDesvioPadrao(Lista* lista) {

    return sqrt(somaQuadradoDif(lista, media(lista)));
}
