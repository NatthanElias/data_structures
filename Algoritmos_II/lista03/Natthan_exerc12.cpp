#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

#define TAM 10

void criaVet(int vet[]);
void mostra(int vet[]);
void ordena(int vet[]);
float mediaVet(int vet[]);

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    cout << fixed;
    cout.precision(2);

    int vet[TAM], id, quit = 1;

    do
    {
        cout.width(30);
        cout << "######MENU######\n";
        cout << "1- Criar um vetor com números aleatórios entre 25 e 75\n";
        cout << "2- Mostrar o vetor criado na tela\n";
        cout << "3- Ordenar os elementos do vetor em ordem decrescente\n";
        cout << "4- Calcular a média dos elementos do vetor\n";
        cin >> id;
        fflush(stdin);
        system("cls");

        switch(id)
        {
        case 1:
            criaVet(vet);
            break;
        case 2:
            mostra(vet);
            break;
        case 3:
            ordena(vet);
            break;
        case 4:
            cout << "A média dos elementos do vetor é: " << mediaVet(vet) << "\n\n";
            break;
        default:
            cout << "ERRO - Informe uma opção valida entre 1 e 4!\n\n";
            break;
        }

        if(id == 2 || id == 4){
            cout << "1- Selecionar outra opção \n2- Sair do programa\n";
            cin >> quit;
            fflush(stdin);
            system("cls");
        }
        else if(id == 1)
            cout << "STATUS: Vetor criado, digite 2 Para mostrar na tela\n\n";
        else if(id == 3)
            cout << "STATUS: Vetor ordenado, digite 2 Para mostrar na tela\n\n";

    } while(quit == 1);


    return EXIT_SUCCESS;
}

void criaVet(int vet[])
{
    for(int i=0; i<TAM; i++)
        vet[i] = rand()%51+25;
}

void mostra(int vet[])
{
    cout << "Vetor: ";
    for(int i=0; i<TAM; i++)
        cout << vet[i] << ", ";
    cout << "\n\n";
}

void ordena(int vet[])
{
    int aux = 0;

    for(int i=0; i<TAM; i++)
    {
        for(int j=0; j<TAM-1; j++)
        {
            if(vet[j] < vet[i])
            {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

float mediaVet(int vet[])
{
    int soma = 0;
    float media = 0;

    for(int i=0; i<TAM; i++)
        soma += vet[i];

    media = soma / 10.00;

    return media;
}
