#include <iostream>
#include <ctime>

using namespace std;

void gerar(int *p, int n);
void mostrarSoma(int *p, int n, int *v);
void mostrarMaiorMenor(int *p, int n);
void existe(int *p, int n);

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    const int tam = 10;
    int vet[tam], *pvet = vet, menu;
    bool teste;

    do
    {
        system("cls");
        cout << "####MENU####\n";
        cout << "0 – Sair\n";
        cout << "1 – Gerar valores\n";
        cout << "2 – Mostrar soma dos valores\n";
        cout << "3 – Mostrar maior e menor valor\n";
        cout << "4 – Verificar se o valor existe no vetor\n";
        cin >> menu;
        fflush(stdin);

        switch(menu)
        {
            case 0:
                system("cls");
                cout << "Programa finalizado!\n";
                break;
            case 1:
                system("cls");
                gerar(pvet, tam);
                cout << "Vetor gerado!";
                teste = true;
                getchar();
                break;
            case 2:
                system("cls");
                if(teste)
                    mostrarSoma(pvet, tam, vet);
                else
                    cout << "ERRO: O vetor ainda nao foi gerado!";
                getchar();
                break;
            case 3:
                system("cls");
                if(teste)
                    mostrarMaiorMenor(pvet, tam);
                else
                    cout << "ERRO: O vetor ainda nao foi gerado!";
                getchar();
                break;
            case 4:
                system("cls");
                if(teste)
                    existe(pvet, tam);
                else
                    cout << "ERRO: O vetor ainda nao foi gerado!";
                getchar();
                break;
            default:
              system("cls");
              cout << "Opcao invalida!";
              getchar();
              break;
        }

    } while(menu != 0);

    return 0;
}

void gerar(int *p, int n)
{
    for(int i = 0; i < n; i++)
    {
        *p = 26 + rand()% 35;
        p++;
    }
}

void mostrarSoma(int *p, int n, int *v)
{
    int s = 0, *ps = &s;

    /*for(int i = 0; i < n; i++)
    {
        cout << *(p++) << ", ";
    }
    cout << "\n";
    p=v;*/

    for(int i = 0; i < n; i++)
        *ps += *(p++);

    cout << "Soma: " << *ps;
}

void mostrarMaiorMenor(int *p, int n)
{
    int maior = 0, menor = *p;
    int *pmaior = &maior, *pmenor = &menor;

    for(int i = 0; i < n; i++)
    {
        if(*p > *pmaior)
            *pmaior = *p;
        else if(*p < *pmenor)
            *pmenor = *p;

        p++;
    }

    cout << "Maior: " << *pmaior << "\nMenor: " << *pmenor;
}

void existe(int *p, int n)
{
    int x, i, *pi = &i;

    cout << "Informe o valor: ";
    cin >> x;
    fflush(stdin);

    for(*pi = 0; *pi <= n; (*pi)++)
    {
        if(x == *(p++))
        {
            cout << "\nExiste. Posicao: " << *pi;
            return;
        }
    }

    cout << "\nO valor informado nao existe no vetor!";
}
