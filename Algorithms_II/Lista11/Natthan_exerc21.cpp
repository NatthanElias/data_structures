#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>

using namespace std;

void gera(int M[8][8]);
void escreve(int M[8][8]);
void mostra(int M[8][8]);

int main()
{
    setlocale(LC_ALL,"Portuguese");
    cout << fixed;
    cout.precision(2);
    srand(time(NULL));

    int i, mat[8][8], menu = -1;
    bool teste = false;

    do
    {
        system("cls");
        cout << "####MENU####\n";
        cout << "0 – Sair\n";
        cout << "1 – Gerar matriz\n";
        cout << "2 – Escrever valores\n";
        cout << "3 – Mostrar matriz\n";
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
                gera(mat);
                cout << "Numeros gerados!";
                teste = true;
                getchar();
                break;
            case 2:
                system("cls");
                if(!teste)
                    cout << "Gere a matriz primeiro!";
                else
                    escreve(mat);
                getchar();
                break;
            case 3:
                system("cls");
                if(!teste)
                    cout << "Gere a matriz primeiro!";
                else
                    mostra(mat);
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

void gera(int M[][8])
{
        for(int l = 0; l < 8; l++){
            for(int c = 0; c < 8; c++){
                M[l][c] = rand() % 100;
            }
        }
}

void escreve(int M[][8])
{
    ofstream objeto("matriz.txt");
    if(objeto.is_open()){
        for(int l = 0; l < 8; l++){
            objeto << M[l][0];
            for(int c = 1; c < 8; c++)
                objeto << " " << M[l][c];
            objeto << ", ";
        }
        objeto.close();
    }
    else{
        cout << "Falha ao abrir o arquivo!";
    }
}

void mostra(int M[][8])
{
    cout << "Matriz: " << endl;
    for(int l = 0; l < 8; l++) {
        for(int c = 0; c < 8; c++) {
            int v = M[l][c];
            cout << v << "\t";
        } cout << "\n";
    }
}

