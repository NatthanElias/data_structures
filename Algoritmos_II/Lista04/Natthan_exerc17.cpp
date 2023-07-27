#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void geraMatriz(int m[][5]);
void mostraETransp(int m[][5]);
void maiorMenorMedia(int m[][5]);

int main()
{
    setlocale(LC_ALL, "portuguese");

    cout << fixed;
    cout.precision(2);

    int mat[3][5], id, quit;

    do
    {
        cout << "#####Menu#####\n";
        cout << "1- Gerar valores para preencher a matriz\n";
        cout << "2- Mostrar a matriz gerada e sua respectiva matriz transposta\n";
        cout << "3- Calcular e mostrar o maior, o menor e a média dos elementos existentes na matriz\n";
        cin >> id;
        fflush(stdin);
        system("cls");

        switch(id)
        {
            case 1:
                geraMatriz(mat);
                break;
            case 2:
                mostraETransp(mat);
                break;
            case 3:
                maiorMenorMedia(mat);
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

    return 0;
}

void geraMatriz(int m[][5])
{
    srand(time(NULL));
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            redo:
            m[i][j] = rand()%50;
            if(m[i][j]%2!=0)
                goto redo;
        }
    }
}

void mostraETransp(int m[][5])
{
    cout << "Matriz gerada:\n";
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 5; j++)
            cout << m[i][j] << "\t";
        cout << endl;
    }

    cout << "\n\nMatriz transposta:\n";
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 3; j++)
            cout << m[j][i] << "\t";
        cout << endl;
    }
}

void maiorMenorMedia(int m[][5])
{
    int maior = 0;
    float soma = 0.00;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 5; j++)
            if(m[i][j] > maior)
                maior = m[i][j];
    }

    int menor = maior;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 5; j++)
            if(m[i][j] < menor)
                menor = m[i][j];
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 5; j++)
            soma += m[i][j];
    }

    cout << "\n\nO maior elemento é: " << maior << ", o menor elemento é: " << menor << ", a média é: " << soma/15.00 << endl;
}
