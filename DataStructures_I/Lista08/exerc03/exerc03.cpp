#include <iostream>
using namespace std;

#include "lista_char.hpp"

void inverteChar(No **lista);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No *lista;

    inicializaL(&lista);

    char teste[5] = {'A', 'E', 'I', 'O', 'U'};
    for(int i = 0; i < 5; i++)
        insereFinalL(&lista, teste[i]);

    cout << "Antes: ";
    mostraL(&lista);

    inverteChar(&lista);

    cout << "Depois: ";
    mostraL(&lista);

    destroiL(&lista);

    return 0;
}

void inverteChar(No** lista) {
    No *aux;
    inicializaL(&aux);

    char c;

    while(!vaziaL(lista)) {
        c = removeFinalL(lista);
        insereInicioL(&aux, c);
    }

    while(!vaziaL(&aux)) {
        c = removeFinalL(&aux);
        insereFinalL(lista, c);
    }

    destroiL(&aux);
}
