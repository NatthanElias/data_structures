#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void cadastra();
void mostra();
void consulta();

int main()
{
    setlocale(LC_ALL,"Portuguese");
    cout << fixed;
    cout.precision(2);

    int menu;

    do
    {
        system("cls");
        cout << "####MENU####\n";
        cout << "0 – Sair\n";
        cout << "1 – Cadastrar\n";
        cout << "2 – Mostrar\n";
        cout << "3 – Consultar\n";
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
                cadastra();
                cout << "Nome cadastrado!";
                getchar();
                break;
            case 2:
                system("cls");
                mostra();
                getchar();
                break;
            case 3:
                system("cls");
                consulta();
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

void mostra()
{
    char c;
    ifstream arquivo;
    arquivo.open("cadastro.txt", ios::in);

    if(arquivo.is_open())
    {
        while(arquivo.get(c))
        {
            cout << c;
        }
    }
    else
        cout << "Erro ao abrir o arquivo";

    arquivo.close();
}

void cadastra()
{
    char nome[80];
    ofstream escrita;
    escrita.open("cadastro.txt", ios::app);

    cout << "Informe o nome que deseja cadastrar: ";
    gets(nome);
    fflush(stdin);

    if(escrita.is_open())
    {
        escrita << nome << "\n";
    }
    else
        cout << "Erro ao abrir o arquivo";

    escrita.close();
}

void consulta()
{
    char conteudo[80], nome[80];
    int teste = 0;

    ifstream arquivo;
    arquivo.open("cadastro.txt", ios::in);

    cout << "Informe o nome que deseja consultar: ";
    gets(nome);
    fflush(stdin);

    if(arquivo.is_open())
    {
        while(!arquivo.eof())
        {
            arquivo.getline(conteudo, 80);
            //cout << strcmp(conteudo, nome) <<  endl;
            if(strcmp(conteudo, nome) == 0)
                teste++;
        }
    }
    else
        cout << "Erro ao abrir o arquivo";

    if(teste > 0)
        cout << "\nO nome existe!";
    else
        cout << "\nO nome nao existe!";

    arquivo.close();
}
