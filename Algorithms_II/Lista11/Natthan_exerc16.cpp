#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void nomeia(string *str);
void leitura(string *str);

int main()
{
    setlocale(LC_ALL,"Portuguese");

    string nome;

    nomeia(&nome);
    leitura(&nome);

    cin.get();
}

void nomeia(string *str)
{
    cout << "Informe o nome do arquivo(nao esquecer do .txt ao final): ";
    getline(cin, *str);
}

void leitura(string *str)
{
    char c;
    ifstream arqv;
    int cont = 0;
    arqv.open(*str, ios::in);

    if(arqv.is_open())
    {
         while(arqv.get(c))
        {
            cout << c;

            if(!isspace(c))
                cont++;
        }
    }
    else
        cout << "Erro ao abrir o arquivo";

    cout << "\nQuatidade de caracteres: " << cont;

    arqv.close();
}
