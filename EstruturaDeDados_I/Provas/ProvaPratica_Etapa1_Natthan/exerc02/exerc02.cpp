#include <iostream>
using namespace std;

#include "pilha-dinamica.hpp"
#include "fila-dinamica.hpp"

void inverterKElementos(Pilha *p, int k);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int k, val, cont = 0;
    Pilha p1, aux;

    int teste[6] = {60,50,40,30,20,10};

    for(int i = 0 ; i < 6; i++) {
        empilhaP(&p1, teste[i]);
    }

    cout << "Informe o numero de elementos a serem invertidos";
    cin >> k;
    fflush(stdin);

    while(!vaziaP(&p1)) {
        val = desempilhaP(&p1);
        empilhaP(&aux, val);
        cont++;
    }

    while(!vaziaP(&aux)) {
        val = desempilhaP(&aux);
        empilhaP(&p1, val);
    }

    if(k > cont) {
        system("cls");
        cout << "ERRO: NUMERO INFORMADO MAIOR QUE O TOTAL DA FILA";
        getchar();
        return 0;

    }

    inverterKElementos(&p1, k);
    mostraP(&p1);

    return 0;
}

void inverterKElementos(Pilha *p, int k) {
    Fila aux, aux2;
    Pilha p2;
    int valor, i = 0;

    while(!vaziaP(p)) {
        valor = desempilhaP(p);
        enfileiraF(&aux2, valor);
    }

    while(!vaziaF(&aux2)) {
        valor = desenfileiraF(&aux2);
        empilhaP(&p2, valor);
    }

    while(i < k) {
        valor = desempilhaP(&p2);
        enfileiraF(&aux, valor);

        i++;
    }

    while(!vaziaF(&aux)) {
        valor = desenfileiraF(&aux);
        empilhaP(&p2, valor);
    }

    while(!vaziaP(&p2))
    {
        valor = desempilhaP(&p2);
        empilhaP(p, valor);
    }
}
