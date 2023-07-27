#include <iostream>
using namespace std;

#include "fila-dinamica.hpp"

void separaF(int n, Fila *f1, Fila *f2);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila f1, f2;
    int n, tam, val;

    cout << "Informe o tamanho da Fila 1: ";
    cin >> tam;
    fflush(stdin);
    system("cls");

    for(int i = 0; i < tam; i++) {
        cout << "Informe o valor " << i+1 << " para ser adiocionado na Fila 1: ";
        cin >> val;
        fflush(stdin);
        system("cls");

        enfileiraF(&f1,val);
    }

    mostraF(&f1);
    cout << "\nInforme o valor onde deseja cortar a fila";
    cin >> n;
    fflush(stdin);
    system("cls");

    separaF(n, &f1, &f2);

    mostraF(&f1);
    mostraF(&f2);

    destroiF(&f1);
    destroiF(&f2);

    return EXIT_SUCCESS;
}

void separaF(int n, Fila *f1, Fila *f2) {
    Fila aux;
    int val;

    while(!vaziaF(f1)) {
        val = desenfileiraF(f1);
        enfileiraF(&aux, val);

        if(val == n) {
            while(!vaziaF(f1)) {
                val = desenfileiraF(f1);
                enfileiraF(f2, val);
            }
        }
    }

    while(!vaziaF(&aux)) {
        val = desenfileiraF(&aux);
        enfileiraF(f1, val);
    }
}
