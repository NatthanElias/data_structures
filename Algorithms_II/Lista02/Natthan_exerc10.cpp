#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");

    string passw, pw, err = "ç`´^~";
    int cont = 0, test;

    do
    {
        cout << "Informe a palavra chave(nao pode ser a palavra 'Fim', nem conter acento ou cedilha): "; // nao consigo comparar o ç e acentos, pois viram outros caracteres quando estocados na string.
        getline(cin, pw);
        fflush(stdin);

        for(int i = 0; i < pw.size(); i++)
            pw[i] = tolower(pw[i]);

        system("cls");
    }while(pw == "fim");

    /*do
    {
    test = 0;

    for(int i = 0; i < pw.size(); i++)
    {
        for(int j = 0; j < err.size(); j++)
        {
            if(pw[i] == err[j])
            {
                test++;
            }
        }
    }
    }while(test > 0)*/

    do
    {
        cout << "Insira a palavra chave salva: ";
        getline(cin, passw);
        fflush(stdin);
        cont++;

        for(int i = 0; i < passw.size(); i++)
            passw[i] = tolower(passw[i]);

        if(passw == pw)
        {
            cout << "\nVocê acertou!" << endl;
            cout << "Total de tentativas: " << cont << endl;
            return 1;
        }
        else if(passw != "fim")
            cout << "\nErrou! Tente novamente ou encerre o programa digitando o comando: 'Fim'\n" << endl;

    } while(passw != "fim");


    return EXIT_SUCCESS;
}
