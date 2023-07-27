#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

void ler(int **pbase);
void gera_piramide(int **pbase);

main()
{
    setlocale(LC_ALL,"Portuguese");
    int *altura = new int;
    ler(&altura);
    gera_piramide(&altura);
}

void ler(int **pbase)
{
    do
    {
        system("cls");
        cout << "Informe o número de caracteres da base da pirâmide: ";
        cin >> **pbase;
        fflush(stdin);
        if((**pbase < 3) or (**pbase > 9))
        {
            cout << "A base necessita ser um número ímpar e menor que 50.";
            getchar();
        }
    }
    while((**pbase < 3) or (**pbase > 9));
}

void gera_piramide(int **pbase)
{
    int *total_espaco = new int;
    int *cont_espaco = new int;
    int *qtd = new int;
    int *cont_asterisco = new int;
    int *cont_asteristico = new int;
    int *x = new int;
    int *i = new int;
    *total_espaco = **pbase ;
    *cont_espaco = 1;
    *qtd = 1;
    *cont_asterisco = 1;
    *cont_asteristico = 1;

    for(*x = 0; *x <= ((**pbase)) ; (*x)++)
    {
        *cont_espaco = 1;
        *cont_asterisco = 1;
        *cont_asteristico = 1;
        for(*i = 1; *i <= **pbase; (*i)++)
        {
            if(*cont_espaco <= *total_espaco)
            {
                cout << " ";
                (*cont_espaco)++;
            }
            else if(*cont_asterisco <= *qtd)
            {
                cout << (*cont_asteristico)++;
                (*cont_asterisco)++;
            }
        }
        cout << "\n";
        (*total_espaco)--;
        *qtd = *qtd + 1;
    }
}

