#include <iostream>
using namespace std;

#include "filacircular_03.hpp"
#include "pilha_03.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila f;
    Pilha p;
    string str;
    bool palindromo = true;

    cout << "Informe a palavra: ";
    getline(cin, str);
    fflush(stdin);
    system("cls");

    inicializaF(&f, str.size());
    inicializaP(&p, str.size());

    for(int i = 0; i < str.size(); i++) {
        enfileiraF(&f, str[i]);
        empilhaP(&p, str[i]);
    }

    for(int i = 0; i < str.size(); i++) {
        if(desenfileiraF(&f) != desempilhaP(&p)) {
            palindromo = false;
            break;
        }
    }

    if(!palindromo)
        cout << "A palavra " << str << " não é um palíndromo!\n";
    else
        cout << "A palavra " << str << " é um palíndromo!\n";

    destroiF(&f);
    destroiP(&p);

    return EXIT_SUCCESS;
}
