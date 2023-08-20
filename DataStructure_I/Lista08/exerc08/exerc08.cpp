#include <iostream>
using namespace std;

#include "lista.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No* L1;
    inicializaL(&L1);

    int teste[10] = {1,2,6,7,8,9,9,3,5,2};
    for(int i = 0; i < 10; i++)
        insereInicioL(&L1, teste[i]);

    mostraL(&L1);

    cout << endl << inserePosicao(&L1, 0, 100) << endl;//returna trues
    mostraL(&L1);

    cout << endl << inserePosicao(&L1, 3, 200) << endl;//returna true
    mostraL(&L1);

    destroiL(&L1);

    return 0;
}
