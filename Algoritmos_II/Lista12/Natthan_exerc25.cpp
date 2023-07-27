#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cstring>

using namespace std;

void carregaDados(vector<string> *vec);
void inclui(vector<string> *vec);
void mostra();
void consultaNome(vector<string> *vec);
void consultaNum(vector<string> *vec);
void exclui(vector<string> *vec);

int main()
{
    setlocale(LC_ALL, "portuguese");

    int menu = -1;
    vector<string> vec;

    carregaDados(&vec);
    do
    {
        system("cls");
        cout << "####MENU####\n";
        cout << "0 – Sair\n";
        cout << "1 – Incluir\n";
        cout << "2 – Mostrar todos\n";
        cout << "3 – Consultar pelo nome\n";
        cout << "4 – Consultar pelo número\n";
        cout << "5 – Excluir cadastro\n";
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
                inclui(&vec);
                getchar();
                break;
            case 2:
                system("cls");
                mostra();
                getchar();
                break;
            case 3:
                system("cls");
                consultaNome(&vec);
                getchar();
                break;
            case 4:
                system("cls");
                consultaNum(&vec);
                getchar();
                break;
            case 5:
                system("cls");
                exclui(&vec);
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

void carregaDados(vector<string> *vec)
{
    vec->clear();

    char aux[200];
    string aux2 = "", aux3 = "";
    ifstream ler;
    ler.open("agenda.txt", ios::in);

    //int cont = 0;
    if(ler.is_open())
    {
        while(ler.getline(aux, 200))
        {
            for(int i = 0; i < strlen(aux); i++)
            {
                if(isalpha(aux[i]) || isspace(aux[i]))
                    aux2 += aux[i];
                else if(isdigit(aux[i]))
                    aux3 += aux[i];
            }
            vec->push_back(aux2);
            vec->push_back(aux3);
            aux2 = "";
            aux3 = "";
        }
    }
    else
        cout << "Erro ao abrir o arquivo";

    ler.close();
}

void inclui(vector<string> *vec)
{
    string nome, numero;

    ofstream escreve("agenda.txt", ios::app);

    cout << "Informe o nome: ";
    getline(cin, nome);
    fflush(stdin);

    cout << "Informe o numero de telefone: ";
    getline(cin, numero);
    fflush(stdin);

    vec->push_back(nome);
    vec->push_back(numero);

    if(escreve.is_open())
    {
        escreve << ";\n" << nome << ";" << numero;
    }
    else
        cout << "Erro ao abrir o arquivo";

    escreve.close();
}

void mostra()
{
    char c;

    ifstream leitura("agenda.txt", ios::in);

    if(leitura.is_open())
    {
        while(leitura.get(c))
        {
            cout << c;
        }
    }
    else
        cout << "Erro ao abrir o arquivo";

    leitura.close();
}

void consultaNome(vector<string> *vec)
{
    string nome;
    bool teste = false;

    cout << "Informe o nome completo: ";
    getline(cin, nome);
    fflush(stdin);

    //cout << "\n\n" << (*vec).size();
    for(int i = 0; i < (*vec).size(); i++)
    {
        if((*vec)[i] == nome)
        {
            teste = true;
            cout << (*vec).at(i) << ";" << (*vec).at(i+1);
        }
        //cout << vec->at(i) << ", ";
    }

    if(!teste)
        cout << "Nome nao encontrado!";
}

void consultaNum(vector<string> *vec)
{
    string numero;
    bool teste = false;

    cout << "Informe o numero completo: ";
    getline(cin, numero);
    fflush(stdin);

    for(int i = 0; i < (*vec).size(); i++)
    {
        if((*vec)[i] == numero)
        {
            teste = true;
            cout << (*vec).at(i-1) << ";" << (*vec).at(i);
        }
    }

    if(!teste)
        cout << "Numero nao encontrado!";
}

void exclui(vector<string> *vec)
{
    string nome;
    vector<string> aux;
    bool teste = false;

    cout << "Informe o nome do cadastro que deseja excluir: ";
    getline(cin, nome);

    ofstream escrever("agenda.txt", ios::out);


    for(int i = 0; i < (*vec).size(); i++)
    {
        if(vec->at(i) == nome)
        {
            teste = true;
            if(i == (*vec).size()-2)
                break;

            i+=2;
        }

        aux.push_back(vec->at(i));
    }

    vec->clear();

    for(int i = 0; i < aux.size(); i++)
        vec->push_back(aux[i]);

    if(escrever.is_open())
    {
        for(int i = 0; i < (*vec).size(); i++)
        {
            if(i == 0)
                escrever << (*vec).at(i);
            else if(i%2==0)
                escrever << ";\n" << (*vec).at(i);
            else
                escrever << ";" << (*vec).at(i);
        }
    }
    else
        cout << "Erro ao abrir o arquivo";

    escrever.close();

    if(!teste)
        cout << "\nNome nao encontrado!";
    else
        cout << "\nCadastro excluido com sucesso!";

}
