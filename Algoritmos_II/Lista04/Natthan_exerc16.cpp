#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void geraAleatorios(int vet[], int quantvet);
bool existe(int valores[], int tam, int valor);
void geraMatriz(int v[], int m[][7]);
void trocaMaior(int m[][7]);
int simetrica(int m[][7]);
void acimaEAbaixoDiag(int m[][7]);

int main()
{
    setlocale(LC_ALL, "portuguese");

    const int tam = 49;
    int id, quit, vet[tam], mat[7][7];

    do
    {

        cout << "#####Menu#####\n";
        cout << "1- Gerar valores para preencher a matriz\n";
        cout << "2- Mostrar a matriz na tela\n";
        cout << "3- Encontrar o maior elemento de cada linha e trocar de lugar com o elemento presente na diagonal principal da linha\n";
        cout << "4– Verificar se é uma matriz simétrica\n";
        cout << "5– Mostrar os elementos acima e abaixo da diagonal principal\n";
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
                cout << "Matriz Original:\n";
                geraMatriz(vet, mat);
                cout << "\nMatriz Modificada:\n";
                trocaMaior(mat);
                break;
            case 4:
                if(simetrica(mat) == 0)
                    cout << "A matriz não é simétrica!\n";
                else
                    cout << "A matriz é simétrica!\n";
                break;
            case 5:
                acimaEAbaixoDiag(mat);
                break;
            default:
                cout << "ERRO: Opção inválida!";
                break;
        }

        if(id == 1)
            cout << "STATUS: Matriz criada\n";

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

void geraMatriz(int v[], int m[][7])
{
    int k = 0;

    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            m[i][j] = v[k];
            cout << m[i][j] << "\t";
            k++;
        }
        cout << endl;
    }
}

void trocaMaior(int m[][7])
{
    int maior, aux, posI, posJ;

    for(int i = 0; i < 7; i++)
    {
        maior= 0;
        for(int j = 0; j < 7; j++)
        {
            if(m[i][j] > maior)
            {
                maior = m[i][j];
                posI = i;
                posJ = j;
            }
        }

        for(int j = 0; j < 7; j++)
        {
            if(i == j)
            {
                aux = m[i][j];
                m[i][j] = maior;
                m[posI][posJ] = aux;
            }
        }

    }

    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}

int simetrica(int m[][7])
{
     for(int i = 0; i < 7; i++)
    {
        for(int j = i+1; j < 7; j++)
        {
            if(m[i][j] != m[j][i])
                return 0;
        }
    }
    return 1;
}

void acimaEAbaixoDiag(int m[][7])
{
    cout << "Acima da diagonal:\n";
    for(int i=0; i < 7; i++)
    {
        for(int j=0; j < 7; j++)
        {
            if(i < j)
                cout << m[i][j] << "\t";
            else
                cout << "-\t";
        }
        cout <<endl;

    }
    cout << endl;

    cout << "\nAbaixo da diagonal:\n";
    for(int i=0; i < 7; i++)
    {
        for(int j=0; j < 7; j++)
        {
            if(i > j)
                cout << m[i][j] << "\t";
            else
                cout << "-\t";
        }
        cout <<endl;

    }
}
