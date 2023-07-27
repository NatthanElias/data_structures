#include <iostream>
#include <cstring>
#include<cstdlib>
#include<cstdio>

using namespace std;

struct Prato
{
    string ingredientes;
    string preparo;
    int calorias;
};

struct Cardapio
{
    int codigo;
    string nome;
    Prato x;
    float valor;
};

void incluir(Cardapio v[], int &i);
void mostra(Cardapio v[], int ind);
void detalhar(Cardapio v[], int ind);
void mostraCaro(Cardapio v[], int ind);
void mostraMenorCal(Cardapio v[], int ind);

int main()
{
    setlocale(LC_ALL, "portuguese");

    int menu = -1, indice = -1;
    Cardapio vet[20];

    do
    {
        system("cls");
        cout << "#############Menu#############\n";
        cout << "0 - Sair\n";
        cout << "1 – Incluir item\n";
        cout << "2 – Mostrar cardápio\n";
        cout << "3 – Detalhar cardápio\n";
        cout << "4 – Mostrar cardápio mais caro\n";
        cout << "5 – Mostrar cardápio com a menor quantidade de calorias\n";
        cin >> menu;
        fflush(stdin);

        switch(menu)
        {
            case 1:
                system("cls");
                incluir(vet, indice);
                cout << "Prato cadastrado com sucesso!\nPressione Enter para prosseguir";
                getchar();
                break;
            case 2:
                system("cls");
                if(indice < 0)
                    cout << "Nenhum item novo foi cadastrado!";
                else
                    mostra(vet, indice);
                getchar();
                break;
            case 3:
                system("cls");
                if(indice < 0)
                    cout << "Nenhum item novo foi cadastrado!";
                else
                    detalhar(vet, indice);
                getchar();
                break;
            case 4:
                system("cls");
                if(indice < 0)
                    cout << "Nenhum item novo foi cadastrado!";
                else
                    mostraCaro(vet, indice);
                getchar();
                break;
            case 5:
                system("cls");
                if(indice < 0)
                    cout << "Nenhum item novo foi cadastrado!";
                else
                    mostraMenorCal(vet, indice);
                getchar();
                break;
            case 0:
                break;
            default:
                system("cls");
                cout << "ERRO: Opcao invalida!";
                getchar();
        }
    } while(menu != 0);

    return 0;
}

void incluir(Cardapio v[], int &i)
{
    i++;

    cout << "Informe o codigo do novo item do cardapio: ";
    cin >> v[i].codigo;
    fflush(stdin);

    cout << "Informe o nome do novo item do cardapio: ";
    getline(cin, v[i].nome);
    fflush(stdin);

    cout << "Informe os ingredientes do novo prato (sem quebra de linha e separados por virgula): ";
    cin >> v[i].x.ingredientes;
    fflush(stdin);

    cout << "Informe o modo de preparo do novo prato (sem quebra de linha): ";
    cin >> v[i].x.preparo;
    fflush(stdin);

    cout << "Informe as calorias do novo prato: ";
    cin >> v[i].x.calorias;
    fflush(stdin);

    cout << "Informe o valor do novo item do cardapio: ";
    cin >> v[i].valor;
    fflush(stdin);
}

void mostra(Cardapio v[], int ind)
{
    cout << "CARDAPIO: " << "\n\n";

    for(int i = 0; i <= ind; i++)
    {
        cout << "Código: " << v[i].codigo << "\n";
        cout << "Nome: " << v[i].nome << "\n";
        cout << "Ingredientes: " << v[i].x.ingredientes << "\n";
        cout << "Preparo: " << v[i].x.preparo << "\n";
        cout << "Calorias: " << v[i].x.calorias << "\n";
        cout << "Valor: " << v[i].valor << "\n";
        cout << "--------------------------------" << "\n";
    }
}

void detalhar(Cardapio v[], int ind)
{
    int c, y = -1;

    cout << "Informe o codigo do item: ";
    cin >> c;
    fflush(stdin);

    for(int i = 0; i <= ind; i++)
    {
        if(v[i].codigo == c)
            y = i;
    }

    if(y != -1)
    {
        cout << "\n" << "--------------------------------" << "\n";
        cout << "Código: " << v[y].codigo << "\n";
        cout << "Nome: " << v[y].nome << "\n";
        cout << "Ingredientes: " << v[y].x.ingredientes << "\n";
        cout << "Preparo: " << v[y].x.preparo << "\n";
        cout << "Calorias: " << v[y].x.calorias << "\n";
        cout << "Valor: " << v[y].valor << "\n";
        cout << "--------------------------------" << "\n";
    }
    else
        cout << "ERRO: O codigo informado é inválido!";
}

void mostraCaro(Cardapio v[], int ind)
{
    int m = 0;
    for(int i = 1; i <= ind; i++)
    {
        if(v[i].valor > v[m].valor)
            m = i;
    }

    cout << "Item mais caro do cardapio: " << "\n";
    cout << "\n" << "--------------------------------" << "\n";
    cout << "Código: " << v[m].codigo << "\n";
    cout << "Nome: " << v[m].nome << "\n";
    cout << "Ingredientes: " << v[m].x.ingredientes << "\n";
    cout << "Preparo: " << v[m].x.preparo << "\n";
    cout << "Calorias: " << v[m].x.calorias << "\n";
    cout << "Valor: " << v[m].valor << "\n";
    cout << "--------------------------------" << "\n";
}

void mostraMenorCal(Cardapio v[], int ind)
{
    int m = 0;
    for(int i = 1; i <= ind; i++)
    {
        if(v[i].x.calorias < v[m].x.calorias)
            m = i;
    }

    cout << "Item com a menor quantidade de calorias do cardapio: " << "\n";
    cout << "\n" << "--------------------------------" << "\n";
    cout << "Código: " << v[m].codigo << "\n";
    cout << "Nome: " << v[m].nome << "\n";
    cout << "Ingredientes: " << v[m].x.ingredientes << "\n";
    cout << "Preparo: " << v[m].x.preparo << "\n";
    cout << "Calorias: " << v[m].x.calorias << "\n";
    cout << "Valor: " << v[m].valor << "\n";
    cout << "--------------------------------" << "\n";
}
