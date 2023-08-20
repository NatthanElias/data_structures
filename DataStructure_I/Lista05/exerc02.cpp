#include <iostream>
using namespace std;

#include "fila-dinamica.hpp"

void concatenaF (Fila *f1, Fila *f2, Fila *fConcatenada);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila f1, f2, fConcatenada;
    int tam1, tam2, val;

    cout << "Informe o tamanho da Fila 1: ";
    cin >> tam1;
    fflush(stdin);
    system("cls");

    cout << "Informe o tamanho da Fila 2: ";
    cin >> tam2;
    fflush(stdin);
    system("cls");

    for(int i = 0; i < tam1; i++) {
        cout << "Informe o valor " << i+1 << " para ser adiocionado na Fila 1: ";
        cin >> val;
        fflush(stdin);
        system("cls");

        enfileiraF(&f1,val);

    }

    for(int i = 0; i < tam2; i++) {
        cout << "Informe o valor " << i+1 << " para ser adiocionado na Fila 2: ";
        cin >> val;
        fflush(stdin);
        system("cls");

        enfileiraF(&f2,val);

    }

    concatenaF(&f1, &f2, &fConcatenada);

    system("cls");
    cout << "Fila 1: \n";
    mostraF(&f1);

    cout << "\n\nFila 2: \n";
    mostraF(&f2);

    cout << "\n\nFila concatenada: \n";
    mostraF(&fConcatenada);

    destroiF(&f1);
    destroiF(&f2);
    destroiF(&fConcatenada);

    return EXIT_SUCCESS;
}

void concatenaF (Fila *f1, Fila *f2, Fila *fConcatenada) {
    int val;
    Fila aux1, aux2;

    while(!vaziaF(f1)){
        val=desenfileiraF(f1);
        enfileiraF(fConcatenada, val);

        enfileiraF(&aux1, val);
    }

    while(!vaziaF(f2)){
        val=desenfileiraF(f2);
        enfileiraF(fConcatenada, val);

        enfileiraF(&aux2, val);
    }

    while(!vaziaF(&aux1)){
        val=desenfileiraF(&aux1);
        enfileiraF(f1, val);
    }

    while(!vaziaF(&aux2)){
        val=desenfileiraF(&aux2);
        enfileiraF(f2, val);
    }
}
