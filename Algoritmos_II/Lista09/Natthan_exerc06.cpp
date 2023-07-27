#include <iostream>
#include <ctime>

using namespace std;

void gerarVal(int **ppx, int **s);
void mostra(int **px, int **s);
float percPar(int **ppx, int **s);
void impar(int **ppx, int **s);
float media(int **ppx, int **s);

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));
    cout << fixed;
    cout.precision(1);

    int *tam = new int(10);
    int *menu = new int;
    int *p = new int[*tam];

    do
    {
        system("cls");
        cout << "####MENU####\n";
        cout << "0 – Sair\n";
        cout << "1 – Gerar valores para o vetor entre 25 e 50\n";
        cout << "2 – Mostrar os valores do vetor, separando cada elemento com uma vírgula\n";
        cout << "3 – Mostrar o percentual de números pares no vetor\n";
        cout << "4 – Mostrar os números ímpares no vetor\n";
        cout << "5 – Mostrar a média dos elementos do vetor com uma casa decimal\n";
        cin >> *menu;
        fflush(stdin);

        switch(*menu)
        {
            case 0:
                system("cls");
                cout << "Programa finalizado!\n";
                break;
            case 1:
                system("cls");
                gerarVal(&p, &tam);
                cout << "Vetor gerado!";
                getchar();
                break;
            case 2:
                system("cls");
                mostra(&p, &tam);
                getchar();
                break;
            case 3:
                system("cls");
                cout << percPar(&p, &tam) << "%";
                getchar();
                break;
            case 4:
                system("cls");
                impar(&p, &tam);
                getchar();
                break;
            case 5:
                system("cls");
                cout << media(&p, &tam);
                getchar();
                break;
            default:
                system("cls");
                cout << "Opção inválida!";
                getchar();
                break;
        }

    } while((*menu) != 0);

    return 0;
}

void gerarVal(int **ppx, int **s)
{
    int *i = new int(0);

    for(*i; *i < **s; (*i)++)
    {
        **ppx = rand()%26+25;
        (*ppx)++;
    }

    *ppx -= (*i);
}

void mostra(int **ppx, int **s)
{
    int *i = new int(0);

    for(*i; *i < **s; (*i)++)
    {
        cout << **ppx << ", ";
        (*ppx)++;
    }

    *ppx -= (*i);
}

float percPar(int **ppx, int **s)
{
    int *par = new int(0);

    int *i = new int(0);

    for(*i; *i < **s; (*i)++)
    {
        if((**ppx)%2 == 0)
            (*par)++;

        (*ppx)++;
    }

    *ppx -= (*i);

    return (((float)*par)*100.00)/((float)**s);
}

void impar(int **ppx, int **s)
{
    int *i = new int(0);

    for(*i; *i < **s; (*i)++)
    {
        if((**ppx)%2 != 0)
        {
             cout << **ppx << ", ";
        }

        (*ppx)++;
    }

    *ppx -= (*i);
}

float media(int **ppx, int **s)
{
    int *i = new int(0);
    int *soma = new int(0);

    for(*i; *i < **s; (*i)++)
    {
        (*soma) += (**ppx);

        (*ppx)++;
    }

    *ppx -= (*i);

    return ((float)*soma)/((float)**s);
}
