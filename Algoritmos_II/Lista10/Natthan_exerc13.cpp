#include <iostream>
#include <ctime>

using namespace std;

void geraVet(int **ppx, int **s);
void determinaMaiorCont(int ***pppx, int ***s);

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
        **ppx = rand()%14+1;
        cout << *(*ppx)++ << ", ";
    }

    *ppx -= (*i);

    determinaMaiorCont(&ppx, &s);
}

void determinaMaiorCont(int ***pppx, int ***s)
{
    int *i = new int(0);
    int *maior = new int(0);
    int *cont = new int(0);

    for(*i; *i < (***s); (*i)++)
    {
        if((***pppx) > *maior)
            *maior = (***pppx);

        (**pppx)++;
    }

    (**pppx) -= *i;
    *i = 0;

    for(*i; *i < (***s); (*i)++)
    {
        if((***pppx) == *maior)
            (*cont)++;

        (**pppx)++;
    }

    cout << "\nO maior valor é " << *maior << ", ocorreu " << *cont << " vezes";
}
