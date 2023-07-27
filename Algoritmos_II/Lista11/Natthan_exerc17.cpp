#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void leitura();

int main()
{
    setlocale(LC_ALL,"Portuguese");
    cout << fixed;
    cout.precision(2);

    leitura();

    cin.get();
}

void leitura()
{
    char conteudo[10];
    ifstream arquivo;
    arquivo.open("exerc17.txt", ios::in);
    float soma = 0.00, cont = 0.00, maior = 0.00, menor = INT_MAX;

    if(arquivo.is_open())
    {
        while(!arquivo.eof())
        {
            arquivo.getline(conteudo, 10, ';');
            soma += atof(conteudo);
            //cout << conteudo << endl;
            cout << atof(conteudo) << endl;
            cont++;
            if(atof(conteudo) > maior)
                maior = atof(conteudo);
            else if(atof(conteudo) < menor)
                menor = atof(conteudo);
        }
    }
    else
        cout << "Erro ao abrir o arquivo";

        cout << "Soma: " << soma << "\nMedia: " << soma/cont << "\nMaior: " << maior << "\nMenor: " << menor << "\n";

    arquivo.close();
}

