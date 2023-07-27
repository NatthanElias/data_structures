#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void mostraDiagPrinc(int mat[][5], int s);
void mostraDiagSec(int mat[][5], int s);
void mostraMat(int mat[][5], int s);

int main()
{
    setlocale(LC_ALL,"Portuguese");
    cout << fixed;
    cout.precision(2);

    const int tam = 5;
    int mat[tam][tam], menu;

    do
    {
        system("cls");
        cout << "####MENU####\n";
        cout << "0 – Sair\n";
        cout << "1 – Mostrar elementos da diagonal principal\n";
        cout << "2 – Mostrar os elementos da diagonal secundária\n";
        cout << "3 – Mostrar a matriz e a soma dos elementos acima e abaixo da diagonal principal\n";
        cin >> menu;
        fflush(stdin);

        switch(menu)
        {
            case 0:
                system("cls");
                cout << "Programa finalizado!";
                getchar();
                break;
            case 1:
                system("cls");
                mostraDiagPrinc(mat, tam);
                getchar();
                break;
            case 2:
                system("cls");
                mostraDiagSec(mat, tam);
                getchar();
                break;
            case 3:
                system("cls");
                mostraMat(mat,tam);
                getchar();
                break;
            default:
              system("cls");
              cout << "Opcao invalida!";
              getchar();
              break;
        }

    } while(menu != 0);

}

void mostraDiagPrinc(int mat[][5], int s)
{
    char conteudo[10];
    int l, c;
    ifstream arquivo;
    arquivo.open("números.txt", ios::in);

    if(arquivo.is_open())
    {
        for(l = 0; l < s; l++)
        {
            for(c = 0; c < s; c++)
            {
                arquivo.getline(conteudo, 10, ';');
                mat[l][c] = atoi(conteudo);
            }
        }
        arquivo.close();

        cout << "Diagonal principal: " << endl;
        for(l = 0; l < s; l++)
        {
            for(c = 0; c < s; c++)
            {
                if(l == c)
                    cout << mat[l][c] << ", ";
            }
        }
    }
    else
        cout << "Erro ao abrir o arquivo";

}

void mostraDiagSec(int mat[][5], int s)
{
    int l, c;
    ifstream arquivo;
    arquivo.open("números.txt", ios::in);

    if(arquivo.is_open())
    {
        cout << "Diagonal secundaria: " << endl;
        for(l = 0; l < s; l++)
        {
            for(c = 0; c < s; c++)
            {
                if(l + c == s-1)
                    cout << mat[l][c] << ", ";
            }
        }
    }
    else
        cout << "Erro ao abrir o arquivo";

    arquivo.close();
}

void mostraMat(int mat[][5], int s)
{
    int l, c, soma1 = 0, soma2 = 0;
    ifstream arquivo;
    arquivo.open("números.txt", ios::in);

    if(arquivo.is_open())
    {
       for(l = 0; l < 5; l++)
        {
            for(c = 0; c < 5; c++)
            {
                cout << mat[l][c] << "\t";
                if(l < c)
                    soma1 += mat[l][c];
                else if(l > c)
                    soma2 += mat[l][c];
            }
            cout << "\n";
        }
    }
    else
        cout << "Erro ao abrir o arquivo";

    cout << "\n\nSoma acima da diagonal principal: " << soma1 << "\nSoma abaixo da diagonal principal: " << soma2;

    arquivo.close();
}
