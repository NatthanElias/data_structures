#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

bool existe(vector<int> **valores, int tam, int valor);
void geraAleatorios(vector<int> *vet, int quantvet);
void mostra(vector<int> vet);
void escreve(vector<int> vet);
void exclui(vector<int> *vet);

int main()
{
    setlocale(LC_ALL, "portuguese");
    int tam, menu = -1;

    cout << "Informe o tamanho do vetor: ";
    cin >> tam;
    fflush(stdin);

    vector<int> vet;
    vet.reserve(tam);

    /*vet.push_back(2);
    vet.push_back(22);
    vet.push_back(33);
    vet.push_back(44);*/


    do
    {
        system("cls");
        cout << "####MENU####\n";
        cout << "0 – Sair\n";
        cout << "1 – Gerar aleatorios\n";
        cout << "2 – Mostrar\n";
        cout << "3 – Ordenar e escrever vetor\n";
        cout << "4 – Excluir valores no vetor\n";
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
                geraAleatorios(&vet, tam);
                cout << "Valores gerados";
                getchar();
                break;
            case 2:
                system("cls");
                mostra(vet);
                getchar();
                break;
            case 3:
                system("cls");
                escreve(vet);
                cout << "Vetor escrito no documento!";
                getchar();
                break;
            case 4:
                system("cls");
                exclui(&vet);
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

bool existe(vector<int> **valores, int tam, int valor)
{
    for (int i = 0; i <tam; i++)
    {
        //cout << valores[i] << ", ";
        if((**valores)[i] == valor)
            return true;
    }
    return false;
}

void geraAleatorios(vector<int> *vet, int quantvet)
{
    srand(time(NULL));

    int v;
    for(int i = 0; i<quantvet; i++)
    {
        v = rand()%500;
        vet->push_back(v);
        //cout << vet[i] << ", ";
        while(existe(&vet,i,v))
        {
            vet->pop_back();
            v = rand()%500;
            vet->push_back(v);
        }
        //cout << (*vet)[i] << ", ";
    }
}

void mostra(vector<int> vet)
{
    for(int i = 0; i<vet.size(); i++)
        cout << vet[i] << ", ";
}

void escreve(vector<int> vet)
{
    //int aux[quantvet];

    ofstream escrever("valores.txt");

    if(escrever.is_open())
    {
        sort(vet.begin(), vet.end());

        for(int i = 0; i<vet.size(); i++)
            escrever << vet[i] << ",";

    }
    else
        cout << "Erro ao abrir o arquivo";

    escrever.close();
}

void exclui(vector<int> *vet)
{
    int n;

    cout << "Informe o valor que deseja excluir: ";
    cin >> n;
    fflush(stdin);

    auto it = find(vet->begin(), vet->end(), n);

    if (it != vet->end())
    {
        ofstream escrever("valores.txt");

        vet->erase(it);

        sort(vet->begin(), vet->end());

        for(int i = 0; i<vet->size(); i++)
            escrever << (*vet)[i] << ",";

        escrever.close();

        cout << "\nElemento excluido com sucesso!";
    }
    else
        cout << "\nElemento nao pertence ao vetor";
}
