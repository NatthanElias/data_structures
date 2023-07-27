#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

void desenhaMatriz(int **pt, int **ptam, char **pmat);

int main()
{
    int *tam = new int;

    cout << "Informe o tamanho dos lados do quadrado: ";
    cin >> *tam;

    int *t = new int((*tam)*(*tam));
    char *mat = new char[*t];

    desenhaMatriz(&t, &tam, &mat);

    return 0;
}

void desenhaMatriz(int **pt, int **ptam, char **pmat)
{
    int *i = new int(0);

    for(*i; *i < **pt; (*i)++)
    {
        if(*i < **ptam || *i >= ((**pt)-(**ptam))|| *i%**ptam==0 || (((*i+1)%**ptam))==0 || *i%(**ptam+1)==0 || *i%(**ptam-1)==0)
            **pmat = '*';
        else
            **pmat = ' ';

        (*pmat)++;
    }
    (*pmat) -= *i;
    *i=0;

    while(**pt > 0)
    {
        cout << **pmat << " ";
        (*pmat)++;
        (**pt)--;
        if(**pt%**ptam ==0)
            cout << "\n";
    }
}
