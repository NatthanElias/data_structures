#include <iostream>
#include <ctime>

using namespace std;

void geraVet(int **v);
void mostraVet(int *v);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int menu = 0;
    int *vet = NULL;

    do
    {
    cout << "1 - Gerar vetor\n";
    cout << "2 - Mostrar vetor\n";
    cout << "0 - Sair\n";
    cin >> menu;
    fflush(stdin);
    system("cls");

    switch(menu)
    {
        case 1:
            geraVet(&vet);
            cout << "Vetor gerado.";
            getchar();
            system("cls");
            break;
        case 2:
            mostraVet(vet);
            getchar();
            system("cls");
            break;
    }
    }while (menu!=0);
    return 0;
}

void geraVet(int **v)
{
    if(*v != NULL)
        delete *v;

    *v = new int[10];

    for(int i = 0; i < 10; i++)
        *(*v + i) = rand()%31+20;
        //(*v)[i] = rand()%31+20;
}

void mostraVet(int *v)
{
    if(v == NULL)
    {
        cout << "ERRO: Vetor nulo";
        return;
    }

    for(int i = 0; i < 10; i++)
        cout << v[i] << ", ";
        //v++;
}
