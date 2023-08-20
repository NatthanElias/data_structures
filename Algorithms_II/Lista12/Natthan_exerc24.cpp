#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

void leitura(string *str);
void quantosCaracteres(string *str);
void quantasVogais(string *str);
void quantosEspacos(string *str);
void quantosCaracteresEspec(string *str);

int main()
{
    setlocale(LC_ALL, "portuguese");

    int menu = -1;
    string nome;

    leitura(&nome);

    do
    {
        system("cls");
        cout << "####MENU####\n";
        cout << "0 – Sair\n";
        cout << "1 – Número de caracteres existentes no arquivo\n";
        cout << "2 – Número de vogais existentes no arquivo\n";
        cout << "3 – Número de espaços em branco existentes no arquivo\n";
        cout << "4 – Número de caracteres especiais existentes no arquivo\n";
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
                quantosCaracteres(&nome);
                getchar();
                break;
            case 2:
                system("cls");
                quantasVogais(&nome);
                getchar();
                break;
            case 3:
                system("cls");
                quantosEspacos(&nome);
                getchar();
                break;
            case 4:
                system("cls");
                quantosCaracteresEspec(&nome);
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

void leitura(string *str)
{
    cout << "Informe o nome do arquivo(nao esquecer do .txt ao final): ";
    getline(cin, *str);
    fflush(stdin);
}

void quantosCaracteres(string *str)
{
    char c;
    int cont = 0;
    ifstream leitura(*str, ios::in);

    if(leitura.is_open())
    {
        while(leitura.get(c))
        {
            cout << c;

            if(!isspace(c))
                cont++;
        }
    }
    else
        cout << "Erro ao abrir o arquivo";

    cout << "\nQuatidade de caracteres: " << cont;

    leitura.close();
}

void quantasVogais(string *str)
{
    char c;
    int cont = 0;
    ifstream leitura(*str, ios::in);

    if(leitura.is_open())
    {
        while(leitura.get(c))
        {
            cout << c;

            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
                cont++;
        }
    }
    else
        cout << "Erro ao abrir o arquivo";

    cout << "\nQuatidade de vogais: " << cont;

    leitura.close();
}

void quantosEspacos(string *str)
{
    char c;
    int cont = 0;
    ifstream leitura(*str, ios::in);

    if(leitura.is_open())
    {
        while(leitura.get(c))
        {
            cout << c;

            if(isspace(c))
                cont++;
        }
    }
    else
        cout << "Erro ao abrir o arquivo";

    cout << "\nQuatidade de espacos em branco: " << cont;

    leitura.close();
}

void quantosCaracteresEspec(string *str)
{
    char c;
    int cont = 0;
    ifstream leitura(*str, ios::in);

    if(leitura.is_open())
    {
        while(leitura.get(c))
        {
            cout << c;

            if((!isspace(c)) && (!isalnum(c)))
                cont++;
        }
    }
    else
        cout << "Erro ao abrir o arquivo";

    cout << "\nQuatidade de caracteres especiais: " << cont;

    leitura.close();
}
