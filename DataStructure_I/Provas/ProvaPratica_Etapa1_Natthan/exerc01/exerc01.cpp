#include <iostream>
using namespace std;

#include "filacircular.hpp"

void removeRepetidos(Fila *f);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int tam;
    Fila f1;

    cout << "Informe o tamanho da fila: ";
    cin >> tam;

    int teste[tam] = {5,5,20,10,2,1,30,1}; // tam = 8

    inicializaF(&f1 ,tam);

    for(int i = 0; i < tam; i++) {
        enfileiraF(&f1, teste[i]);
    }

    removeRepetidos(&f1);
    mostraF(&f1);

    destroiF(&f1);
    return 0;
}

void removeRepetidos(Fila *f) {
    Fila aux;

    inicializaF(&aux, 20);

    while(!vaziaF(f)) {
        int x = desenfileiraF(f);
        //enfileiraF(&aux, x);
        if(!buscaF(&aux,x)) {
            enfileiraF(&aux, x);
            //cout << "teste ";
        }
        //enfileiraF(f,x);
    }

    /*while(!vaziaF(f)) {
        desenfileiraF(f);
    }*/

    while(!vaziaF(&aux)) {
        int z = desenfileiraF(&aux);
        enfileiraF(f,z);
    }

    destroiF(&aux);

}
