#include <iostream>
using namespace std;

#include "filacircular.hpp"
#include "pilha.hpp"

int contaPar(Fila f, int tam);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila f;
    int tam, val;

    cout << "Informe o tamanho da fila: ";
    cin >> tam;
    fflush(stdin);

    inicializaF(&f, tam);

    for(int i = 0; i < tam; i++) {
        system("cls");
        cout << "Informe o valor que deseja adicionar: ";
        cin >> val;
        fflush(stdin);

        enfileiraF(&f, val);
    }

    system("cls");
    cout << "Quantidade de pares :" << contaPar(f, tam);

    destroiF(&f);

    return EXIT_SUCCESS;
}

int contaPar(Fila f, int tam) {
    int val, cont = 0;

    for(int i = 0; i < tam; i++) {
        val = desenfileiraF(&f);

        if(val%2==0)
            cont++;
    }

    return cont;
}
