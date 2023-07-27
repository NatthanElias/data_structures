#include <iostream>
using namespace std;

#include "filacircular.hpp"
#include "pilha.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila f;
    Pilha aux;
    int tam, val;

    cout << "Informe o tamanho da fila: ";
    cin >> tam;
    fflush(stdin);

    inicializaF(&f, tam);
    inicializaP(&aux, tam);

    for(int i = 0; i < tam; i++) {
        system("cls");
        cout << "Informe o valor inteiro que deseja adicionar: ";
        cin >> val;
        fflush(stdin);

        enfileiraF(&f, val);
    }

    system("cls");
    mostraF(&f);
    cout << "\n\nPressione qualquer botao para inverter a pilha";
    getchar();

    for(int i = 0; i < tam; i++) {
        val = desenfileiraF(&f);
        empilhaP(&aux, val);
    }

    for(int i = 0; i < tam; i++) {
        val = desempilhaP(&aux);
        enfileiraF(&f, val);
    }

    system("cls");
    cout << "FILA INVERTIDA:\n";
    mostraF(&f);
    cout << "\n\nPressione qualquer botao para finalizar o programa";
    getchar();

    return EXIT_SUCCESS;
}
