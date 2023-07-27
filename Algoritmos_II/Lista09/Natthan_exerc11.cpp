#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void geraMat(int **pl, int(**pmat)[5]);
void mostraMat(int **pl, int(**pmat)[5]);
void diagonaisSoma(int **pl, int(**pmat)[5]);
void inverte(int **pl, int(**pmat)[5]);

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    int *lin = new int;
    int (*mat)[5];
    int *menu = new int;
    bool *teste = new bool;
    *teste = false;

    do
    {
        system("cls");
        cout << "####MENU####\n";
        cout << "0 – Sair\n";
        cout << "1 – Gerar matriz\n";
        cout << "2 – Mostrar a matriz\n";
        cout << "3 – Soma das diagonais\n";
        cout << "4 – Mostrar a matriz de forma invertida\n";
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
                geraMat(&lin, &mat);
                *teste = true;
                cout << "Matriz gerada!";
                getchar();
                break;
            case 2:
                system("cls");
                if(*teste)
                    mostraMat(&lin, &mat);
                else
                    cout << "ERRO: A matriz ainda nao foi gerada!";
                getchar();
                break;
            case 3:
                system("cls");
                if(*teste)
                    diagonaisSoma(&lin, &mat);
                else
                    cout << "ERRO: A matriz ainda nao foi gerada!";
                getchar();
                break;
            case 4:
                system("cls");
                if(*teste)
                    inverte(&lin, &mat);
                else
                    cout << "ERRO: A matriz ainda nao foi gerada!";
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

void geraMat(int **pl, int(**pmat)[5])
{
    cout << "Informe o numero de linhas: ";
    cin >> **pl;
    fflush(stdin);

    (*pmat) = new int[**pl][5];

    int *i = new int(0);
    int *j = new int(0);

    for(*i; *i < **pl; (*i)++)
    {
        for(*j; *j < 5; (*j)++)
        {
            (*pmat)[*i][*j] = rand()%100;
            //cout << (*pmat)[*i][*j] << "\t";
        }
        *j -= 5;
    }
    system("cls");
}

void mostraMat(int **pl, int(**pmat)[5])
{
    int *i = new int(0);
    int *j = new int(0);

    cout << "Matriz:\n";
    for(*i; *i < **pl; (*i)++)
    {
        for(*j; *j < 5; (*j)++)
        {
            cout << (*pmat)[*i][*j] << "\t";
        }
        *j -= 5;
        cout << "\n";
    }
}

void diagonaisSoma(int **pl, int(**pmat)[5])
{
    int *i = new int(0);
    int *j = new int(0);
    int *soma = new int(0);

    cout << "Diagonal principal:\n";
    for(*i; *i < **pl; (*i)++)
    {
        for(*j; *j < 5; (*j)++)
        {
            if(*i == *j)
            {
                *soma += (*pmat)[*i][*j];
                cout << (*pmat)[*i][*j] << "\t";
            }
            else
                cout << "-\t";
        }
        *j -= 5;
        cout << "\n";
    }

    cout << "\nSoma diagonal principal: " << *soma;

    *soma = 0;
    *i = 0;
    *j = 0;

    cout << "\n\nDiagonal secundaria:\n";
    for(*i; *i < **pl; (*i)++)
    {
        for(*j; *j < 5; (*j)++)
        {
            if((*i) + (*j) == (**pl) - 1 )
            {
                *soma += (*pmat)[*i][*j];
                cout << (*pmat)[*i][*j] << "\t";
            }
            else
                cout << "-\t";
        }
        *j -= 5;
        cout << "\n";
    }

    cout << "\nSoma diagonal secundaria: " << *soma;
}

void inverte(int **pl, int(**pmat)[5])
{
    int *i = new int((**pl)-1);
    int *j = new int(0);

    cout << "Matriz invertida:\n";
    for(*i; *i >= 0; (*i)--)
    {
        for(*j; *j < 5; (*j)++)
        {
            cout << (*pmat)[*i][*j] << "\t";
        }
        *j -= 5;
        cout << "\n";
    }
}
