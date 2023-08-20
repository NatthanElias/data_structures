#include <iostream>
#include <fstream>
using namespace std;
#include "lista.hpp"

bool verificaInversao(No **L1, No **L2);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    ifstream f;
    f.open("q1-entrada1.txt", ios::in);

    Lista* L1 = new Lista();
    Lista* L2 = new Lista();

    string op;
    int n = 0;

    while(!f.eof()) {
        op = "";

        if(!(f >> op))
            break;

        if(!(f >> n))
            break;

        if(op == "L1") {
            insereFinalL(L1, n);
        } else if(op == "L2") {
            insereFinalL(L2, n);
        }
    }

    cout << "L1 :";
    mostraL(L1);
    cout << "L2: ";
    mostraL(L2);

    if(verificaInversao(&L1->inicio,&L2->inicio))
        cout << "\nLista 1 é o inverso da Lista 2\n\n";
    else
        cout << "\nLista 1 não é o inverso da Lista 2\n\n";

    cout << "L1 :";
    mostraL(L1);
    cout << "L2: ";
    mostraL(L2);

    return 0;
}

bool verificaInversao(No **L1, No **L2) {
    Lista* aux = new Lista();
    Lista* aux2 = new Lista();
    Lista* aux3 = new Lista();
    Lista* aux4 = new Lista();
    Lista* aux5 = new Lista();

    int cont1 = 0,  cont2 = 0;
    No* n = new No();
    No* n2 = new No();

    bool teste = true;


    if(!L1 || !L2)
        return false;

    while((*L1) != NULL) {
        insereFinalL(aux5, (*L1)->dado);

        *L1 = (*L1)->prox;
        cont1++;
    }

    (*L1) = aux5->inicio;

    while((*L2) != NULL) {
        insereFinalL(aux4, (*L2)->dado);

        *L2 = (*L2)->prox;
        cont2++;
    }

    (*L2) = aux4->inicio;

    if(cont1!=cont2)
        return false;

    while((*L1) != NULL) {
        insereInicioL(aux, (*L1)->dado);

        *L1 = (*L1)->prox;
    }

    while((*L2) != NULL) {
        n = removeInicioL(aux);
        insereInicioL(aux2, n->dado);

        insereFinalL(aux3, (*L2)->dado);

        if((*L2)->dado!= n->dado)
            teste =  false;

        *L2 = (*L2)->prox;
    }

    (*L1) = aux2->inicio;
    (*L2) = aux3->inicio;

    if(!teste)
        return false;

    return true;
}
