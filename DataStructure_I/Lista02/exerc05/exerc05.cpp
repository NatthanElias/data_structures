#include <iostream>
#include <cctype>
using namespace std;

#include "pilha_string.hpp"

//void ler(string *v);
//void empilhar(Pilha p1, Pilha p2, string *v, int tam);
//void desempilhar(Pilha p1, Pilha p2, string *v, int tam);

int main(void) {

    const int tam = 30;
    int cont = 0, cont2 = 0;
    string val ="";
    Pilha p1(tam), p2(tam);

    cout << "Informe a string: ";
    getline(cin, val);
    fflush(stdin);

    for(int i = 0; i < tam; i++) {
        char c = val[i];
        if(isalpha(c)){
            empilhaP(&p1, c);
            cont++;
        }
        else if(isdigit(c)) {
            empilhaP(&p2, c);
            cont2++;
        }
    }

    cout << "Pilha p1: \n";
    for(int i = 0; i < cont; i++)
        cout << desempilhaP(&p1) << ", ";

    cout << "\n\nPilha p2: \n";
    for(int i = 0; i < cont2; i++)
        cout << desempilhaP(&p2) << ", ";

    return 0;
}
