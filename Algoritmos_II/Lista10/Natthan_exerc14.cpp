#include <iostream>
#include <ctime>

using namespace std;

void geraVet(int **ppx, int **s);
void troca(int ***pppx, int ***s);

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    int *tam = new int(10);
    int *vet = new int[*tam];

    geraVet(&vet, &tam);

    cin.get();
}

void geraVet(int **ppx, int **s)
{
    int *i = new int(0);

    cout << "Vet: ";
    for(*i; *i < **s; (*i)++)
    {
        **ppx = rand()%30+25;
        cout << *(*ppx)++ << ", ";
    }
    (*ppx)--;

    troca(&ppx, &s);
}

void troca(int ***pppx, int ***s)
{
    int *i = new int(0);
    int *aux = new int[***s];

    cout << "\n\nVet trocado: ";
    for(*i; *i < (***s); (*i)++)
    {
        *aux = (***pppx);
        //cout << *aux << ", ";
        (**pppx)--;
        aux++;
    }

    aux -= *i;
    *i = 0;

    for(*i; *i < (***s); (*i)++)
    {
        (***pppx) = *aux;
        cout <<  (***pppx) << ", ";
        (**pppx)++;
        aux++;
    }

}
