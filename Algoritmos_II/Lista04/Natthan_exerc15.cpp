#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void geraAleatorios(int vet[], int quantvet);
bool existe(int valores[], int tam, int valor);
void geraMatriz(int v[], int m[][5]);
void diagonal(int m[][5]);
void diagonalSec(int m[][5]);
void maior(int m[][5]);

int main()
{
    setlocale(LC_ALL, "portuguese");

    const int tam = 25;
    int vet[tam], mat[5][5], quit, id;

    do
    {
        cout << "#####Menu#####\n";
        cout << "1- Gerar valores para preencher a matriz\n";
        cout << "2- Mostrar a matriz na tela\n";
        cout << "3- Mostrar os elementos da diagonal principal da matriz\n";
        cout << "4– Mostrar os elementos da diagonal secundária da matriz\n";
        cout << "5– Encontrar o maior elemento da matriz e exibir sua posição (linha, coluna) onde se encontra\n";
        cin >> id;
        fflush(stdin);
        system("cls");

        switch(id)
        {
            case 1:
                geraAleatorios(vet, tam);
                break;
            case 2:
                geraMatriz(vet, mat);
                break;
            case 3:
                diagonal(mat);
                break;
            case 4:
                diagonalSec(mat);
                break;
            case 5:
                maior(mat);
                break;
            default:
                cout << "ERRO: Opção inválida!";
        }

        if(id == 1)
            cout << "STATUS: Matriz criada, volte ao menu e digite 2 para mostrar\n";

        cout << "\n1- Continuar\n2- Encerrar programa\n";
        cin>> quit;
        fflush(stdin);
        system("cls");
    }while(quit != 2);

    return EXIT_SUCCESS;
}

bool existe(int valores[], int tam, int valor)
{
    for (int i = 0; i <tam; i++)
    {
        if(valores[i] == valor)
            return true;
    }
    return false;
}

void geraAleatorios(int vet[], int quantvet)
{
    srand(time(NULL));

    int v;
    for(int i = 0; i<quantvet; i++)
    {
        v = rand()%100;
        while(existe(vet,i,v))
        {
            v = rand()%100;
        }
        vet[i] = v;
    }
}

void geraMatriz(int v[], int m[][5])
{
    int k = 0;

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            m[i][j] = v[k];
            cout << m[i][j] << "\t";
            k++;
        }
        cout << endl;
    }
}

void diagonal(int m[][5])
{
    int v[5];

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(i == j)
            {
                v[i] = m[i][j];
            }
        }
    }

    cout << "\nDiagonal principal: ";
    for(int n : v)
        cout << n << ", ";
}

void diagonalSec(int m[][5])
{
     int v[5];

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(i + j == 5-1)
            {
                v[i] = m[i][j];
            }
        }
    }

    cout << "\n\nDiagonal secundária: ";
    for(int n : v)
        cout << n << ", ";
}

void maior(int m[][5])
{
    int b = 0, l , c;

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(m[i][j] > b)
            {
                b = m[i][j];
                l = i + 1;
                c = j + 1;
            }
        }
    }

    cout << "\n\nO maior elemento é: " << b << ", Linha " << l << ", Coluna " << c << endl;
}
