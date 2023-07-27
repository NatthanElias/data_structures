#include <iostream>
using namespace std;
#include "lista_dupla_string.hpp"

void percursoInverso(Lista *lista);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Lista *lista = new Lista();

    insereFinalL(lista, "direita");
    insereFinalL(lista, "baixo");
    insereFinalL(lista, "direita");
    insereFinalL(lista, "cima");
    insereFinalL(lista, "direita");
    insereFinalL(lista, "baixo");
    insereFinalL(lista, "direita");
    insereFinalL(lista, "direita");
    insereFinalL(lista, "direita");
    insereFinalL(lista, "cima");
    insereFinalL(lista, "direita");
    insereFinalL(lista, "direita");
    insereFinalL(lista, "cima");
    insereFinalL(lista, "cima");
    insereFinalL(lista, "cima");
    insereFinalL(lista, "cima");
    insereFinalL(lista, "esquerda");
    insereFinalL(lista, "cima");
    insereFinalL(lista, "direita");
    insereFinalL(lista, "direita");

    mostraL(lista);

    percursoInverso(lista);

    mostraL(lista);
    //mostrarInversoL(lista);

    delete(lista);

    return 0;
}

void percursoInverso(Lista *lista) {
    No* no = lista->inicio;

    while(no!= NULL) {
        if(no->dado == "direita")
            no->dado = "esquerda";
        else if(no->dado == "esquerda")
            no->dado = "direita";
        else if(no->dado == "cima")
            no->dado = "baixo";
        else if(no->dado == "baixo")
            no->dado = "cima";

        no = no->prox;
    }

    inverteL(lista);
}
