#include <iostream>
#include <ctime>

using namespace std;

bool existe(int *v, int i, int *pv);
void geraAleatorios(int *v, int s, int vet[]);
void mostra(int *v, int s);
void MediaMaiorMenor(int *p, int s);
void percentual(int *v, int s);

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));
    cout << fixed;
    cout.precision(2);

    const int tam = 50;
    int vet[tam], *pvet = vet, menu;
    bool teste;

    do
    {
        system("cls");
        cout << "####MENU####\n";
        cout << "0 – Sair\n";
        cout << "1 – Gerar valores\n";
        cout << "2 – Mostrar vetor\n";
        cout << "3 – Média, maior e menor\n";
        cout << "4 – Percentual\n";
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
                geraAleatorios(pvet, tam, vet);
                cout << "Vetor gerado!";
                teste = true;
                getchar();
                break;
            case 2:
                system("cls");
                if(teste)
                    mostra(&vet[0], tam);
                else
                    cout << "ERRO: O vetor ainda nao foi gerado!";
                getchar();
                break;
            case 3:
                system("cls");
                if(teste)
                     MediaMaiorMenor(pvet, tam);
                else
                    cout << "ERRO: O vetor ainda nao foi gerado!";
                getchar();
                break;
            case 4:
                system("cls");
                if(teste)
                    percentual(&vet[0], tam);
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

bool existe(int *v, int i, int *pv)
{
    for (int j = 0; j < i; j++)
    {
        if(*v == *(pv++))
            return true;
    }
    return false;
}

void geraAleatorios(int *v, int s, int vet[])
{
    int i;
    for(i = 0; i<s ; i++)
    {
        *v = rand()%100;
        while(existe(v, i, &vet[0]))
        {
            *v = rand()%100;
        }
        v++;
    }

    /*for(int i = 0; i < s; i++)
        cout << vet[i] << ", ";*/
}

void mostra(int *v, int s)
{
    int m[5][10];

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            m[i][j] = *(v++);
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }

}

void MediaMaiorMenor(int *p, int s)
{
    int maior = 0, menor = *p;
    float soma = 0;
    int *pmaior = &maior, *pmenor = &menor;
    float *psoma = &soma;

    for(int i = 0; i < s; i++)
    {
        if(*p > *pmaior)
            *pmaior = *p;
        else if(*p < *pmenor)
            *pmenor = *p;

        *psoma += *p;
        p++;
    }

    cout << "Maior: " << maior << "\nMenor: " << menor << "\nMedia: " << *psoma/s;
}

void percentual(int *v, int s)
{
    int impar = 0, par = 0, *pimp = &impar, *ppar = &par;

    for(int i = 0; i < s; i++)
    {
        if(*(v++)%2 == 0)
            *ppar += 1;
        else
            *pimp += 1;
    }

    cout << "Par: " << ((*ppar)*100)/s << "%\nImpar: " << ((*pimp)*100)/s << "%";
}
