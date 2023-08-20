#include <iostream>
#include <cstring>
#include <regex>

using namespace std;

void inverte(string s);

int main()
{
    setlocale(LC_ALL, "portuguese");

    string str;
    regex validacao("^[a-zA-Z ]+$");
    bool teste;

    do
    {
        cout << "Informe um texto qualquer: ";
        getline(cin, str);
        fflush(stdin);
        system("cls");

        teste = regex_match(str, validacao);

        if(teste == false)
            cout << "ERRO: Entrada inválida!\n\n";

    }while(teste == false);


    cout << "Texto digitado: " << str << "\n";
    cout << "Texto invertido: ";
    inverte(str);
    cout << "\n";

    return 0;
}

void inverte(string s)
{
    if(s.size() == 0)
        return;
    inverte(s.substr(1));
    cout << s[0];
}

