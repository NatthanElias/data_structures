#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void obj();
void escreve(char n[]);

int main()
{
    //string nome;
    int menu = -1;

    do
    {
        obj();
        cout << "\n\nDigite 1 Se deseja continuar programa. Outro caracter para sair";
        cin >> menu;
        fflush(stdin);
    }while(menu == 1);

    return 0;
}


void escreve(char n[])
{
    ofstream cid;
    cid.open("cidade.txt", ios::app);
    cid << n << "\n";
    cid.close();
}

void obj()
{
    system("cls");
    char aux[80], n[80];
    int cont = 0;
    ifstream cidade("cidade.txt");
    bool teste = false;

    cout << "Informe o nome da cidade: ";
    gets(n);
    fflush(stdin);

    if(cidade.is_open())
    {
        while(!cidade.eof())
        {
            cidade.getline(aux, 80);
            cont++;
            if(strcasecmp(aux, n)==0)
            {
                teste = true;
                cout << "Existe! Esta na linha " << cont;
                break;
            }
        }
        if(!teste)
        {
            cidade.close();
            cout << "Nao existe! Cidade adicionada";
            escreve(n);
        }
    }
    else
        cout << "Erro ao abrir o arquivo";

    cidade.close();
}
