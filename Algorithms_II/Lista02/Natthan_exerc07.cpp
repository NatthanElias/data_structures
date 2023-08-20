#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");

    string texto, aux;
    char x;

    cout << "Digite um texto qualquer: ";
    getline(cin, texto);
    fflush(stdin);

    cout << "Digite um caracter presente no texto: ";
    cin >> x;
    fflush(stdin);

    cout << "\nTexto conforme lido: ";
    for(int i=0; i < texto.size(); i++)
        cout << texto[i];

    for(int i=0; i < texto.size(); i++)
    {
        if(texto[i] != x)
            aux += texto[i];
    }

    cout << "\nTexto sem o caracter: ";
    for(int i=0; i < aux.size(); i++)
        cout << aux[i];

    return EXIT_SUCCESS;
}

